sumThree :: Int -> Int -> Int -> Int
sumThree x y z = x + y + z

prodThree :: Int -> Int -> Int -> Int
prodThree x y z = x * y * z

identity :: Int -> Int
identity x = x

myMax :: Int -> Int -> Int
myMax x y = if x <= y then y else x

myMaxThree :: Int -> Int -> Int -> Int
myMaxThree x y z = myMax (myMax x y) z

mySum :: Int -> Int
mySum x = if (x<=0) then 0 else x + mySum (x - 1)

fibo :: Int -> Int
fibo x = if (x == 0) then 0 
         else if (x == 1) then 1 
         else if (x == 2) then 1
         else fibo (x-1) + fibo (x-2)

cmmdc :: Int -> Int -> Int
cmmdc x y = if (x == y) then x
            else if (x < y) then cmmdc x (y-x)
            else cmmdc (x-y) x