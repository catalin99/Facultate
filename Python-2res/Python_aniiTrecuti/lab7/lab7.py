'''
Scrieti un program care la fiecare x secunde unde x va fi aleator ales la fiecare iteratie (din intervalul [a, b],
unde a, b sunt date ca argumente) afiseaza de cate minute ruleaza programul (in minute, cu doua zecimale).
Programul va rula la infinit.
'''

import random
import time

def timelogger(a, b):
    timp = time.time()
    while (True):
        x = random.randint(a,b)
        time.sleep(x)
        print((int)(time.time()-timp) // 60, " minutes and ", (int)(round((time.time()-timp) % 60,2)), "seconds")
print(timelogger(2, 10))

'''
 Scrieti doua functii de verificare daca un numar este prim, si verificati care dintre ele 
 este mai eficienta din punct de vedere al timpului.
'''

import math
import time


def prime1(a):
    count = 0
    for i in range(1, a+1):
        if a % i == 0:
            count += 1
    if count == 2:
        print("Numar prim")
    else:
        print("Numarul nu e prim")



def prime2(a):
    count = 0
    for i in range(2, int(math.sqrt(a))):
        if a % i == 0:
            count += 1
    if count == 0:
        print ("Numar prim")
    else:
        print("Numarul nu e prim")



def call_primes(a):
    dif1 = 0
    dif2 = 0

    x1 = time.time()
    prime1(a)
    x2 = time.time()
    prime2(a)
    x3 = time.time()

    dif1 = x2 - x1
    dif2 = x3 - x2

    if dif1 < dif2:
        print(dif1, " < ", dif2, "Primul algoritm ruleaza mai rapid ca al doilea!")

    elif dif1 > dif2:
        print(dif1, " > ", dif2, "Al doilea algoritm ruleaza mai rapid ca primul!")
    else:
        print("egale")


print(call_primes(104729))

'''
 Gasiti toate fisierele duplicate dintr-un director dat ca argument si afisati timpul de rulare. 
 Calea grupurilor de fisiere duplicate vor fi scrise intr-un fisier output.txt. 
'''

import time
import os
import hashlib
import sys

f = open(sys.argv[1], mode='r', buffering=-1, encoding=None, errors=None, newline=None, closefd=True, opener=None)


def hashfile(blocksize = 65536):
    hasher = hashlib.md5()
    buf = f.read(blocksize)
    while len(buf)>0:
        hasher.update(buf)
        buf = f.read(blocksize)
    f.close()
    return hasher.hexdigest()

time1 = time.time()
dups = dict()
f = open("Ex3out.txt", mode="w", closefd=True)
for files in os.listdir(sys.argv[1]):
    full_fileName = os.path.join(sys.argv[1], files)
    file_hash = hashfile(full_fileName)
    if file_hash in dups:
        dups[file_hash].append(full_fileName)
        f.write(full_fileName)
        f.write("\n")
    else:
        dups[file_hash] = [full_fileName]
time2 = time.time()

print ((time2 - time1) % 60)

'''
Sa se scrie un script care primeste ca argument un director si creeaza un fisier JSON cu date despre toate fisierele 
din acel director. Pentru fiecare fisier vor fi afisate urmatoarele informatii: nume_fisier, md5_fisier, sha256_fisier, 
size_fisier (in bytes), cand a fost creat fisierul (in format human-readable) si calea absoluta catre fisier.
'''

import os
import hashlib
import sys
import json
import time

s=""

for element in os.listdir(sys.argv[1]):
    file_info = dict()
    if os.path.isfile(os.path.join(sys.argv[1], element)):
        file_info.clear()
        f = open(os.path.join(sys.argv[1], element), mode="rb", closefd=True)

        h = hashlib.md5()
        h.update(f.read(65536))
        file_info["nume_fisier"] = element
        file_info["md5_fisier"] = h.hexdigest()

        h = hashlib.sha256()
        f.seek(0,0)
        h.update(f.read(65536))
        file_info["sha256_fisier"] = h.hexdigest()

        file_info["size_fisier"] = os.path.getsize(os.path.join(sys.argv[1], element))
        file_info["date_created"] = time.ctime(os.path.getctime(os.path.join(sys.argv[1], element)))
        file_info["full_path"] = str(os.path.join(sys.argv[1], element))

        s = json.dumps(file_info)
        open("serialization.json", "wt", closefd=True).write(s)
    print(s, "\n")

