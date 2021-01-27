import numpy as np
import re
import time
import copy

valoare_epsilon = 10 ** (-8)
maxim_interatii = 10000


def citim_matricea_rara(fisier_intrare):
    with open(fisier_intrare, 'r') as fd:
        dimensiune = int(fd.readline())
        matrice = [[] for index in range(dimensiune)]
        data = fd.readline()
        while data:
            valori = re.split(',', data.replace("\n", ""))
            val = float(valori[0].strip())
            r = int(valori[1].strip())
            c = int(valori[2].strip())
            pozitia = index_coloana(matrice[r], c)
            if pozitia != -1:
                matrice[r][pozitia][0] += val
            else:
                matrice[r].append((val, c))
            data = fd.readline()
    return matrice


def vectorul_termenilor_liberi(fisier_intrare):
    with open(fisier_intrare, 'r') as fd:
        dim = int(fd.readline())
        vector_rezultat = []
        data = fd.readline()
        while data:
            vector_rezultat.append(float(data.replace("\n", '').strip()))
            data = fd.readline()
    return vector_rezultat


def verificare_coloana_principala(matrix):
    dim = len(matrix)
    for index in range(dim):
        pozitia = index_coloana(matrix[index], index)
        if pozitia == -1:
            return False
        else:
            if abs(matrix[index][pozitia][0] - 0.0) <= valoare_epsilon:
                return False
    return True


def generam_noi_valori_pentru_x(matricea_A, b, x_actual):
    dim = len(x_actual)
    for i in range(dim):
        suma = 0
        for valoare, j in matricea_A[i]:
            if j != i:
                if j < i:
                    suma += valoare * x_actual[j]
                elif j > i:
                    suma += valoare * x_actual[j]
        poz = index_coloana(matricea_A[i], i)
        x_actual[i] = (b[i] - suma) / matricea_A[i][poz][0]
    return x_actual


def generam_solutia_finala(matricea_A, b):
    dim = len(matricea_A)
    x = [0 for index in range(dim)]
    nr_iteratii_curent = 0
    while True:
        x_new = generam_noi_valori_pentru_x(matricea_A, b, copy.deepcopy(x))
        delta_x = np.linalg.norm(np.array(x_new) - np.array(x))
        x = x_new
        nr_iteratii_curent = nr_iteratii_curent + 1
        if (delta_x < valoare_epsilon) or (nr_iteratii_curent > maxim_interatii) or (delta_x > (10 ** 8)):
            break
    if delta_x < valoare_epsilon:
        return x
    else:
        print("divergenta")
        return None


def index_coloana(r, c):
    lista = list(filter(lambda x: x[1] == c, r))
    if len(lista) == 0:
        return -1
    else:
        index = r.index(lista[0])
        return index


def inmultirea_matricelor(matricea_A, x):
    dim = len(matricea_A)
    rezultatul = []
    for i in range(dim):
        suma = 0
        for valoarea, j in matricea_A[i]:
            suma = suma + valoarea * x[j]
        rezultatul.append(suma)
    return rezultatul


def verificare_coloana_principala(matrix):
    dim = len(matrix)
    for index in range(dim):
        pozitia = index_coloana(matrix[index], index)
        if pozitia == -1:
            return False
        else:
            if abs(matrix[index][pozitia][0] - 0.0) <= valoare_epsilon:
                return False
    return True

if __name__ == "__main__":
    for i in range(5):
        print("Rezultate pentru fisierele: a_{}.txt si b_{}.txt".format(str(i + 1), str(i + 1)))
        start = time.time()
        A = citim_matricea_rara("a_{}.txt".format(str(i + 1)))
        b = vectorul_termenilor_liberi("b_{}.txt".format(str(i + 1)))
        print("Timp citire date: {} secunde".format(time.time() - start))
        print("Verificare coloana principala: {}".format(verificare_coloana_principala(A)))

        x_GS = generam_solutia_finala(A, b)
        if x_GS is not None:
            print("x_GS = " + str(x_GS))
            rezultatul_inmultirii = inmultirea_matricelor(A, x_GS)
            valoarea_normei = np.linalg.norm(np.array(rezultatul_inmultirii) - np.array(b), np.inf)
            print("Norma ||A * x_GS - b || = {}".format(valoarea_normei))
        print()
