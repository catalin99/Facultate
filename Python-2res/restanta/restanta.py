def problema0(a, b):
    suma=0
    for i in range(a, b):
        suma+=i
    return suma
#print( problema0(a=1, b=10))

import re
def problema1(my_str):
    sir=re.split(r'[A-Z]', my_str)
    litere=[]
    l=[]
    final=''
    for i in range(0, len(my_str)):
        if(my_str[i].isupper()):
            litere.append(my_str[i])
    for i in range(1, len(sir)):
        x=litere[i-1].lower()+sir[i]
        l.append(x)
    for i in range(0, len(l)-1):
        final = final + l[i] +'_'
    final+=l[i+1]
    return str(final)
print(problema1("CamelCase"))

def problema2(my_list):
    list=[]
    for i in my_list:
        nr=0
        for j in range(0, len(my_list)):
            if(i==my_list[j]):
                nr+=1
        if (nr%2==1) and (i not in list):
            list.append(i)
    return list
#print(problema2(my_list=[1, 2, 3, 1, 2, 3, 1, 5]))



