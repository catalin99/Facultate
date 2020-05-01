-- data MobileDevice = Smartphone
--                   | Laptop
--                   | Tablet Int String
--                   deriving (Show)

data Color = White
            | Black
            | Green
            | Yellow
            deriving (Show)

data Tip1 a = Aux1 
            | Aux2 a

data Tip2 = Aux3 (Tip1 Bool)
           | Aux4
data MobileDevice = Smartphone Color
                   | Laptop Color
                   | Tablet Color
                   deriving (Show)

descriere :: MobileDevice -> String
descriere (Laptop White) = "Acesta este un laptop de culoare albă"


showColor :: MobileDevice -> Color
showColor (Smartphone c) = c
showColor (Laptop c) = c
showColor (Tablet c) = c

data Nat = Zero
         | Succ Nat
         deriving (Show)

adunare :: Nat -> Nat -> Nat
adunare Zero x = x
adunare (Succ x) y = Succ (adunare x y) 

inmultire :: Nat -> Nat -> Nat
inmultire Zero x = Zero
inmultire (Succ x) y = adunare y (inmultire x y)

data ErrorNat = Error
              | Val Nat
              deriving (Show)

scadere :: ErrorNat -> ErrorNat -> ErrorNat
scadere Error _ = Error
scadere _ Error = Error
scadere (Val Zero) (Val Zero) = (Val Zero)
scadere (Val Zero) (Val (Succ _)) = Error
scadere (Val (Succ x)) (Val Zero) = Val (Succ x)
scadere (Val (Succ x)) (Val (Succ y)) = scadere (Val x) (Val y)

impartire :: ErrorNat -> ErrorNat -> ErrorNat
impartire Error _ = Error
impartire _ Error = Error
impartire (Val (Succ _)) (Val Zero) = Error
impartire (Val Zero) (Val (Succ _)) = (Val Zero)
impartire (Val (Succ x)) (Val (Succ y)) = scadere (Val (Succ x)) (impartire (Val x) (Val y))

-- impartire :: ErrorNat -> ErrorNat -> ErrorNat
-- impartire (Val Zero) (Val Zero) = Error;                                -- Cazul 0/0, caz de nedeterminare                        
-- impartire _ Error = Error;                                                                                                      
-- impartire Error _ = Error;
-- impartire (Val Zero) (Val x) = Val Zero;                                                        -- Cazul 0/x, eroare
-- impartire (Val x) (Val Zero) = Error;                                                           -- Cazul x/0, eroare
-- impartire (Val (Succ x)) (Val (Succ y)) = scadere (Val x) (impartire (Val x) (Val y));       -- Cazul x/y, prin scaderi

data ArbBin = Frunza Int
            | Nod Int ArbBin ArbBin
            deriving (Show)

searchSt :: ArbBin -> Int -> Bool
searchSt (Frunza x) y = if (x<=y) then True else False
searchSt (Nod x s t) y = if (x<=y) then True else False

searchDr :: ArbBin -> Int -> Bool
searchDr (Frunza x) y = if(x>=y) then True else False
searchDr (Nod x s t) y = if(x>=y) then True else False

binarySearchTree :: ArbBin -> Bool
binarySearchTree (Frunza x) = True
binarySearchTree (Nod x z t) = if (searchSt z x == False) then False
                               else if (searchDr t x == False) then False
                               else (binarySearchTree z) && (binarySearchTree t)

data List = Null
          | Elem Int List
          deriving (Show)

cautaVal :: List -> Int -> Bool
cautaVal Null x = False
cautaVal (Elem z l) x= if (z==x) then True
                       else cautaVal l x

addFinal :: List -> Int -> List
addFinal Null x = Elem x Null
addFinal (Elem y l) x = Elem y (Elem x l)

addStart :: List -> Int -> List
addStart Null x = Elem x Null
addStart (Elem y l) x = Elem x (Elem y l)

addPoz :: List -> Int -> Int -> List
addPoz Null x y = if (y<=0) then Null else Elem x Null
addPoz (Elem t l) x y = if (y == 0) then Elem x (Elem t l) else Elem t (addPoz l x (y-1))

maxim :: List -> Int
maxim Null = 0
maxim (Elem a Null) = a
maxim (Elem a l) = if (a > maxim l) then a
                   else maxim l

minim :: List -> Int
minim Null = 0
minim (Elem a Null) = a
minim (Elem a l) = if (a < minim l) then a
                    else minim l

concatt :: List -> List -> List
concatt (Elem a l) Null = Elem a l
concatt Null (Elem a l) = Elem a l
concatt (Elem a l) (Elem b z) = Elem a (concatt l (Elem b z))

