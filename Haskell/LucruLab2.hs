data ErrorList = Error
               | Rez Int
               deriving(Show)

data Lista = Vida
            |Elem Int Lista
            deriving(Show)

cautare::Lista->Int->Int->Int
cautare Vida x y = -1
cautare (Elem a t) x y = if a==x
                       then
                          y
                       else 
                          cautare t x (y+1)   

cautareaBuna::Lista->Int->Int
cautareaBuna (Elem a t) x = cautare (Elem a t) x 0

adaugare::Lista->Int->Lista
adaugare Vida x = Elem x Vida
adaugare (Elem a t) x = Elem a (adaugare t x)

adaugareStart::Lista->Int->Lista
adaugareStart Vida x = Elem x Vida
adaugareStart (Elem a t) x = Elem x (Elem a t)

afisareLista::Lista->[Int]
afisareLista Vida = []
afisareLista (Elem a t) = [a] ++ afisareLista t

adaugareMijloc::Lista->Int->Int->Lista
adaugareMijloc Vida x y = if y>0
                                then
                                  Vida
                                else 
                                  Elem x Vida
adaugareMijloc (Elem a t) x y = if y==0
                                      then 
                                        Elem x (Elem a t)
                                      else Elem a (adaugareMijloc t x (y-1))                                         

maximList::Lista->Int->ErrorList
maximList Vida m = Error
maximList (Elem a Vida) m = if a>m
                             then Rez a
                            else Rez m
maximList (Elem a t) m = if a>m
                           then maximList t a
                         else maximList t m

maxim::Lista->ErrorList
maxim t = maximList t (-100000000)

minimList::Lista->Int->ErrorList
minimList Vida m = Error
minimList (Elem a Vida) m = if a<m
                             then Rez a
                            else Rez m
minimList (Elem a t) m = if a<m
                           then minimList t a
                         else minimList t m

minim::Lista->ErrorList
minim t = minimList t (100000000)

maximUnParam::Lista->Int
maximUnParam Vida = 0
maximUnParam (Elem a Vida) = a
maximUnParam (Elem a t) = if a > (maximUnParam t)
                            then a 
                          else maximUnParam t 

concaten::Lista->Lista->Lista
concaten Vida Vida = Vida
concaten (Elem a t) Vida = Elem a t
concaten Vida (Elem a t) = Elem a t
concaten (Elem a t) (Elem b l) = Elem a (concaten t (Elem b l))





--data Arb = Fr Int 
--         | Nod Int Arb Arb
--         deriving(Show)

--checkSt::Int->Arb->Bool
--checkSt a (Fr b) = if a<=b 
--                    then False
--                   else True 
--checkSt a (Nod b ar1 ar2) = if a<=b
--                             then False
--                            else True

--checkDr::Int->Arb->Bool
--checkDr a (Fr b) = if a>=b 
--                    then False
--                   else True 
--checkDr a (Nod b ar1 ar2) = if a>=b
--                              then False
--                            else True
                          
--binCautare::Arb->Bool
--binCautare (Fr a) = True
--binCautare (Nod a ar1 ar2) = if (checkSt a ar1 == False)
--                               then False
--                             else if (checkDr a ar2 == False)
--                                   then False
--                                  else (binCautare ar1) && (binCautare ar2) 

--cautaInBin::Arb->Int->Bool
--cautaInBin (Fr a) x = if a==x
--                        then True
--                      else False
--cautaInBin (Nod a ar1 ar2) x = if (x==a)
--                                 then True
--                               else if (x>a)
--                                      then cautaInBin ar2 x
--                                    else cautaInBin ar1 x       
                                    
                                    



--data Nat = Zero
--         | Succ Nat
--         deriving (Show)

--data ErrorNat = ErrorNr
--              | Val Nat
--              deriving(Show)

--adun::Nat->Nat->Nat
--adun Zero n = n
--adun (Succ m) n = Succ(adun m n)

--mult::Nat->Nat->Nat
--mult Zero n = Zero
--mult (Succ m) n = adun n (mult m n)

--minus:: ErrorNat->ErrorNat->ErrorNat 
--minus (Val Zero) (Val Zero) = Val Zero
--minus (Val Zero) (Val n) = ErrorNr
--minus (Val n) (Val Zero) = Val n
--minus (Val (Succ n)) (Val (Succ m)) = minus (Val n) (Val m)

 