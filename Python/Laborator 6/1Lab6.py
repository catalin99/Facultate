"""
    Sa se scrie o functie care extrage cuvintele dintr-un text dat ca parametru.
    Un cuvant este definit ca o secventa de caractere alfa-numerice.
"""

def extrage_cuvinte(text):
    copyText = text
    for i in '?./,:;!':
        copyText = copyText.replace(i, " ")
    copyText = copyText.split()
    for i in copyText:
        print(i)

text = "Ana are mere, pere , 2 banane, 5 struguri."
extrage_cuvinte(text)