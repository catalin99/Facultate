data MyNat = O | S MyNat deriving Show

add :: MyNat -> MyNat -> MyNat
add O x = x
add (S x) y = S (add x y)

multiply :: MyNat -> MyNat -> MyNat
multiply O x = O
multiply (S x) y = add y (multiply x y)

--data Player = Player String String Float Float Int deriving Show

data Player = Player {
                name :: String,
                team :: String,
                height :: Float,
                weight :: Float,
                age :: Int }
            deriving Show

data Option a = None | Some a deriving Show

elementAt :: Int -> [a] -> a
elementAt i l
  | (i < 0) || i >= (length l) = error "Index out of bounds."
elementAt 0 (x:_) = x
elementAt i (_:xs) = elementAt (i-1) xs


elementAt' :: Int -> [a] -> Option a
elementAt' i l
  | (i < 0) || i >= (length l) = None
elementAt' 0 (x:_) = Some x
elementAt' i (_:xs) = elementAt' (i-1) xs

data MyList a = NULL | Cons a (MyList a) deriving Show

len :: MyList a  -> Int
len NULL = 0
len (Cons x xs) = 1 + len xs

data listConc a = NULL | Cons a (listConc a) deriving Show

listConcat :: listConc -> [a] -> [a]
listConcat x NULL = x
listConcat (Cons x xs) = x ++ listConc xs
