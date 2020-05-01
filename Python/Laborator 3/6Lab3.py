"""
   {
    "+": lambda a, b: a + b,
    "*": lambda a, b: a * b,
    "/": lambda a, b: a / b,
    "%": lambda a, b: a % b
}
 Sa se construiasca o functie apply_operator(operator, a, b) care va aplica peste a si b
 regula specificata de dictionarul global. Sa se implementeze astfel incat,
 in cazul adaugarii unui operator nou, sa nu fie necesara modificarea functiei.
"""

dict = {
	"+": lambda a, b: a + b,
	"*": lambda a, b: a * b,
	"/": lambda a, b: a / b,
	"%": lambda a, b: a%b
}

def apply_operator(operator, a, b):
	print(dict[operator](a, b))

apply_operator('*', 2, 5)