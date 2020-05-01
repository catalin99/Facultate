identitate x = x
sumThree :: Int -> Int -> Int -> Int
sumThree x y z = x + y + z
myMax :: Int -> Int -> Int
myMax x y = if x <= y then y else x
mySum :: Int -> Int
mySum x = if x <= 0 then 0 else x + mySum (x - 1)
nfibonacci :: Int -> Int
nfibonacci x = if x <= 0 then 0 else if x == 1 then 1 else if x == 2 then 1 else (x + nfibonacci (x-1))
divv :: Int -> Int -> Int
divv a b = a `div` 2
cmmdc :: Int -> Int -> Int
cmmdc a b = if a == b then a else if a<b then cmmdc a (b-a) else cmmdc (a-b) b
forn :: Int -> Int -> Int -> Bool
forn start x a = if a `mod` start == 0 then False else if start<x then forn (start+1) x a else True
nrprim :: Int -> Bool
nrprim a = if a == 2 then True else if a < 2 then False else forn 3 (divv a 2) a
check :: Int -> Int -> Int
check a x = if a<x && nrprim a == True then a //iteratie...
nprime x :: Int -> Int
nprime x = check 0 (x-1)