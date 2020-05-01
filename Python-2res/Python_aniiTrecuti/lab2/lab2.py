'''
Sa se scrie o functie care sa returneze o lista cu primele n numere din sirul lui Fibonacci.
'''

def fibo(n):
    fib=[0,1]
    for _ in range(n-2):
        fib.append(fib[-1]+fib[-2])
    return fib

#fibo(8) -> [0, 1, 1, 2, 3, 5, 8, 13]

'''
Sa se scrie o functie care primeste o lista de numere si returneaza o lista cu numerele prime care se gasesc in ea.
'''

def is_prime(a):
    x = True
    for i in range(2, a):
       if a%i == 0:
           x = False
    if x:
        return True
    else:
        return False

def prime_list(L):
    list = []
    for i in range(0,len(L)):
        if is_prime(L[i]):
            list.append(L[i])
    print(list)

'''
Fie un tuplu (x,y) reprezentarea unui punct intr-un sistem cartezian. Sa se scrie o functie care primeste ca parametru 
o lista de puncte si returneaza o lista de tuple (a,b,c) unice care reprezinta dreptele unice determinate de acele 
puncte ( (a,b,c) corespunde dreptei ax + by + c = 0).
'''

def line2p(p1, p2):
    x1, y1 = p1
    x2, y2 = p2
    dx = (x2 - x1)
    dy = y2 - y1
    a = dy
    b = -dx
    c = -x1 * dy + y1 * dx

    return (a, b, c) if a > 0 else (-a, -b, -c)


def lines(ls):
    rez = []
    for i in range(len(ls) - 1):
        for j in range(i, len(ls)):
            t = line2p(ls[i], ls[j])
            if t not in rez:
                rez += [t]
    return rez

#lines([(1, 2), [2, 4], [1, 2]]) -> [(0, 0, 0), (2, -1, 0)]

'''
Sa se scrie o functie care primeste ca parametri doua liste a si b si returneaza: (a intersectat cu b, 
a reunit cu b, a - b, b - a)
'''

def lists(l1,l2):
    intersect = [val for val in l1 if val in l2]
    reunion = list(set().union(l1,l2))
    difab = list(set(l1) - set(l2))
    difba =list(set(l2) - set(l1))
    print(intersect)
    print(reunion)
    print (difab)
    print (difba)

#lists([1,2,3,4],[3,4,5,6]) -> [3, 4] [1, 2, 3, 4, 5, 6] [1, 2] [5, 6]

'''
Sa se scrie o functie care primeste ca parametru o lista x, si un numar k. Sa se returneze o lista cu tuple care sa 
reprezinte combinari de len(x) luate cate k din lista x. Exemplu: pentru lista x = [1,2,3,4] si k = 3 se va returna 
[(1, 2, 3), (1, 2, 4), (1, 3, 4), (2, 3, 4)].
'''

from itertools import combinations

def comb(x, k):
    return list(combinations(x, k))

#comb([1, 2, 3, 4], 3) -> [(1, 2, 3), (1, 2, 4), (1, 3, 4), (2, 3, 4)]

'''
Sa se scrie o functie care primeste ca parametru un numar variabil de liste si un numar intreg x. 
Sa se returneze o lista care sa contina elementele care apar de exact x ori in listele primite. 
Exemplu: pentru listele [1,2,3], [2,3,4], [4,5,6], [4, 1, "test"] si x = 2 se va returna [1, 2, 3, 4] # 1 
se afla in lista 1 si 4, 2 se afla in lista 1 si 2, 3 se afla in listele 1 si 2, 4 se afla in listele 2 si 3.
'''

def numar(*args, x):
    toate = sum(args, [])
    return [e for e in set(toate) if toate.count(e) == x]

#numar([1,2,3],[2,3,4],[4,5,6],[4,1,"test"],x=2) -> [1,2,3]


'''
Sa se scrie o functie care primeste ca parametri un numar x default egal cu 1, un numar variabil de siruri de caractere
 si un flag boolean setat default pe True. Pentru fiecare sir de caractere, sa se genereze o lista care sa contina 
 caracterele care au codul ASCII divizibil cu x in caz ca flag-ul este setat pe True, in caz contrar sa contina 
 caracterele care au codul ASCII nedivizibil cu x. Exemplu: x=2, "test", "hello", "lab002", flag=False va returna 
 (["e", "s"], ["e", "o"], ["a"]). Atentie: functia trebuie sa returneze un numar variabil de liste care sa corespunda 
 cu numarul de siruri de caractere primite ca input.
'''

def div_cifre(*args):
    a = list(args)
    x, flag = 1, True
    if type(a[0]) == int:
        x = a.pop(0)
    if type(a[-1]) == bool:
        flag = a.pop(-1)

    return [[c for c in s if ord(c) % x != flag] for s in a]

#div_cifre(2, "test", "hello", "lab002", False) -> [['e', 's'], ['e', 'o'], ['a']]


'''
Sa se scrie o functie care primeste un numar variabil de liste si returneaza o lista de tuple astfel: primul tuplu sa 
contina primele elemente din liste, al doilea element sa contina elementele de pe pozitia 2 din liste, etc. Ex: pentru 
listele [1,2,3], [5,6,7], ["a", "b", "c"] se va returna: [(1,5,"a"), (2,6,"b"), (3,7,"c")]. Observatie: In cazul in 
care listele primite ca input nu au acelasi numar de elemente, elementele lipsa vor fi inlocuite cu None pentru a putea 
fi generate max([len(x) for x in input_lists]) tuple.
'''

from itertools import zip_longest
print(list(zip_longest([1, 2, 3, None], [5, 6], ["a", "b", "c"], fillvalue='piton')))

# [1,2,3], [5,6,7], ["a", "b", "c"] -> [(1,5,"a"), (2,6,"b"), (3,7,"c")]
# [1, 2, 3, None], [5, 6], ["a", "b", "c"] -> [(1, 5, 'a'), (2, 6, 'b'), (3, 'piton', 'c'), (None, 'piton', 'piton')]

'''
Să se scrie o funție ce va ordona o listă de tuple de string-uri în funcție de al 3-lea caracter al celui de-al 2-lea 
element din tuplă. Exemplu: [('abc', 'bcd'), ('abc', 'zza')] ==> [('abc', 'zza'), ('abc', 'bcd')]
'''

def ex9(*args):
    return sorted(args, key=lambda t: t[1][2])

#print(ex9(('abc', 'bcd'), ('abc', 'zza'))) -> [('abc', 'zza'), ('abc', 'bcd')]

