"""
Cel mai mare divizor comun a mai multor numere (numar variabil de parametri)
"""

def cmmdc2(a, b):
    while b:
        a, b = b, a%b
    return a

def cmmdc(*args):

    rez = args[0]
    args1 = args[1:] #->o lista de la primul caracter pana la sfarsit
    for a in args1:
        rez = cmmdc2(rez, a)
    return rez

# cmmdc(10, 5, 15) -> 5
# cmmdc(15,21,33,69) -> 3


'''
Scrieti o functie care calculeaza cate vocale sunt intr-un sir de caractere
'''

def nr_vocale(s):
    print(sum(map(s.lower().count, 'aeiou')))

#nr_vocale('theodora') -> 4

'''
Scrieti o functie care returneaza numarul de cuvinte care exista intr-un string. 
Cuvintele sunt separate de spatii, semne de punctuatie (, ;, ? ! . )
'''
def nrcuv(s):
    for semn in '?!.;,':
        s = s.replace(semn, ' ')
    return len(s.split())

#print(nrcuv("ana are mere"))

'''
Scrieti o functie care primeste ca parametri doua siruri de caractere 
si care returneaza numarul de aparitii ale primului sir de caractere in al doilea.
'''

def subOcc(s, q):
    i = 0
    count = 0
    for i in range(len(s) - len(q) + 1):
        if (s[i:i+len(q)] == q):
            count+=1
    return count

#subOcc(subOcc("ana are ana", "ana"))