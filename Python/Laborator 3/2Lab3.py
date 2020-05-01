"""
    Scrieti o functie care primeste ca parametru un sir de caractere
    si returneaza un dictionar in care cheile sunt caracterele din
    componenta sirului de caractere iar valorile sunt reprezentate
    de numarul de aparitii ale caracterului respectiv in textul dat.
"""


def dictionarFrecventaCaractere(sir):
    d = dict()
    for a in sir:
        d[a] = d.get(a, 0) + 1
    return d

print(dictionarFrecventaCaractere('Ana are mere.'))