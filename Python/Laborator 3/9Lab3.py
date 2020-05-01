"""
    Sa se scrie o functie care primeste un numar variabil de seturi
    si returneaza un dictionar cu urmatoarele operatii dintre toate
    seturile doua cate doua: reuniune, intersectie, a-b, b-a.
    Cheia va avea urmatoarea forma: "a op b", unde a si b sunt
    doua seturi, iar op este operatorul aplicat: |, &, -.

    Ex: {1,2}, {2, 3} =>
    {
        "{1, 2} | {2, 3}": 3,
        "{1, 2} & {2, 3}": 1,
        "{1, 2} - {2, 3}": 1,
        ...
    }
"""

dict_op = {
    "&": lambda a, b: a & b,
    "|": lambda a, b: a | b,
    "-": lambda a, b: a - b
}


def print_pairs(*sets):
    op_dir = dict()

    for i in range(len(sets) - 1):
        for j in range(i + 1, len(sets)):
            for op in dict_op.keys():
                key = str(sets[i]) + ' ' + op + ' ' + str(sets[j])
                value = dict_op[op](sets[i], sets[j])
                op_dir[key] = value

            op = '-'
            key = str(sets[i]) + ' ' + op + ' ' + str(sets[j])
            value = dict_op[op](sets[j], sets[i])
            op_dir[key] = value
    print(op_dir)

print_pairs({1, 2}, {2, 3})