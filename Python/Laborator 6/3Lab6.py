"""
    Sa se scrie o functie care primeste ca parametru un sir de caractere text
    si o lista de expresii regulate si returneaza o lista de siruri de caractere
    care fac match pe cel putin o expresie regulata data ca parametru.
"""

import re

def cauta_match(text, listaExpresii):
    l = list()
    text = text.split()
    for i in text:
        for j in listaExpresii:
            if re.match(i, j):
                l.append(i)
    print(l)

text = "ANaaa mer mdsjkd"
listaExpresii = ["ANaaa", "[A-N][a-n]"]
cauta_match(text, listaExpresii)
