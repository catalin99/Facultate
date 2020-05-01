-- varianta uncrurried pentru g
f :: (Int, Int) -> Int
f (x,y) = x + y

-- varianta curried pentru f
-- permite să fac aplicații parțiale ale funcțiilor 
g :: Int -> Int -> Int
g x y = x + y

addThree :: (Int, Int, Int) -> Int
addThree (x,y,z) = x + y + z

addThree' :: Int -> Int -> Int -> Int
addThree' x y z = x + y + z

process :: (a -> b) -> a -> b
process f x = f x

--funcEx1 :: (Int -> Int) -> Int -> Int -> Int

compose :: [a -> a] -> a -> a 
compose [] x = x
compose (f2:fs) x = f2 (compose fs x)
-- compose [id , (\x -> x -1) , (\x -> x + 1)] 10