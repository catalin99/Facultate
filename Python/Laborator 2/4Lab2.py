"""
    Scrieti o functie care primeste ca parametri doua liste a si b si returneza
    a intersectat cu b, a reunit cu b, a minus b si b minus a
"""

def operatiiListe(lista1, lista2):
    intersectie = []
    for i in lista1:
        if i in lista2:
            intersectie += [i]
    reuniune = list(set().union(lista1, lista2)) #set() selecteaza doar elementele unice
    a_minus_b = list(set(lista1) - set(lista2))
    b_minus_a = list(set(lista2) - set(lista1))
    return intersectie, reuniune, a_minus_b, b_minus_a

print(operatiiListe([1, 2, 3, 4], [3, 4, 5, 6]))