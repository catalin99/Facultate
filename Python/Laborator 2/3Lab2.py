"""
   Fie un tuplu (x,y) reprezentarea unui punct intr-un sistem cartezian.
   Sa se scrie o functie care primeste ca parametru o lista de puncte si
   returneaza o lista de tuple (a,b,c) unice care reprezinta dreptele unice
   determinate de acele puncte ( (a,b,c) corespunde dreptei ax + by + c = 0).
"""

def line2p(p1, p2):
    x1, y1 = p1
    x2, y2 = p2
    dx = (x2 - x1)
    dy = y2 - y1
    a = dy
    b = -dx
    c = -x1 * dy + y1 * dx

    return (a, b, c) if a > 0 else (-a, -b, -c)


def lines(ls):
    rez = []
    for i in range(len(ls) - 1):
        for j in range(i, len(ls)):
            t = line2p(ls[i], ls[j])
            if t not in rez:
                rez += [t]
    return rez

print(lines([(1, 2), [2, 4], [1, 2]]))
