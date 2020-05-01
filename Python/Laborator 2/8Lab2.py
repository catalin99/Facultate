"""
    Sa se scrie o functie care primeste un numar variabil de liste si returneaza
    o lista de tuple astfel: primul tuplu sa contina primele elemente din liste,
    al doilea element sa contina elementele de pe pozitia 2 din liste, etc.
    Ex: pentru listele [1,2,3], [5,6,7], ["a", "b", "c"] se va returna:
    [(1,5,"a"), (2,6,"b"), (3,7,"c")]. Observatie: In cazul in care listele
    primite ca input nu au acelasi numar de elemente, elementele lipsa vor fi
    inlocuite cu None pentru a putea fi generate
    max([len(x) for x in input_lists]) tuple.
"""

from itertools import zip_longest

def functie(*liste):
    t = tuple(zip_longest(*liste, fillvalue = 'None'))
    return t

print(functie([1, 2, 3], [5, 6, 7], ["a", "b", "c"]))
print(functie([1, 2, 3, None], [5, 6], ["a", "b", "c"]))