bmiTell :: (RealFloat a) => a -> a -> String  
bmiTell weight height  
    | weight / height ^ 2 <= 18.5 = "You're underweight, you emo, you!"  
    | weight / height ^ 2 <= 25.0 = "You're supposedly normal. Pffft, I bet you're ugly!"  
    | weight / height ^ 2 <= 30.0 = "You're fat! Lose some weight, fatty!"  
    | otherwise                   = "You're a whale, congratulations!"  
	
	
	
bmiTelll :: (RealFloat a) => a -> a -> String  
bmiTelll weight height  
    | bmi <= 18.5 = "You're underweight, you emo, you!"  
    | bmi <= 25.0 = "You're supposedly normal. Pffft, I bet you're ugly!"  
    | bmi <= 30.0 = "You're fat! Lose some weight, fatty!"  
    | otherwise   = "You're a whale, congratulations!"  
    where bmi = weight / height ^ 2 
	
cylinder :: (RealFloat a) => a -> a -> a  
cylinder r h = 
    let sideArea = 2 * pi * r * h  
        topArea = pi * r ^2  
    in  sideArea + 2 * topArea

myMap :: (a->b) -> [a] -> [b]
myMap f [] = []
myMap f (x:xs) = f x : myMap f xs

myZip :: [a] -> [b] -> [(a,b)]
myZip [] [] =[]
myZip [] (x:xs)= []
myZip (x:xs) (y:ys) = (x,y) : myZip xs ys

sumInts :: Integer -> Integer -> Integer
sumInts x y = sumInts' x y 0

sumInts' :: Integer -> Integer -> Integer -> Integer
sumInts' x y sum =
    if (y<x) then
        sum
    else
        sumInts' x (y-1) (sum+y)

sq :: Int -> Int
sq x = x*x

sumSquares :: Int -> Int -> Int
sumSquares n m = sq n + sq m