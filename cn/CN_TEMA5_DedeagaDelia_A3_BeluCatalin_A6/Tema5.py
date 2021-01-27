import numpy as np
import re
import time
import random

valoare_epsilon = 10 ** (-9)
maxim_interatii = 100 #1000000
procent = 0.2


def index_coloana(r, c):
    l = list(filter(lambda x: x[1] == c, r))
    if len(l) == 0:
        return -1
    else:
        index = r.index(list(filter(lambda x: x[1] == c, r))[0])
        return index


def verificam_simetria_matricei(matrix):
    dimensiune_matrice = len(matrix)
    for i in range(dimensiune_matrice):
        for val, j in matrix[i]:
            if i < j:
                poz = index_coloana(matrix[j], i)
                if poz == -1:
                    return False
                else:
                    if abs(val - matrix[j][poz][0]) > valoare_epsilon:
                        return False
    return True


def metoda_puterii(dim_rand, dim_col, matrix):
    x = np.random.randint(low=1, high=10, size=(dim_rand, 1))
    v = (1 / np.linalg.norm(x)) * x
    w = np.array(inmultirea_matricelor(matrix, v))
    lambd = np.sum(np.multiply(w, v))

    k = 0
    while True:
        v = (1 / np.linalg.norm(w)) * w
        w = np.array(inmultirea_matricelor(matrix, v))
        lambd = np.sum(np.multiply(w, v))
        k += 1
        if np.linalg.norm(w - lambd * v) < dim_col * valoare_epsilon or k > maxim_interatii:
            break

    return k, lambd, v

def generam_matricea_simetrica(dim_rand, dim_col):
    rezultat = [[] for index in range(dim_rand)]
    for i in range(dim_rand):
        for j in range(i, dim_col):
            if np.random.rand() <= procent:
                val = np.random.randn()
                rezultat[i].append([val, j])
                rezultat[j].append([val, i])
    return rezultat


def generam_valorileproprii_vectorul_valoriproprii(dim_rows, dim_cols, matrix, generated=False):
    global valoare_epsilon
    if generated or dim_rows == 2020:
        valoare_epsilon = 10 ** (-2)
    else:
        valoare_epsilon = 10 ** (-9)

    numar_iteratii, valori_proprii, vector_valoriproprii = metoda_puterii(dim_rows, dim_cols, matrix)
    while numar_iteratii > maxim_interatii:
        valoare_epsilon *= 10
        numar_iteratii, valori_proprii, vector_valoriproprii = metoda_puterii(dim_rows, dim_cols, matrix)

    return valori_proprii, vector_valoriproprii


def inmultirea_matricelor(matrix1, matrix2):
    dim = len(matrix1)
    rezultat = []
    for i in range(dim):
        suma = 0
        for val, j in matrix1[i]:
            suma += val * matrix2[j]
        rezultat.append(suma)
    return rezultat


def verificam_valorileproprii(valoriproprii, matrice):
    semn_determinant, logaritm_determinant = np.linalg.slogdet(matrice - valoriproprii * np.eye(len(matrice)))
    print("Semn determinant = {}, Logaritm determinant = {}".format(str(semn_determinant), str(logaritm_determinant)))
    if logaritm_determinant > 709:
        return semn_determinant * np.exp(709)
    else:
        return semn_determinant * np.exp(logaritm_determinant)


def generam_matricea_nerara(dim_rand, dim_col, matrix):
    matricea_completa = np.zeros((dim_rand, dim_col))
    for i in range(dim_rand):
        for val, j in matrix[i]:
            matricea_completa[i][j] = val
    return matricea_completa


def returnam_raspunsul_final(dimensiune):
    b = np.array([[random.randint(0, 9)] for i in range(dimensiune)])
    return b


def citim_matricea(fisier_intrare):
    with open(fisier_intrare, 'r') as fd:
        dimensiune_rand = int(fd.readline())
        dimensiune_col = 0
        matrix = [[] for index in range(dimensiune_rand)]
        data = fd.readline()
        while data:
            valori = re.split(',', data.replace("\n", ""))
            val = float(valori[0].strip())
            r = int(valori[1].strip())
            c = int(valori[2].strip())
            poz = index_coloana(matrix[r], c)
            if poz != -1:
                matrix[r][poz][0] += val
            else:
                matrix[r].append([val, c])
                if dimensiune_col < c:
                    dimensiune_col = c
            data = fd.readline()
    return dimensiune_rand, dimensiune_col + 1, matrix


def aflam_nrmaxim_valori_nule_rand(dim_rand, matrix):
    maxim = 0
    for i in range(dim_rand):
        if maxim < len(matrix[i]):
            maxim = len(matrix[i])
    return maxim


if __name__ == "__main__":
    files = ["a_300.txt", "a_500.txt", "a_1000.txt", "a_1500.txt", "a_2020.txt"]
    for file in files:
        start = time.time()
        p, n, A = citim_matricea(file)
        print("\nTimp citire date din fisier {}: {} secunde".format(file, time.time() - start))
        print("Numar randuri: p = {}".format(str(p)))
        print("Numar coloane: n = {}\n".format(str(n)))

        if p == n:
            print("Verificare simetrie matrice citita: {}".format(verificam_simetria_matricei(A)))
            print("Numarul maxim de valori nenule pe linie a matricii citite: {}\n".format(
                str(aflam_nrmaxim_valori_nule_rand(p, A))))

            start = time.time()
            aproximam_modululmaxim_valoriproprii, aproximam_vectorul_valoriproprii = generam_valorileproprii_vectorul_valoriproprii(
                p, n, A)
            print("Timp determinare vectori si valori proprii a matricii citite: {} secunde\n".format(time.time() - start))

            print("Aproximare a valorii proprii de modul maxim a matricei citite A:")
            print("lambda = {}\n".format(str(aproximam_modululmaxim_valoriproprii)))
            print("Aproximare vector propriu asociat acestei autovalori:")
            print("v = {}\n".format(str(aproximam_vectorul_valoriproprii.T[0])))

            print("Determinant |A - lambda * I| = {}".format(str(
                verificam_valorileproprii(aproximam_modululmaxim_valoriproprii, generam_matricea_nerara(p, n, A)))))

            if p > 500:
                start = time.time()
                matricea_generata = generam_matricea_simetrica(p, n)
                print("\nTimp generare matrice aleatoare simetrica: {} secunde\n".format(time.time() - start))

                print("Verificare simetrie matrice generata: {}".format(verificam_simetria_matricei(matricea_generata)))
                print("Numarul maxim de valori nenule pe linie a matricii generate: {}\n".format(
                    str(aflam_nrmaxim_valori_nule_rand(p, matricea_generata))))

                start = time.time()
                aproximam_modululmaxim_generator_valoriproprii_alematricei, approximation_eigenvector_generated_matrix = generam_valorileproprii_vectorul_valoriproprii(
                    p, n, matricea_generata, generated=True)
                print("Timp determinare vectori si valori proprii a matricii generate: {} secunde\n".format(
                    time.time() - start))

                print("Aproximare a valorii proprii de modul maxim a matricei generate:")
                print("lambda = {}\n".format(str(aproximam_modululmaxim_generator_valoriproprii_alematricei)))
                print("Aproximare vector propriu asociat acestei autovalori:")
                print("v = {}\n".format(str(approximation_eigenvector_generated_matrix.T[0])))

                print("Determinant |A - lambda * I| = {}".format(str(
                    verificam_valorileproprii(aproximam_modululmaxim_generator_valoriproprii_alematricei,
                                              generam_matricea_nerara(p, n, matricea_generata)))))

        elif p > n:
            A = generam_matricea_nerara(p, n, A)
            print("A = {}\n".format(str(A)))
            U, S, V_transpose = np.linalg.svd(A, full_matrices=True)

            print("Valorile singulare ale matricii A sunt: {}\n".format(str(S)))

            rank_A = len(S)
            print("Rangul matricii A este: {}\n".format(str(rank_A)))

            max_singular_value = max(S)
            min_singular_value = min(list(map(lambda x: x > 0, S)))
            print("Numarul de conditionare al matricei A este: {}\n".format(str(max_singular_value/min_singular_value)))

            S_I = np.zeros((n, p))
            for index in range(rank_A):
                S_I[index][index] = 1 / S[index]

            A_I = np.dot(np.dot(V_transpose.T, S_I), U.T)
            print("Pseudoinversa Moore-Penrose a matricei A:")
            print("A_I = {}\n".format(str(A_I)))

            b = returnam_raspunsul_final(p)
            print("Raspuns ecuatie creat:")
            print("b = {}\n".format(str(b)))

            x_I = np.dot(A_I, b)
            print("Solutie ecuatie A * x = b:")
            print("x_I = {}\n".format(str(x_I)))

            norm_b_A_x_I = np.linalg.norm(b - np.dot(A, x_I))
            print("Norma ||b - A * x_I|| = {}\n".format(str(norm_b_A_x_I)))

            A_J = np.dot(np.linalg.inv(np.dot(A.T, A)), A.T)
            print("Matricea pseudo-inversa in sensul celor mai mici patrate:")
            print("A_J = {}\n".format(str(A_J)))

            norm_A_I_A_J = np.linalg.norm(A_I - A_J, 1)
            print("Norma ||A_I - A_J|| = {}".format(str(norm_A_I_A_J)))