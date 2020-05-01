rem_dup::[Int]->[Int]
rem_dup [] = []
rem_dup [x] = [x]
rem_dup (x:xs)
		| x == head xs = rem_dup xs
		| otherwise = x: (rem_dup xs)

rem_dup_r::[Int]->[Int]
rem_dup_r = foldr f []
	where
		f x []=[x]
		f x acc 
				| x==(head(acc))=acc
				| otherwise = x:acc

rem_dup_l::[Int]->[Int]
rem_dup_l = foldl f []
	where 
		f [] x=[x]
		f acc x
			| last acc==x=acc
			| otherwise= acc++[x]

group_dup::[Int]->[[Int]]
group_dup = foldr f []
	where 
		f x []=[[x]]
		f x acc@(l:ls)
			| x==head(l)=(x:l):ls
			| otherwise = [x]:acc

d2u::[Int]->Int
d2u = foldl (\x y->x*10+y) 0  

--compunere functii 
app2 f = f.f 

--valoarea absoluta a sumei unei cozi a unei liste 
--(abs (sum (tail xs)))
 
 --vascl (x:xs)= (abs.sum) xs

quicksort :: Ord a => [a] -> [a]
quicksort []     = []
quicksort (x:xs) = (quicksort lesser) ++ [x] ++ (quicksort greater)
    where
        lesser  = filter (< x) xs
        greater = filter (>= x) xs