sumThree :: Int -> Int -> Int -> Int
sumThree x y z = x + y + z

myMax :: Int -> Int -> Int
myMax x y = if x <= y
            then y
            else x

mySum :: Int -> Int
mySum n = if n <=0
        then 0
        else 
        n + mySum ( n - 1 )

mulThree x y z = x * y * z

fib n = if n <= 2
        then 1
        else fib(n - 1) + fib(n - 2)

cmmdc :: Int -> Int -> Int
cmmdc a 0 = a
cmmdc a b = cmmdc b (mod a b)
