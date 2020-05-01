addThree::Int->Int->Int->Int
addThree x y z = x + y + z

--3.1

interval:: (Int->Int)->Int->Int->Int
interval f a b = if a > b
                 then 0
                 else (f a) + interval f (a+1) b 

--3.2

compunere::(a->b)->(b->c)->a->c
compunere f g x = (g (f x)) 

-- (.) compune 2 functii

--3.3

listaCompunere::[a->a]->a->a
listaCompunere [] x = x
listaCompunere (f:tl) x = f (listaCompunere tl x)

--3.4

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