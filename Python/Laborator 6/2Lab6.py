"""
    Sa se scrie o functie care primeste ca parametru un sir de caractere regex,
    un sir de caractere text si un numar intreg x si returneaza acele substring-uri
    de lungime maxim x care fac match pe expresia regulata data.
"""

import re

def verifica_match(regex, text, x):
    for j in range(len(text)-1):
        for i in range(x):
            if re.match(regex, text[j:j+i]):
                print(text[j:j+i])


verifica_match("07[0-9]{2}", "075367890ttt075467ff", 6)