"""
    Sa se scrie o functie care primeste ca parametri doua liste a
    si b si returneaza un tuplu de seturi care sa contina:
    (a intersectat cu b, a reunit cu b, a - b, b - a)
"""

def operatii(a, b):
    a = set(a)
    b = set(b)
    return (a | b, a & b, a - b, b - a)

print(operatii([1, 2, 3, 4], [3, 4, 5, 6]))