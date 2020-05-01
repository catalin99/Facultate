'''
 Scrieti un program python care sa primeasca de la linia de comanda doua numere (a si b) si care sa afiseze:
a) a-b
b) a+b
c) a/b
d) a*b
'''

try:
    a=int (input())
    b=int (input())
    print(a)
    print(b)
except ValueError as eroare:
    print(type(eroare))
    print(eroare)
    raise SystemExit
try:
    print("a-b:" + str(a-b))
    print("a+b:" + str(a+b))
    print("a*b:" + str(a*b))
    print("a/b:" + str(a/b))
except ArithmeticError as eroare1:
    print(type(eroare1))
    print(eroare1)
    print("exceptie")
except Exception as eroare2:
    print(eroare2)

'''
Scrieti un script care primeste ca parametru de la linia de comanda un path si afiseaza primii 4096 bytes daca path-ul 
duce la un fisier, intrarile din acesta daca path-ul reprezinta un director si un mesaj de eroare daca path-ul nu este 
unul valid.
'''

import os

try:
    inputPath = input()
except IndexError as e:
    print(e)
    exit()
try:
    if os.path.isfile(inputPath):
        print(open(inputPath, 'rb').read(4096))
    elif os.path.isdir(inputPath):
        print(os.listdir(inputPath))
    else:
        print('Not valid path')
except Exception as e:
    print("some random exception happened", e)

'''
Scrieti o functie care primeste ca parametru un nume de fisier. Aceasta va scrie in fisier datele din os.environ, 
fiecare linie continand cate o intrare din acest dictionar, sub forma cheie [tab] valoare.
'''
import os

def get_env(fisier):
    d = dict(os.environ)
    try:
        f = open(fisier, 'w')
    except:
        print("file cannot be accessed")
        exit()
    for key in d:
        f.write(key + '\t' + d[key] + '\n')
    f.close()

get_env('env_da.txt')

'''
Scrieti o functie care primeste ca parametru un path ce reprezinta un director de pe sistem, parcurge recursiv structura
 de fisiere si directoare pe care acesta le contine si afiseaza in consola toate path-urile pe care le-a parcurs. NU aveti voie sa folositi os.walk.
'''
import os

def parcurgere(cale):
    if os.path.isfile(cale):
        print(cale)
    elif os.path.isdir(cale):
        print(cale)
        try:
            for f in os.path.listdir(cale):
                parcurgere(os.path.join(cale, f))
        except Exception:
            print("problema director")

#parcurgere("asdlkjk")

'''
Scrieti un script care primeste 2 parametri de la consola reprezentand un path catre un director de pe sistem si un nume
 de fisier. Scriptul va parcurge recursiv structura de fisiere si directoare din directorul dat ca parametru, utilizand 
 os.walk si va scrie in fisierul dat ca parametru toate path-urile pe care le-a parcurs si tipul acestuia 
 (FILE, DIRECTORY, UNKNOWN), separate de |. Fiecare path va fi scris pe cate o linie.
'''
from os import walk
from os.path import join, isfile, isdir

def enumerare(top, fisier):
    f = open(fisier, 'w')
    for root, dirs, files in walk(top):
        for name in files + dirs:
            entry = join(root, name)
            s = entry + '|' + \
                'FILE' if isfile(entry) else \
                'DIRECTORY' if isdir(entry) else \
                'UNKOWN'
            f.write(s + '\n')
    f.close()


enumerare('.', 'env_da.txt')

'''
Scrieti un script care primeste 3 parametri de la consola. Primul va fi un path catre un fisier, al doilea un path 
catre un director iar al treilea va fi dimensiunea unui buffer. Scriptul va copia fisierul dat ca parametru in 
directorul dat ca parametru, utilizand un buffer de marimea celui de-al treilea parametru, in bytes.
'''
from os.path import join

def copiere(fisier, cale, buffer_size):
    f = open(fisier, 'r')
    cp = open(join(cale, fisier), 'w')
    b = f.read(buffer_size)
    while len(b):
        cp.write(b)
        b = f.read(buffer_size)

    f.close()
    cp.close()


copiere('env_da.txt', '.\\asd\\', 10)

'''
Sa se scrie un script care primeste urmatoarele argumente: path, tree_depth, filesize , filecount, dircount si care 
creeaza o structura de directoare de adancime depth astfel: incepand din radacina path vor fi create dircount 
directoare si filecount fisiere cu continut de filesize octeti (doar caracterul "a" de exemplu") iar acest proces 
va fi repetat recursiv pentru fiecare director creat pana cand se obtine adancimea dorita (in directoarele aflate la 
adacimea maxima nu se vor crea alte directoare)
'''
from os import mkdir
from os.path import join


def kill_disk(p, depth, size, dcount, fcount):
    if depth > 0:
        for i in range(dcount):
            newp = join(p, 'dir' + str(i))
            mkdir(newp)
            kill_disk(newp, depth - 1, size, dcount, fcount)
        for i in range(fcount):
            open(join(p, 'file' + str(i)), 'w').write('a' * size)


kill_disk('./asd', 2, 64, 4, 4)
'''
full_path = calea absoluta catre fisier, os.path.abspath(path)
file_size = dimensiunea fisierului in octeti, os.path.getsize(path)
file_extension = extensia fisierului (daca are) sau "", os.path.splitext(path)[1]
can_read si can_write = True/False daca se poate citi din/scrie in fisier. os.access(path, mode, *, dir_fd=None, effective_ids=False, follow_symlinks=True)¶
'''

'''
Sa se scrie o functie search_by_content care primeste ca parametru doua siruri de caractere target si to_search si 
returneaza o lista de fisiere care contin to_search. Fisierele se vor cauta astfel: daca target este un fisier, se 
cauta doar in fisierul respectiv iar daca este un director se va cauta recursiv in toate fisierele din acel director. 
Daca target nu este nici fisier nici director, se va arunca o exceptie de tipul ValueError cu un mesaj corespunzator.
'''
from os.path import *
from os import listdir


def create_bin():
    f = open("binary", "wb")
    for i in range(256):
        f.write(chr(i).encode("utf-8"))
    f.write("hello world".encode("utf-8"))
    f.close()


def str_in_file(file_name, string):
    conditie = string.encode("utf-8") in open(file_name, 'rb').read()
    return [file_name] if conditie else []


def search_by_content(target, to_search, callback):
    rez = []
    try:

        if not exists(target):
            callback(ValueError)
            return []
        elif isfile(target):
            return str_in_file(target, to_search)
        elif isdir(target):
            for entry in listdir(target):
                path = join(target, entry)
                rez += search_by_content(path, to_search, callback)
    except Exception as error:
        callback(error)
    return rez


def callback_func(error):
    print(error)

#print(search_by_content("asfasdlkkjj", "hello", callback_func))
