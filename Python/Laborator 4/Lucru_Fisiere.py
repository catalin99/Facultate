fp = r'C:\Users\diana\OneDrive\Desktop\Facultate\Python\py.txt'
""" Punem r inainte pentru a putea lasa caracterele speciale \ intacte. Daca nu vrem sa punem r putem dubla \ """

fh = open(fp, 'r')
fh.read()
""" Asa citim ceea ce este in fisier. Acum cursorul este la finalul fisierului"""

fh.seek(0)
""" Asa ducem cursorul pe pozitia 0, adica la inceputul fisierului si putem citi din nou informtiile din el"""

fh.seek(1100)
fh.tell()
fh.read(2)
""" Asa am dus cursorul la pozitia 1100, apoi cu tell intrebam la ce pozitie e cursorul si va spune 1100, iar cu read(2) citim caracterele doar pana la pozitia 2"""
""" Astfel fh ramane deschis"""

fh.close()
""" Inchide fisierul fh"""
fh.closed
""" Verifica daca fh este inchis"""

with open(fp, 'r') as fh:
        fh.read()
""" Astfel fh este inchis dupa ce se citesc datele"""

fh = open(fp, 'w')
fh.write('Cevaa')
""" Continutul din fp a fost sters si s-a scris textul nou"""

fh = open(fp, 'r')
fh.read()
""" Se citeste 'Cevaa' """
