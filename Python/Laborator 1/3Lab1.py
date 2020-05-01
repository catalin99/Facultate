"""
    Scrieti o functie care returneaza numarul de cuvinte dintr-un string. Cuvintele sunt separate de .,?! :;
"""

def cuvinte(sir):
    numar_cuvinte = 0
    sir = sir.replace(',', ' ')
    sir = sir.replace('.', ' ')
    sir = sir.replace('?', ' ')
    sir = sir.replace('!', ' ')
    sir = sir.replace(';', ' ')
    sir = sir.replace(';', ' ')
    sir = sir.split()
    print (sir)
    return len(sir)

print(cuvinte("Ana .are,?66 de ! mere"))

""""
    Varianta 2
"""

def nr_cuvinte(sir):
    for semn in ',.?!;:':
        sir = sir.replace(semn, ' ')
    return len(sir.split())

print(nr_cuvinte("Ana .are,?66 de ! mere"))
