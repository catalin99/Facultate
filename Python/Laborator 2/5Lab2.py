"""
    Sa se scrie o functie care primeste ca parametru o lista x, si un numar k.
    Sa se returneze o lista cu tuple care sa reprezinte combinari de len(x) luate
    cate k din lista x. Exemplu: pentru lista x = [1,2,3,4] si k = 3 se va returna
    [(1, 2, 3), (1, 2, 4), (1, 3, 4), (2, 3, 4)].
"""

from itertools import combinations

def combinari(lista, k):
    return list(combinations(lista, k))

print(combinari([1, 2, 3, 4], 3))