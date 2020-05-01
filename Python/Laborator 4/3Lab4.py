"""
    Scrieti un script care citeste un fisier linie cu linie si pentru fiecare tripla
    (a, b, c), separate prin spatii, aplica operatorul c pentru operanzii a si b.
    Operatiile valide sunt: +, *, -, /, **
    ex: input: 3 5 ** -> output: 3 ** 5 = 243
        input: 7 2 + -> output: 7 + 2 = 9
"""

op_dict = {
    "+" : lambda a, b: a + b,
    "*" : lambda a, b: a * b,
    "-" : lambda a, b: a - b,
    "/" : lambda a, b: a / b,
    "**": lambda a, b: a ** b
}

fp = r'C:\Users\diana\OneDrive\Desktop\Facultate\Python\Laborator 4\operatiiEx3.txt'


def apply_operator(operator, a, b):
    try:
        print(op_dict[operator](a, b))
    except KeyError as exc:
        print("Nu exista operatorul")
    except Exception as exc:
        print(exc, type(exc))

try:
    lines = [line.rstrip('\n') for line in open(fp, 'r')]
except FileNotFoundError as exc:
    print("File not found")
except FileExistsError as exc:
    print("File exist error")
except Exception as exc:
    print(exc, type(exc))



for line in lines:
    l = line.split()
    print(l)
    a = l[0]
    b = l[1]
    operator = l[2]
    print(a + ' ' + operator + ' ' + b + ' = ')
    apply_operator(operator, int(a), int(b))
