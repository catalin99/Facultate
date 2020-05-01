sumThree:: Int->Int->Int->Int
sumThree x y z= x+y+z

myMax:: Int->Int->Int
myMax x y = if x<=y
            then y
            else x

mySum::Int->Int
mySum n = if n<=0
          then n
          else n+mySum(n-1)

nFibo::Int->Int
nFibo x = if x==1
         then 0
         else if x==2
              then 1
              else nFibo(x-1)+nFibo(x-2)

myCmmdc::Int->Int->Int
myCmmdc x y = if y/=0
              then (myCmmdc y (x `mod` y))
              else x

myCmmmc::Int->Int->Int
myCmmmc x y = (x * y) `div` (myCmmdc x y)

iterare::Int->Int->Bool
iterare x y = if y==(x `div` 2 + 1)
                then True
                else
                     if x `mod` y==0
                          then False
                          else iterare x (y+1)

verifPrim::Int->Bool
verifPrim x = if iterare x 2==True
                then True
                else False

afis::Int->Int->[Int]
afis n x = if n==0
           then
                []
           else
                if verifPrim x==True
                     then 
                          [x] ++ afis (n-1) (x+1)
                     else 
                          afis n (x+1)     

firstPrimes::Int->[Int]
firstPrimes n = afis n 2