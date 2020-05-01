
data Maybe a = Nothing | Just a

{-head [a]->a
[Int]


1:[]

-}

data L a = V | C a (L a) deriving Show

head'::L a-> a
head' V = error "Lista vida"
head' (C x _ ) = x -- head' (C 2 (C 1 V ) )

cT::L a-> L a->L a 
ct V xs = xs
cT (C x xs ) ys = C x (cT xs ys) --nu merge

data Bst = F Int | N Int Bst Bst V
s::Int -> Bst -> Bool
s n (F x) = n==x
s n (N x st dr)
	| n==x = True
	| n<x = s n st
	| otherwise = s n dr

-- s 2 (N 1 (F 2) (F 3))

