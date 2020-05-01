data Nat = Zero
         | Succ Nat
        --  deriving (Show)

instance Show Nat where
    show Zero = "z"
    show (Succ x) = "s " ++ show x

instance Eq Nat where
    (==) Zero Zero = True
    (==) Zero _ = False
    (==) _ Zero = False
    (==) (Succ x) (Succ y) = if (x==y) then True else False

instance Ord Nat where
    (<=) Zero Zero = True
    (<=) Zero (Succ _) = True
    (<=) (Succ _) Zero = False
    (<=) (Succ x) (Succ y) = if (x<=y) then True else False

data Arb a = Leaf
           | Node a (Arb a) (Arb a)

instance (Show a) => Show (Arb a) where
    show Leaf = "()"
    show (Node x a b) = "(" ++ show x ++ show a ++ show b ++ ")"

instance (Eq a) => Eq (Arb a) where
    (==) Leaf Leaf = True
    (==) Leaf (Node x a b) = False
    (==) (Node x a b) Leaf = False
    (==) (Node x a b) (Node y c d) = ((==) x y) && ((==) a c) && ((==) b d)



class Pretty a where
    prettyPrint :: a -> String

instance Pretty Nat where
    prettyPrint Zero = "Zero"
    prettyPrint (Succ x) = "Succ " ++ prettyPrint x

instance (Show a) => Pretty (Arb a) where
    prettyPrint Leaf = "Leaf "
    prettyPrint (Node x a b) = "( " ++ show x ++ " " ++ prettyPrint a ++ prettyPrint b ++ ") "

class MyNum a where
    toInt :: a -> Int

instance MyNum Nat where
    toInt Zero = 0
    toInt (Succ x) = 1 + toInt x

-- instance Num Nat where
--     (+) Zero x = x
--     (+) (Succ x) y = Succ (y + x)
--     (-) x Zero = x
--     (-) (Succ x) y = Succ (x - y)

count :: Char -> [Char] -> Int
count x [] = 0
count x (hd:tl) = if (hd==x) then 1 + (count x tl) else count x tl

-- dup1Contor :: [a] -> Int -> Bool 


-- dup1 :: [a] -> [a]
-- dup1 [] = []
-- dup1 (hd:tl) = [hd] ++ [hd] ++ dup1 tl
