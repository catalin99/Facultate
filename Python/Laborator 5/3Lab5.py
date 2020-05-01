"""
    Scrieti o functie care primeste ca parametru un nume de fisier. Aceasta va scrie
    in fisier datele din os.environ, fiecare linie continand cate o intrare din acest
    dictionar, sub forma cheie [tab] valoare.
"""
import os

numeFisier = input("Introduceti calea fisierului: ")

def scrieInFisier(fisier):
    fh = open(numeFisier, 'w')
    for linie in os.environ:
        fh.write(linie)
        fh.write("\t")
        fh.write(os.environ[linie])
        fh.write("\n")
    fh.close()

scrieInFisier(numeFisier)