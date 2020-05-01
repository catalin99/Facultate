main = print (fac 20)

fac 0 = 1
fac n = n * fac (n-1)

smaller x y = if x < y then x else y
biger x y = if x > y then x else y

f::Int->Int->Int->Int
f x y z = x + y + z

count::Char->[Char]->Int
count c [] = 0
count c (x:xs) = if (c == x) then 1 + (count c xs) else count c xs