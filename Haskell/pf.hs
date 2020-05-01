//lab 1
ghci=glasgow haskell compiler interpretor
:q - quit
:? - help
:cd 
:r 
:t || :type


evaluare expresii
2 == 3
2 / 3
2 `div` 3
True
False
True && False
not (True || False)
"ana " ++ "are " ++ "mere"
321312412312314*321731273127312
div 2 4 == 2 `div` 4

prefixat
2
(+) 2 3 == 2 + 3
(2 + 3) * 5 == (*) ((+ 2 3 ) 5

Num p->variabilă de tipuri, baza tipurilor numerice
(<=) :: Ord a => a -> a -> Bool

f(2) -->> f 2 !!!!
succ 'a' <= pred 'c'
succ (pred (succ (succ 17)))

//curs 2
Tipuri de date algebrice -> algebră a tipurilor
-operația produs
-operația sumă disjunctă

Operația produs.
-definim un tip de date algebric
data pair = pereche int bool---argumentele constructorului (int și bool)
------|-------|
------|-------|
------|---constructor
----|
----numele tipului
ex1 :: Pair
ex1 = Pereche 10 True
first :: Pair -> Int
first (Pereche x y) = x
second :: Pair -> Bool
second (Pereche  x y)=y
data Singleton = Bla Int
extract::Singleton->Int
extract (Bla x) = x
variabile, funcții - literă mică
constructor, type, clasă de tipuri - literă mare
deriving Show -> forțează tipul să facă parte din clasa Show - stringuri,
construct :: Int -> Bool -> Pair
construct x y = Pereche x y
dist :: Viteza -> Timp -> Distanta
dist (V speed) (T time) = D(speed * time)
data Unit = Unit
f1 :: Unit -> Int
f1 U = 42

Operația sumă disjunctă
data Cerc = C Float
data Dreptunghi = Dr Float Float
ariaCerc :: Cerc -> Float
ariaCerc (C x) = 3.14*x*x
ariaDreptunghi :: Dreptunghi -> Dreptunghi -> Float
ariaDreptunghi (Dr y z) = y * z
data Figura = C Float
            | Dr Float Float
aria :: Firgura -> Float
aria (C r) = 3.14*r*r*r
aria (Dr lung latime) = lung * latime
			

