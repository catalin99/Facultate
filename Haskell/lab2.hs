--data MobileDevice = Smartphone --Value constructors
  --                | Laptop
    --              | Tablet Int String
      --            deriving (Show)
 
--descriere :: MobileDevice -> String
--pattern matching
--descriere (Smartphone ) = "telefon"
--descriere (Laptop ) = "laptop"
--descriere (Tablet _ y) = "tableta " ++y -- daca nu ne intereseaza cine sunt x si y punem _ in loc de variabila

data MobileDeviceColoured = Smartphone Culori--Value constructors
                  | Laptop Culori
                  | Tablet Culori
                  deriving (Show)

data Culori = Red
            | Black
            | Blue
            deriving (Show)

color :: MobileDeviceColoured -> String
color (Smartphone c) = "telefon " ++ (show c)
color (Laptop c) = "laptop " ++ (show c)
color (Tablet c) = "tableta " ++ (show c)

data Nat = Zero
         | Succ Nat
         deriving (Show)

add :: Nat -> Nat -> Nat
add Zero n = n
add (Succ m) n = Succ (add m n)

mul :: Nat -> Nat -> Nat
mul Zero n = Zero
mul (Succ m) n = 