"""
    Scrieti o functie care are ca parametri un intreg char_len si un numar variat de siruri
    si verifica daca fiecare 2 vecini respecta regula: al doilea sir incepe cu ultimele
    char_len caractere ale primului sir .(ca jocul Fazan)
"""

def verifica_fazan(char_len, *sir):
    siruri = sir
    for i, sir in enumerate(siruri):
        if (i + 1 < len(siruri)):
            sir1 = siruri[i]
            sir2 = siruri[i + 1]
            if (sir1[len(sir1) - char_len:] != sir2[0:char_len]):
                return "Gresit"
    return "Corect"

print(verifica_fazan(2, "canar", "are", "reme", "melc"))
