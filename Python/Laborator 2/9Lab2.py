"""
    Să se scrie o funție ce va ordona o listă de tuple de string-uri în funcție
    de al 3-lea caracter al celui de-al 2-lea element din tuplă. Exemplu:
    [('abc', 'bcd'), ('abc', 'zza')] ==> [('abc', 'zza'), ('abc', 'bcd')]
"""

def ordonare(lista):
    lista.sort(key=lambda param: param[1][2])
    print(lista)

ordonare([('abc', 'bcd'), ('abc', 'zza')])