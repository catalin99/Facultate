import Data.List

myLast a = (head.reverse) (a)
myButLast a = a !! ((length a)-2)
elementAt :: Int -> [a] -> a
elementAt a (x:xs) = last(x:(take a xs))
myLength a = length a
myReverse a = reverse a
isPalindrome a = a == reverse a
compress a = nub a
pack1 :: [Char] -> [[Char]]
pack1 xs = foldl(\acc x -> if not(null acc) && [x] `isPrefixOf` (last acc) 
                            then (init acc) ++ [(last acc) ++ [x]] 
                            else acc ++ [[x]]) [] xs
			
encode (x:xs) = (length (x:xs) , x)
--linie comanda map encode (group "aaaabccaadeeee")