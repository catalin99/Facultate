"""
    Scrieti o functie care sa returneze o lista cu primele n numere in sirul Fibonnacci
"""

def fibonnacci(n):
    f1 = 0
    f2 = 1
    fib = [0, 1]
    for i in range(n - 2):
        f3 = f1 + f2
        f1 = f2
        f2 = f3
        fib.append(f2)
    return fib

print(fibonnacci(10))

"""
    Varianta 2
"""

def fibo(n):
    fib = [0, 1]
    for _ in range(n - 2):
        fib.append(fib[-1] + fib[-2])
    return fib

print(fibo(10))