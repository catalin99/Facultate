"""
     Sa se compare doua dictionare fara a folosi operatorul "==" si
     sa se returneze un tuplu de liste de diferente astfel:
     (cheile_comune_dar_cu_valori_diferite,
     cheile_care_se_gasesc_doar_in_primul_dict,
     cheile_care_se_gasesc_doar_in_al_doilea_dict).
     (Atentie, dictionarele trebuiesc parcurse recursiv deoarece la
     randul lor pot contine alte containere, cum ar fi dictionare, liste, set-uri, etc)
"""

def comaparaDictionare(dict1, dict2):
    k1 = set(dict1.keys())
    k2 = set(dict2.keys())
    set_val_dif ={}
    chei_comune = k1 & k2
    for k in chei_comune:
        if (dict1[k] != dict2[k]):
            set_val_dif.add(k)
    aux = 0
    if (len(k1 - k2) and len(k2 - k1) and len(set_val_dif)):
        aux = 1
    return aux, set_val_dif, k1 - k2, k2 - k1