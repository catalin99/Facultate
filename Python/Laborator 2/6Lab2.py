"""
    Sa se scrie o functie care primeste ca parametru un numar variabil de liste
    si un numar intreg x. Sa se returneze o lista care sa contina elementele care
     apar de exact x ori in listele primite. Exemplu: pentru listele
     [1,2,3], [2,3,4], [4,5,6], [4, 1, "test"] si x = 2 se va returna
     [1, 2, 3] # 1 se afla in lista 1 si 4, 2 se afla in lista 1 si 2, 3
     se afla in listele 1 si 2.
"""

def numarDeXOri(*liste, x):
    toate_elementele = list(liste[0] + liste[1])
    elemente = []
    for i in range(2, len(liste)):
        toate_elementele = toate_elementele + liste[i]
    print(toate_elementele)
    for i in toate_elementele:
        if (toate_elementele.count(i) == x):
            elemente.append(i)
    return set(elemente)

print(numarDeXOri([1, 2, 3], [2, 3, 4], [4, 5, 6], [4, 1, "test"], x = 2))
