"""
    Scrieti un script care primeste ca parametru de la linia de comanda un path si
    afiseaza primii 4096 bytes daca path-ul duce la un fisier, intrarile din acesta daca
    path-ul reprezinta un director si un mesaj de eroare daca path-ul nu este unul valid.
"""

import os

path = input("Introduceti path-ul: ")

if (os.path.isfile(path)):
    try:
        print(os.getcwd())
        print(os.path.join(os.getcwd(), path))
        fp = os.path.join(os.getcwd(), path)
        nr=0
        with open(fp, 'rb') as fh:
            while nr < 4064:
                byte_s = fh.read(1)
                byte = byte_s[0]
                nr += 1
                print(byte)
    except Exception as exc:
        print(exc, type(exc))
else:
    try:
        if(os.path.isdir(path)):
            print("dir")
            dirs = os.listdir(path)
            for file in dirs:
                print(file)
    except Exception as exc:
        print(exc, type(exc))
    else:
        print("Path invalid.")


