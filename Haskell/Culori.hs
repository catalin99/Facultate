data Culori = Albastru
            | Verde
            | Rosu
            | Mov
            deriving (Show)

data MobileDevice = Smartphone Culori
                  | Laptop Culori
                  | Tablet Culori
                  deriving (Show)

culoare::MobileDevice -> String
culoare (Smartphone x) = "Acesta este un telefon de culoare " ++ (show x)
culoare (Laptop x) = "Acesta este un laptop de culoare " ++ (show x)
culoare (Tablet x) = "Aceasta este o tableta de culoare " ++ (show x)

data Nat = Zero
         | Succ Nat
         deriving (Show)

data ErrorNat = Error
              | Val Nat
              deriving(Show)

adun::Nat->Nat->Nat
adun Zero n = n
adun (Succ m) n = Succ(adun m n)

mult::Nat->Nat->Nat
mult Zero n = Zero
mult (Succ m) n = adun n (mult m n)

minus:: ErrorNat->ErrorNat->ErrorNat 
minus (Val Zero) (Val Zero) = Val Zero
minus (Val Zero) (Val n) = Error
minus (Val n) (Val Zero) = Val n
minus (Val (Succ n)) (Val (Succ m)) = minus (Val n) (Val m)

impart::ErrorNat->ErrorNat->ErrorNat
impart (Val n) (Val Zero) = Error
impart (Val Zero) (Val n) = Val Zero
impart (Val (Succ m)) (Val n) = minus (Val n) (impart (Val m) (Val n))
