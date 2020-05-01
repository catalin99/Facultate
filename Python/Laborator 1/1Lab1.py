"""
    Gasiti cel mai mare divizor comun pentru un sir de numere.
"""

def cmmdc(*numbers):
        cmmdc = numbers[0]
        n = len(numbers)
        for i in range (1, n, 1):
            element = numbers[i]
            while element != cmmdc:
                if element > cmmdc:
                    element -= cmmdc
                elif element < cmmdc:
                    cmmdc -= element
        return cmmdc

print (cmmdc(6, 36, 12, 18, 6))

"""
    Varianta 2
"""

def cmmdc2(a, b):
    while b:
        a, b = b, a%b
    return a

def cmmdcII(*numbers):
    rezultat = numbers[0]
    numbers1 = numbers[1:] #in numbers1 se formeaza o lista cu elementele primite ca argument incepand cu cel aflat pe pozitia 1
    for i in numbers1:
        rezultat = cmmdc2(rezultat, i)
    return rezultat

print(cmmdcII(6, 36, 12, 18, 6))

