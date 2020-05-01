"""
    Sa se scrie o functie care primeste ca parametru un set si
    returneaza un tuplu (a, b), a reprezentand numarul de elemente
    unice din set iar b reprezentand numarul de elemente duplicate
    din set.
"""


def lucru_set(param):
    d = dict.fromkeys(param, 0)
    for i in param:
        d[i]+=1
    nr = 0
    for i in d:
        if d[i] > 1:
            nr+=1
    return (len(set((param))), nr)

param=[2, 5, 8, 5, 5, 6, 6, 9, 10]
print(lucru_set(param))

