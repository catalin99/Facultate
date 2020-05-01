"""
    Sa se scrie o functie cu numele problema1 ce returneaza o
    lista ordonata crescator ce contine toate cuvintele din sirul
    de caractere s dat ca parametru. Un cuvant este format din:
    litere mici si mari, cifre si caracterul underscore '_'.
"""
import os
import re
def problema1(s):
    s = re.sub(r'[^a-zA-Z0-9_]', ' ', s)
    lista = sorted(s.split())
    return lista

s = "ana are mere"
s1 = "@c3sta 3st3, un cuvant_."
s2 = "u"
#print(problema1(s))
#print(problema1(s1))
#print(problema1("u"))


"""
    Sa se scrie o functie cu numele problema2 care primeste ca 
    parametri un sir de caractere s si un sir de caractere url ce 
    reprezinta un link http. Sa se returneze True daca s se 
    gaseste in continutul de la link-ul http dat, sau False altfel.
"""

from urllib import request
def problema2(s, url):
    res = request.urlopen(url)
    result = res.read()
    return s.encode() in result


s = "2014 hackaday.com. All Rights Reserved."
url = "http://retro.hackaday.com/"
#print(problema2(s, url))

"""
    Sa se scrie o functie cu numele problema3 care primeste ca 
    parametru un sir de caractere path ce reprezinta path-ul 
    unui director. Sa se returneze o lista ordonata crescator cu 
    hash-urile md5 ale tuturor fisierelor din director (nerecursiv).
"""

from hashlib import md5, sha256

def problema3(path):
    fisiere_hash = list()
    for item in os.scandir(path):
        if item.is_file():
            with open(item.path, 'rb') as file:
                _hash = md5()
                f = file.read(4096)
                while f:
                    _hash.update(f)
                    f = file.read(4096)
                fisiere_hash.append(_hash.hexdigest())
    return sorted(fisiere_hash)

#print(problema3(".idea"))

"""
    Sa se scrie o functie cu numele problema4 ce primeste ca 
    parametru un sir de caractere path ce reprezinta path-ul unei 
    arhive zip. Sa se returneze o lista ordonata crescator cu 
    numele fisierelor care au size dupa compresie mai mare de 
    1 KB ( 1000 de bytes ).
"""

import zipfile
def problema4(path):
    nume_fisiere = list()
    z = zipfile.ZipFile(path)
    for item in z.infolist():
        if not item.is_dir() and item.compress_size > 1000:
            nume_fisiere.append(os.path.basename(item.filename))
    z.close()
    return sorted(nume_fisiere)

#print(problema4("arhiva.zip"))

"""
    Sa se scrie o functie cu numele problema5 care primeste ca 
    argumente un sir de caractere host, un numar port si un sir de 
    caractere text.
    Sa se returneze raspunsul final de la server, ca si string, 
    urmand urmatorul protocol definit:
    - clientul trimite continutul argumentului text la server
    - clientul va primi de la server un alt sir de caractere (de lungime 32)
    - clientul trimite serverului hash-ul sha256 al sirului primit anterior
    - clientul primeste raspunsul final de la server (de lungime 32) pe care il returneaza
"""

import socket
def problema5(ip, port, text):
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect((ip, port))

    #1
    s.sendall(text.encode())

    #2
    data = s.recv(32)
    _hash = sha256(data).hexdigest()

    #3
    s.sendall(_hash.encode())
    data = s.recv(32)
    s.close()
    return data.decode()

print(problema5("fiieval.tk", 6969, "c1624aedce5b46fd9855c133b3da473b"))
