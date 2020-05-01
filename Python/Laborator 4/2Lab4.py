"""
    Folositi acelasi fisier ca la problema precedenta, 'sample.txt' si modificati
    liniile care nu sunt in formatul UUID (8-4-4-4-12 si toate literele sa fie mici).
    Inlocuiti liniile respective cu textul '|INVALID_UUID|'
"""

fin = r'C:\Users\diana\OneDrive\Desktop\Facultate\Python\Laborator 4\sample.txt'
fh = open(fin, 'r')
fh.seek(0)
l = list()

for i in range(len(fin)):
    x = fh.readline()
    x = x.replace('-', ' ')
    x = x.split()
    l.append(x)

for i in range(len(l)):
    ok = 1
    l1=l[i][0]
    l2=l[i][1]
    l3=l[i][2]
    l4=l[i][3]
    l5=l[i][4]
    if(len(l1)!=8 or len(l2)!=4 or len(l3)!=4 or len(l4)!=4
            or len(l5)!=12):
        ok = 0
    for j in range(5):
        for k in l[i][j]:
            if (k not in '0123456789'):
                if (k.isupper()):
                    ok=0;
    if(ok == 0):
        l[i][0]=l[i][1]=l[i][2]=l[i][3]=l[i][4]=0

for i in l:
    print(i)


fh.close()