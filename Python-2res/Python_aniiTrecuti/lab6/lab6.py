'''
Sa se scrie o functie care extrage cuvintele dintr-un text dat ca parametru. Un cuvant este definit ca o secventa
de caractere alfa-numerice.
'''

import re

def extract_words(text):
    words = []
    r = re.compile("\w+")
    words = r.findall(text)
    return words

print(extract_words("Ana121 are12312 mere..."))

'''
Sa se scrie o functie care primeste ca parametru un sir de caractere regex, un sir de caractere text si un numar 
intreg x si returneaza acele substring-uri de lungime maxim x care fac match pe expresia regulata data.
'''

import re

def max_substring(regex, text, x):
    r=re.compile(regex)

    substrs = list()
    for i in r.findall(text):
        if len(i) == x:
            substrs.append(i)

    return substrs

print(max_substring("\w+", "ana are cateva mere parca cinci", 5))

'''
Sa se scrie o functie care primeste ca parametru un sir de caractere text si o lista de expresii regulate si returneaza 
o lista de siruri de caractere care fac match pe cel putin o expresie regulata data ca parametru.
'''

import re

def least_match(text, regex:list):
    result = []
    for i in regex:
        r = re.compile(i)
        if r.findall(text):
            result.append(r.findall(text))

    return result

print(least_match("hai12,,  acasa222 nu mai vreau   ,,!python", ["\w+", "\s+", ""]))

'''
Sa se scrie o functie care primeste ca parametru path-ul catre un document xml si un dictionar attrs si returneaza 
acele elemente care au ca atribute toate cheile din dictionar si ca valoare valorile corespunzatoare. De exemplu, 
pentru dictionarul {"class": "url", "name": "url-form", "data-id": "item"} se vor selecta elementele care au atributele:
 class="url" si name="url-form" si data-id="item".
'''

import re

dict = {
	"class": "url", 
	"name": "url-form", 
	"data-id": "item"	
}

def xml_regex(path, attrs: dict):
    pattern = ""
    r = re.compile("class=\"url\"\s+name=\"url-form\"\s+data-id=\"item\"")
    with open("D:\Facultate\Python\Lab5\ex4f.xml") as file:
        for i in file.readline():
            if r.search(i):
                print(r.search(i).group(1))

print (xml_regex("D:/Faculty/Python/Lab5/ex4f.xml", {"class": "url", "name": "url-form", "data-id": "item"}))