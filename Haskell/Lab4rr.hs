nth :: (Int, Int, Int, Int) -> Int -> Int
nth (a, b, c, d) poz = case poz of 0 -> a
                                   1 -> b
                                   2 -> c
                                   3 -> d
                                   _ -> -1

addThree :: (Int, Int, Int) -> Int
addThree (x,y,z) = x + y + z

addThreeCurried :: Int -> Int -> Int -> Int
addThreeCurried x y z = x + y + z

process :: (a -> a) -> a -> a
process f x = f x

sumaInterval :: (Int -> Int) -> Int -> Int -> Int
sumaInterval f a b = if (a>b) then 0
                    else (f a) + sumaInterval f (a+1) b

compunere :: (a -> b) -> (b -> c) -> a -> c
compunere f g x = g(f(x))

listaCompunere::[a->a]->a->a
listaCompunere [] x = x
listaCompunere (f:t) x = f (listaCompunere t x)

sumaLista::[Int]->Int
sumaLista [] = 0
sumaLista (x:tl) = x + sumaLista(tl) 

--3.5

allElem::(a->b)->[a]->[b]
allElem _ [] = []
allElem f (hd:tl) = ((f hd) : (allElem f tl))

--3.6

filterElem::[a]->(a->Bool)->[a]
filterElem [] f = []
filterElem (hd:tl) f = if (f hd == True)
                        then [hd] ++ filterElem tl f
                        else filterElem tl f

--3.7

foldleft::(a->b->a)->a->[b]->a
foldleft f x (hd:[]) = f x hd
foldleft f x (hd:tl) = foldleft f x tl 


sumaEx1 :: (Int->Int) -> Int -> Int -> Int
sumaEx1 f a b = if a > b then 0
                else a + sumaEx1 f (a+1 ) b


compunereEx2 :: (a -> b) -> (b->c) -> a -> c
compunereEx2 f g x = g (f (x))

compunereListaEx3 :: [a -> a] -> a -> a
compunereListaEx3 [] x = x
compunereListaEx3 (f:s) x = f (compunereListaEx3 s x)

sumaListaEx4 :: [Int] -> Int
sumaListaEx4 [] = 0
sumaListaEx4 (f:l) = f + (sumaListaEx4 l)

aplicaTuturorEx5 :: (a -> a) -> [a] -> [a]
aplicaTuturorEx5 _ [] = []
-- aplicaTuturorEx5 f (a1:b1) = ((f a1) : (aplicaTuturorEx5 f b1))
aplicaTuturorEx5 f (hd:tl) = [(f hd)] ++ (aplicaTuturorEx5 f tl)

listaTrueEx6 :: (a->Bool) -> [a] -> [a]
listaTrueEx6 _ [] = []
listaTrueEx6 f (a:b) = if ((f a) == True) then ([a] ++ (listaTrueEx6 f b))
                       else listaTrueEx6 f b
                    
foldrEx7 :: (a -> b -> b) -> b -> [a] -> b
foldrEx7 f x (a:[]) = f a x
foldrEx7 f x (a:b) = (f a (foldrEx7 f x b))

foldlEx7 :: (a -> b -> a) -> a -> [b] -> a
foldlEx7 f x (a:[]) = f x a
foldlEx7 f x (a:b) = (foldlEx7 f (f x a) b)

 
data ArbBin = Frunza Int
            | Nod Int ArbBin ArbBin
            deriving (Show)

preordine :: (Int->Int) -> ArbBin -> ArbBin
preordine f (Frunza x) = Frunza (f x)
preordine f (Nod x st dr) = Nod (f x) (preordine f st) (preordine f dr)

-- inordine :: (Int -> Int) -> ArbBin -> ArbBin
-- inordine f (Frunza x) = Frunza (f x)
-- inordine f (Nod x st dr) = (inordine f st) Nod (f x) (inordine f dr)

-- postordine :: (Int -> Int) -> ArbBin -> ArbBin
-- postordine f (Frunza x) = Frunza (f x)
-- postordine f (Nod x st dr) = (postordine f st) (postordine f dr) Nod (f x)