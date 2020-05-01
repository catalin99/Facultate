"""
    Se da un sir de caractere ce reprezinta un polinom(ex: "3x^3 + 5x^2 - 2x - 5") si o valoare pentru x (intreg sau real). Evaluati polinomul pentru valoarea lui x data.
"""

def evaluatePolynomial(polynomial, value):
    polynomial = polynomial.replace('x', ' ')
    polynomial = polynomial.replace('^', '^ ')
    lista_poly = polynomial.split()
    print(lista_poly)
    rezultat = int(lista_poly[0])
    print(type(rezultat))
    count = 0
    for i in lista_poly[1:]:
        count += 1
        if (i == '^'):
            rezultat = rezultat * pow(value, int(lista_poly[count + 1]))
            print(rezultat)
        elif (i == '-'):
            rezultat -= int(lista_poly[count + 1])
            print(rezultat)
        elif (i == '+'):
            rezultat = rezultat + int(lista_poly[count + 1])
            print(rezultat)

    return rezultat



print(evaluatePolynomial("3x^3 + 5x^2 - 2x - 5", 2))