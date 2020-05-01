'''
Sa se scrie o functie care primeste ca parametri doua liste a si b si returneaza un tuplu de seturi care sa contina:
(a intersectat cu b, a reunit cu b, a - b, b - a)
'''

def p1(a, b):
    a, b = set(a), set(b)
    return (a & b, a | b, b - a, a - b)

'''
Scrieti o functie care primeste ca parametru un sir de caractere si returneaza un dictionar in care cheile sunt 
caracterele dn componenta sirului de caractere iar valorile sunt reprezentate de numarul de aparitii ale caracterului 
respectiv in textul dat.
'''

def problema2(s):
    d = {}
    for c in s:
        d[c]= d.get(c,0)+1
    return d

#problema2("Ana are mere") -> {'A': 1, 'n': 1, 'a': 2, ' ': 2, 'r': 2, 'e': 3, 'm': 1}

'''
Sa se compare doua dictionare fara a folosi operatorul "==" si sa se returneze un tuplu de liste de diferente astfel: 
(cheile_comune_dar_cu_valori_diferite, cheile_care_se_gasesc_doar_in_primul_dict, 
cheile_care_se_gasesc_doar_in_al_doilea_dict). (Atentie, dictionarele trebuiesc parcurse recursiv deoarece la randul 
lor pot contine alte containere, cum ar fi dictionare, liste, set-uri, etc)
'''

def p3(dict1, dict2):
    k1 = set(dict1.keys())
    k2 = set(dict2.keys())
    t1 = k1 - k2
    t2 = k2 - k1
    setValDiff = {}
    cheiComune = k1 & k2
    for k in cheiComune:
        if dict1[k] != dict2[k]:
            setValDiff.add(k)
    aux == 0
    if len(k1 - k2) and len(k2 - k1) and len(setValDiff):
        aux == 1
    return aux, setValDiff, k1 - k2, k2 - k1

'''
Fie functia build_xml_element care primeste urmatorii parametri: tag, content si elemente cheie-valoare date ca 
parametri cu nume. Sa se construiasca si sa se returneze un string care reprezinta elementul XML aferent. 
Exemplu: build_xml_element("a", "Hello there", href="http://python.org", _class="my-link", id="someid") => 
"<a href=\"http://python.org\" _class=\"my-link\" id=\"someid\">Hello there</a>"
'''

def build_xml_element(tag, content, **kwargs):
    s = "<" + tag + " "
    for k in kwargs.keys():
        s = s + k + "=" + kwargs[k] + " "
    s = s[:-1] + ">" + content + "</" + tag + ">"
    return s

'''
 Fie functia validate_dict care primeste ca parametru un set de tuple care reprezinta reguli de validare pentru un 
 dictionar cu chei de tipul string si valori tot de tipul string si un dictionare. O regula este definita astfel: 
 (cheie, "prefix", "middle", "sufix"). O valoare este considerata valida daca incepe cu "prefix", "middle" se gaseste 
 in interiorul valorii (nu la inceput sau sfarsit) si se sfarsete cu "sufix". Functia va returna True daca dictionarul 
 dat ca parametru respecta toate regulile, False in caz contrar. 
Exemplu: regulile [("key1", "", "inside", ""), ("key2", "start", "middle", "winter")] si dictionarul {"key2": "starting 
the engine in the middle of the winter", "key1": "come inside, it's too cold outside", "key3": "this is not valid"} => 
False deoarece desi regulile sunt respectate pentru "key1" si "key2", apare "key3" care nu apare in reguli.
'''
dictionar={"key2": "starting the engine in the middle of the winter",
            "key1": "come inside, it's too cold outside",
           "key3": "this is not valid"}

def validate_dict(dictionar, rules):
    for rule in rules:
        myStr = dictionar[rule[0]]
        if not myStr.startswith(rule[1]) or not myStr.endswith(rule[3]) or myStr.find(rule[2]) <= 0 or myStr.find(
                rule[2]) == len(myStr) - len(rule[2]):
            return False
    return True

print(validate_dict(dictionar, [("key1", "", "inside", ""), ("key2", "start", "middle", "winter"), ("key3","","is", "")]))


gd = {
    "+": lambda a, b: a + b,
    "*": lambda a, b: a * b,
    "/": lambda a, b: a / b,
    "%": lambda a, b: a % b
}

'''
Sa se construiasca o functie apply_operator(operator, a, b) care va aplica peste a si b regula specificata de 
dictionarul global. Sa se implementeze astfel incat, in cazul adaugarii unui operator nou, sa nu fie necesara 
modificarea functiei. 
'''

def apply_operator(operator, a, b):
    if operator in gd:
        return gd[operator](a, b)


'''
Fie un dictionar global definit asemanator cu cel de mai sus, cu deosebirea ca functiile date ca valori ale 
dictionarului poate primi orice combinatie de parametri. Sa se scrie o functie apply_function care primeste ca 
parametru numele unei operatii si aplica functia corespunzatoare peste argumentele primite. Sa se implementeze astfel 
incat, in cazul adaugarii unei functii noi, sa nu fie necesara modificarea functiei apply_function.
'''

gd2 = {
    "print_all": lambda *a, **k: print(a, k),
    "print_args_commas": lambda *a, **k: print(a, k, sep=", "),
    "print_only_args": lambda *a, **k: print(a),
    "print_only_kwargs": lambda *a, **k: print(k)
}


def apply_function(operator, *args, **kwargs):
    if operator in gd2:
        return gd2[operator](args, kwargs)


#apply_function("print_all", 2, 3)

'''
Sa se scrie o functie care primeste ca parametru un set si returneaza un tuplu (a, b), a reprezentand numarul de 
elemente unice din set iar b reprezentand numarul de elemente duplicate din set.
'''

def p8(set1):
    a=0
    b=0

    return (len(set1), 0)

'''
 Sa se scrie o functie care primeste un numar variabil de seturi si returneaza un dictionar cu urmatoarele operatii 
 dintre toate seturile doua cate doua: reuniune, intersectie, a-b, b-a. Cheia va avea urmatoarea forma: "a op b", 
 unde a si b sunt doua seturi, iar op este operatorul aplicat: |, &, -. 
'''

def buildDict(*args):
    myDict = {}
    for elem1 in args:
        for elem2 in args:
            if (elem1 != elem2):
                myDict[str(elem1) + "|" + str(elem2)] = elem1 | elem2
                myDict[str(elem1) + "&" + str(elem2)] = elem1 & elem2
                myDict[str(elem1) + "-" + str(elem2)] = elem1 - elem2
    return myDict


#print(buildDict({2, 3}, {4, 5}))