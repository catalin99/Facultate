class Pretty a where
    prettyPrint :: a -> String
    {-# MINIMAL prettyPrint #-}

class MyNum a where
    toInt :: a -> Int

data Nat = Zero | Succ Nat

instance Ord Nat where 
    Zero <= Zero = True
    Zero <= Succ _ = True
    Succ _ <= Zero = False
    Succ x <= Succ y = x <=y

instance MyNum Nat where 
    toInt Zero = 0
    toInt (Succ x) = 1 + (toInt x)

instance Num Nat where
    (+) Zero Zero = Zero
    (+) Zero n = n
    (+) n Zero = n
    (+) (Succ m) n = Succ ((+) m n)

    (*) Zero n = Zero
    (*) (Succ Zero) n = n
    (*) (Succ m) n = (+) n ((*) m n)

    abs x = x

    signum x = (Succ Zero)

    fromInteger 0 = Zero
    fromInteger x = Succ (fromInteger x)

    negate x = Zero

instance Eq Nat where 
    Zero == Zero = True
    Succ _ == Zero = False
    Zero == Succ _ = False
    Succ x == Succ y = x == y

instance Pretty Nat where
    prettyPrint Zero = "0"
    prettyPrint (Succ x) = "S (" ++ prettyPrint x ++ ")"



data Arb a = Node a (Arb a) (Arb a)
            | Empty

instance (Show a) => Show (Arb a) where
    show Empty = "(" ++ ")"
    show (Node x left right) = "(" ++ show(x)  ++ (show left) ++ (show right) ++ ")" ++ ")"


instance (Eq a) => Eq (Arb a) where
    Empty == Empty = True
    Empty == _ = False
    _ == Empty = False
    t1@(Node x left1 right1) == t2@(Node y left2 right2) = if x /= y then False
                                                        else left1==left2 && right1==right2

instance (Show a) => (Pretty (Arb a)) where
    prettyPrint Empty = "(" ++ ")"
    prettyPrint (Node x left right) = "(" ++ show(x)  ++ (prettyPrint left) ++ (prettyPrint right) ++ ")" ++ ")"


data List a = Nil | Cons a (List a)

instance (Eq a) => Eq (List a) where
    Nil == Nil = True
    Nil == _ = False
    _ == Nil = False
    (Cons hd1 tl1) == (Cons hd2 tl2) = if hd1/=hd2 then False
                            else tl1==tl2


    
bst :: Arb Int
bst = (Node 5 (Node 3 (Node 2 Empty Empty) (Node 4 Empty Empty))  (Node 9 Empty Empty))


