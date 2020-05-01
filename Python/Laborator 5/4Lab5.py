"""
    Scrieti o functie care primeste ca parametru un path ce reprezinta un director de pe
    sistem, parcurge recursiv structura de fisiere si directoare pe care acesta le
    contine si afiseaza in consola toate path-urile pe care le-a parcurs. NU aveti voie
    sa folositi os.walk.
"""

import os

numeDirector = input("Introduceti calea directorului: ")


def parcurge_structura(director):
    if os.path.isdir(director):
        try:
            print("okkk")
            os.path.abspath(director)
            dirs = os.listdir(director)
            for file in dirs:
                if os.path.isfile(file):
                    print(os.path.abspath(file))
                else:
                    if os.path.isdir(file):
                        parcurge_structura(file)
        except Exception as exc:
            print(exc, type(exc))

parcurge_structura(numeDirector)