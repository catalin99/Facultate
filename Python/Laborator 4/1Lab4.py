"""
    Creati in modul care contine o functie numita 'sort_uuids'.
    Aceasta functie citeste fisierul 'sample.txt' si sorteaza liniile
    pe baza sirului aflat intre primul si al doilea semn '-'.
    ex: 00e43761-e18a-40c6-b252-3407aa1d8e45, va fi sortat dupa 'e18a'
    Tratati exceptiile si afisati raspunsul in fisierul 'result.txt'
"""

fin = r'C:\Users\diana\OneDrive\Desktop\Facultate\Python\Laborator 4\sample.txt'
fout = r'C:\Users\diana\OneDrive\Desktop\Facultate\Python\Laborator 4\results.txt'
fh = open(fin, 'r')
fh.seek(0)
l = list()

fh.seek(0)
for i in range(len(fin)):
    x = fh.readline()
    x = x.replace('-', ' ')
    x = x.split()
    l.append(x)

l.sort(key = lambda l: l[1])
"""sorteaza lista l dupa elementul de pe pozitia 1 din fiecare lista a listei"""

for i in l:
    print(i)

fg = open(fout, 'w')

for i in range(len(l)):
    fg.write(l[i][0] + '-' + l[i][1] + '-' + l[i][2] + '-' + l[i][3] + '-' + l[i][4] + '\n')

fg.close()
fh.close()