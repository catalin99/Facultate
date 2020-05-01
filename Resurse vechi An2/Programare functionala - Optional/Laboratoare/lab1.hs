double x = x + x
{----}

sum2 x y = x + y
{--apelare  sum2 x y 
		 	x `sum2` y
		 	x + y
		 	(+) x y
--}

estePar n = n `mod` 2 == 0

test x = if estePar x == True
	then double x 
	else double(double x)

min2 x y = if x<y
	then x
	else y

how_is x	| x < 0 = "negativ"
			| x == 0 = "zero"
			| x > 0 = "pozitiv"

r_sum 0 = 0
r_sum x = x + r_sum (x-1)

