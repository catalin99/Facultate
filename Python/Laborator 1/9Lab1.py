"""
    Scrieti o functie care returneaza cel mai mare numar prim dintr-un e caractere primit ca paramentru. Daca nu are numere prime se va returna -1.
"""

def estePrim(numar):
    if (numar == 0 or numar == 1):
        return False
    else:
        for i in range(2, numar):
            if (numar % i == 0):
                return False
    return True

print(estePrim(271))

def largestPrime(sir):
    for litera in sir:
        if (litera not in '0123456789'):
            sir = sir.replace(litera, ' ')
    lista_numere = sir.split()
    largest_prime = -1
    for i in lista_numere:
        x = int(i)
        if ((estePrim(x) == True) and (x > largest_prime)):
            largest_prime = x
    return largest_prime

print(largestPrime('ajgdbs35ajbd21jagb271kajs97jhdg'))