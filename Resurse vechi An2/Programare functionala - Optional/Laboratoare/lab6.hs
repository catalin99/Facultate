

s xs = s' 0 xs
	where 
		s' v [] = v
		s' v (x:xs) = s' (v+x) xs  

foldl' :: (b->a->b)->b->[a]->b
foldl' f v [] = v
foldl' f v (x:xs) = foldl' f (f v x) xs

length' = foldl' (\acc _->1+acc) 0 

reverse' = foldl' (\acc x->(x:acc)) []

foldlMap f  = foldl' (\acc x->acc++[f x]) []