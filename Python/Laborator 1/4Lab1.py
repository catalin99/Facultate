"""
    Scrieti o functie care primeste ca paramatri 2 siruri de caractere si returneaza numarul de aparitii ale primului sir in al doilea.
"""

def numar_aparitii(sir1, sir2):
    numar = 0
    for i in range(len(sir2)):
        if (sir2[i:i+len(sir1)] == sir1):
            numar += 1
    return numar

print(numar_aparitii("are", "ana are ana are ana ana"))
