-- (div 10)   //  ('div'2)

--app2 :: (t -> t) -> t -> t
app2 function value = function(function value) 

--zipWith zipWith (+) [1..100] [500..600]

map2 function list = [ function x | x<-list ]

map' function [] = []
map' function (x:xs) = (function x): (map' function xs)

qSort [] = []
qSort (x:xs) = (qSort(filter(<x) xs))++[x]++(qSort(filter(>=x) xs))

--suma patratelor perf pare mai mici decat n

function n = sum (filter even ( takeWhile (<n) (map (^2) [1..] ) ) )

function2 n = sum ( patrate_perfecte_pare )
	where
		patrate_perfecte_pare = filter even patrate_perfecte
		patrate_perfecte = takeWhile (<n) ( map (^2) [1..])

--filter (\x->mod x 2==1) [] 

sumlmb = \x y->x+y

sumlmb2 = \x->(\y->x+y)

sumList [] = []
sumList (x:xs) = x+sumList xs

prodList []=1
prodList (x:xs) = x*prodList xs

sau [] = False
sau (x:xs) = x||sau xs

--f [] = value
--f (x:xs) = x Operator (f xs)
		-- = g x (f xs)

s = foldr (+) 0
p = foldr (*) 1

foldr' f v [] = v
foldr' f v (x:xs) = f x (foldr' f v xs)
--[1,2,3]  
--1 + (2+(3+0))

foldrLength = foldr (\_ acc->1+acc) 0 

foldrMap function = foldr (\x acc->((function x):acc)) []

tf1 n = sum [x*x | x<-[1..n]]
tf2 n = [(x,y,z)|x<-[1..n],y<-[1..n],z<-[1..n] ,x*x+y*y==z*z]
tf3 f p xs = map f (filter p xs) 
tf4 xs = (zip xs (tail xs))
 		