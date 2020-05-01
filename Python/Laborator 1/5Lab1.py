"""
    Scrieti o functie care verifica daca un sir de caractere contine caractere speciale(\r, \t, \n, \a, \b, \f, \v)
"""

def numar_caractere_speciale(sir):
    lista_caractere = ['\r', '\t', '\n', '\a', '\b', '\f', '\v']
    for i in range(len(lista_caractere)):
        if(lista_caractere[i] in sir):
            return "Sirul contine caractere speciale."
    return "Sirul nu contine carcatere speciale."


print(numar_caractere_speciale("ana are mere"))
print(numar_caractere_speciale("ana are mere\t"))

