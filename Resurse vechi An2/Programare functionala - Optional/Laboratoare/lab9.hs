{--
tipuri de variabile Bool,Char,Int limitat 32/64(reprezentate intern),Integer nelimitat,Float,Double
liste [Int]
tuple (Bool,Int)
fst::(a,b)->a   a,b pot sa fie diferite, tipul a sa fie acelasi return are acelasi tip ca variabila de pe pozitia initiala
(==)::Eq a=>a a->a->Bool //Eq - clasa 
(<)::Ord a=>a->a>Bool //Ord clasa tipurilor care sunt membrii clasei Eq si operatori < > >= <=

abs
Show
show::(Show a)=>a->String

Read 
read  ex  1+read "123"
||::Bool->Bool->Bool

Enum
succ
pred

[1..10] [1,2,3,4,5,6,7,8,9,10]

Num

Floating|Integral
Float   |Int
Double  |Integer

1::Int+2.3   fortam 1 sa fie integer

length::[a]->Int

(length [1])+3.2
fromIntegral::(Integral a,Num b)->a->b

Bounded
minBound::(Bounded a)=>a
maxBound

minBound::Int

data Bool=True|False
--}

data BoolRo=Adevarat|Fals deriving Show --nu e instanta la Show try >Adevarat 
data Zi = Luni|Marti|Miercuri|Joi|Vineri|Sambata|Duminica deriving (Show,Enum)

data Figura = Cerc Float Float Float | Dreptunghi Float Float Float Float deriving Show  -- cerc dreptunghi constructori pt figura

-- :t Cerc::Float a->Float a ->Float a->Figura
-- Cerc 0 0 3
{-
aria::Figura->Float
aria (Cerc _ _ raza)=pi*raza^2 
aria (Dreptunghi x1,y1,x2,y2)=abs(x1-x2)*abs(y1-y2)
-}
{-
data Punct=Punct Float Float deriving Show --acelasi nume e ok ;)

data Figura'= Cerc' Punct Float | Dreptunghi' Punct Punct deriving Show
aria'::Figura'->Float
aria' (Cerc' _ r)=pi*r^2
aria' (Dreptunghi' (Punct x1 y1) (Punct x2 y2) )=abs(x1-x2)*abs(y1-y2) 

--getCercuri = map (Cerc (Punct 0 0) ) [1..10]
-}
data Box a = Empty | Full a deriving Show
shead ::[a]->Box a
shead [] = Empty
shead (x:_)= Full x