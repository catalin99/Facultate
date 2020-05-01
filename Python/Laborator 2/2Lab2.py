"""
    Scrieti o functie care orimeste ca parametru o lista de numere si returneaza o lista cu numerele prime din ea
"""

def estePrim(numar):
    if (numar < 2):
        return False
    for i in range(2, numar):
        if (numar % i == 0):
            return False
    return True

def listaPrime(lista_numere):
    lista_prime = []
    for i in lista_numere:
        if (estePrim(i)):
            lista_prime.append(i)
    return lista_prime

numere = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
print(listaPrime(numere))

"""
    Varianta 2
"""

def prime_list(L):
    list = []
    for i in range(0,len(L)):
        if estePrim(L[i]):
            list.append(L[i])
    print(list)

prime_list(numere)