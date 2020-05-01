def impartire(a, b):
    try:
            rezultat = a/b
    except ZeroDivisionError as exc:
            print('Impartire la zero')
    except Exception as exc:
            print(exc, type(exc))
    else:
            print(rezultat)
    finally:
            print('Am ajuns la final')
            """ Aceasta linie va fi printata mereu"""

impartire(7, 0)
""" se afiseaza:
Impartire la zero
Am ajuns la final"""

impartire(7, 3)
""" se afiseaza:
2,3333333333
Am ajuns la final"""

impartire(7, 'a')
"""da eroare + se afiseaza:
Am ajuns la final"""


try:
    7/'a'
except:
    pass
""" Astfel trece mai departe fara a trata exceptia si fara a da eroare"""

""" Trebuie sa tratam exceptia corecta. Daca tratam alta exceptie, va da eroare oricum"""

