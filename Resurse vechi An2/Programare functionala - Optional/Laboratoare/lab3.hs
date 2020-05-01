
head1 a = a!!0

head2 a = (take 1 a)

head3 [] = error "eroare"
head3 [x] = x
--head3 (x:xs) = x
head3 (x:_) = x

tail1 [] = error "eroare"
--tail1 [x] = x
tail1 (_:xs) = xs

len [] = 0
len (_:xs)=1+len xs

max1 [] = error "eroare"
max1 [x] = x
max1 (x:xs) = max x (max1 xs)

drop1 _ [] = []
drop1 0 xs = xs
drop1 n (_:xs) = drop1 (n-1) xs

reverse1 [] = []
reverse1 [x] = [x]
reverse1 (x:xs) = reverse1 (xs) ++ [x]

