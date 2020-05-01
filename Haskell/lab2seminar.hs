data MobileDevice1 = Smartphone1 --Value constructors
                  | Laptop1 
                  | Tablet1 Int String
                  deriving (Show)

descriere :: MobileDevice1 -> String
--pattern matching
descriere Smartphone1 = "telefon"
descriere Laptop1 = "laptop"
descriere (Tablet1 _ y) = "tableta " ++y --daca nu ne intereseaza cine sunt x si y punem _ in loc de variabila

data MobileDevice = Smartphone Culori
                  | Laptop Culori
                  | Tablet Culori
                   deriving (Show)

data Culori = Albastru 
            | Rosu
            | Verde 
            | Mov 
            deriving (Show)

functieCulori :: MobileDevice -> String
functieCulori (Smartphone c) = "telefon " ++ (show c)
functieCulori (Laptop c) = "laptop " ++ (show c)
functieCulori (Tablet c) = "tableta " ++ (show c)

data Nat = Zero
         | Succ Nat
         deriving (Show)

adunare :: Nat -> Nat -> Nat 
adunare Zero x = x
adunare (Succ y ) x = Succ (adunare y x)

inmultire :: Nat -> Nat -> Nat
inmultire Zero x = Zero
inmultire x y = inmultire (Succ x) (Succ y)

data ErrorNat = Error
              | Val Nat
               deriving (Show)

scadere :: ErrorNat -> ErrorNat -> ErrorNat
scadere Error _ = Error
scadere _ Error = Error
scadere (Val Zero) (Val Zero)= (Val Zero)
scadere (Val Zero) (Val (Succ _))= Error
scadere (Val (Succ x)) (Val Zero) = (Val(Succ x))
--scadere (Val (Succ x)) (Val (Succ y))= (scadere x y)

sub :: Nat -> Nat -> ErrorNat
sub x y = scadere (Val x) (Val y)


--
   -- getNat :: ErrorNat -> Nat
  --  getNat Error = Zero
 --   getNat (Val x) = x
    
 --   div :: ErrorNat -> ErrorNat ->ErrorNat
 --   div Error _ = Error
 --   div _ Error = Error
 --   div (Val x) (Val y) =..
--


desc :: Nat ->String
desc x = case x of 
    Zero -> "Acesta este zero"
    (Succ z) -> "Acesta nu este zero"

data BinTree = Left Int BinTree --Not Int BinTree BinTree
             | Right Int BinTree --Empty
             deriving (Show)


data List = Null
          | Next Int List
           deriving (Show)

cauta :: List -> Int -> Bool
cauta Null x = False
cauta (Next x t) y = if x == y then True else cauta t y 

adaugaFin :: List -> List -> List
adaugaFin Null lista = lista
adaugaFin (Next a b) lista = Next a (adaugaFin b lista)

adaugaInc :: List -> List -> List
adaugaInc Null lista = lista
adaugaInc lista (Next a b) = Next a (adaugaInc b lista)

adaugaPoz :: List -> List -> Int -> List
adaugaPoz lista1 lista2 0 = adaugaInc lista1 lista2 

concatLists :: List -> List -> List
concatLists l1 l2 = adaugaFin l1 l2

