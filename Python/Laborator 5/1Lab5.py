"""
    Scrieti un program python care sa primeasca de la linia de comanda doua numere si care
    sa afiseze a-b, a+b, a/b, a*b
"""

def operatii(a, b):
    try:
        print(a, " - ", b, " = ", (a - b))
        print(a, " + ", b, " = ", (a + b))
        print(a, " / ", b, " = ", (a / b))
        print(a, " * ", b, " = ", (a * b))
    except ZeroDivisionError as exc:
        print("Impartire la zero.")
    except TypeError as exc:
        print("Tip de date incompatibil.")
    except Exception as exc:
        print(exc, type(exc))

a = input("a = ")
b = input("b = ")
operatii(int(a), int(b))