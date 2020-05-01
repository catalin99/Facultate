"""
    Fie functia validate_dict care primeste ca parametru un set de tuple care reprezinta
    reguli de validare pentru un dictionar cu chei de tipul string si valori tot de tipul
    string si un dictionar. O regula este definita astfel: (cheie, "prefix", "middle",
    "sufix"). O valoare este considerata valida daca incepe cu "prefix", "middle" se
    gaseste in interiorul valorii (nu la inceput sau sfarsit) si se sfarsete cu "sufix".
    Functia va returna True daca dictionarul dat ca parametru respecta toate regulile,
    False in caz contrar.
"""

def validate_dict(dictionar, rules):
    for rule in rules:
        myStr = dictionar[rule[0]]
        if not (myStr.startswith(rule[1])) or not (myStr.endswith(rule[3])) or (myStr.find(rule[2])) <= 0 or myStr.find(rule[2]) == len(myStr) - len(rule[2]):
            return False
    return True

dictionar={"key2": "starting the engine in the middle of the winter",
            "key1": "come inside, it's too cold outside",
           "key3": "this is not valid"}

print(validate_dict(dictionar, [("key1", "", "inside", ""), ("key2", "start", "middle", "winter"), ("key3","","is", "")]))