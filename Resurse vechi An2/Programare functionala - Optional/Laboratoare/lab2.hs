--"function_name :: Type -> Type"

--inc :: Int -> Int --max 2^32
inc a = a + 1

inc2 :: Integer -> Integer
inc2 a = a + 1  

inc3 :: Double -> Double
inc3 a = a + 1

--":type function_name" returneaza tipul functiei

sum2 :: Int -> Int -> Int 
sum2 x y = x + y

--orice functie in haskell ia un singur parametru; ia un parametru 
--de tip a si returneaza functia a->a

inc' :: Int -> Int
--inc' a = sum2 a 1
inc' = sum2 1

mul3 :: Int -> Int -> Int -> Int
mul3 x y z = x * y * z

mul3with9 = mul3 9

cmmdcEuclid :: Int -> Int -> Int
cmmdcEuclid x y 
	| x == y = x
	| x > y = cmmdcEuclid (x-y) y
	| x < y = cmmdcEuclid (y-x) x

cmmdcE :: Int -> Int -> Int
cmmdcE x y 
	| y == 0 = x
	| y > 0 = cmmdcE y (mod x y) 

testPalindrom :: Int -> Bool 
testPalindrom n 
	| ((show n) == (reverse (show n))) = True
	| otherwise = False
	
--homework	
reverseInt :: Integer -> Integer
reverseInt n
	|  n > 0 = ((mod n 10) * 10^(nrDigits(n)-1) + reverseInt (div n 10))
	|  otherwise = 0

nrDigits n 
	| n>0 = 1 + nrDigits(div n 10)
	| otherwise = 0

(%) a b = mod a b

isPalin a = if (g a 0 == a) then True else False
	where
		g a n
			| a == 0 = n
			| otherwise = g (a `div` 10) (n*10 + a%10)



repeat' :: a -> [a] 
repeat' x = xs where xs = x:xs

doubleLen :: [a] -> Int
doubleLen xs = let n=length xs in n+n

factorial 1=1
factorial n = n*factorial(n-1)