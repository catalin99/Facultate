"""
    Scrieti o functie care calculeaza cate vocale sunt intr-un string
"""

def vocale(sir):
    numar_vocale = 0
    for i in range(len(sir)):
        if sir[i] in ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']:
            numar_vocale += 1
    return numar_vocale

print (vocale('Ana are mere si pere'))

"""
    Varianta 2
"""

def nr_vocale(sir):
    return sum(map(sir.lower().count, 'aeiou'))

print(nr_vocale('Ana are mere si pere'))