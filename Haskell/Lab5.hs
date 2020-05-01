data Nat = Zero
         | Succ Nat

--instance Ord Nat where
--Zero <= _ = True
--Succ _ <= Zero = False
--Succ x <= Succ y = x <= y

instance Show Nat where
    show Zero = "o"
    show (Succ x) = "s " ++ show x

--data Arb = Fr Int 
--         | Nod Int Arb Arb

--instance Show Arb where
--    show (Fr x) = "(" ++ show x ++ "()())"
--    show (Nod x a1 a2) = "(" ++ show x ++ show a1 ++ show a2 ++ ")"  

instance Eq Nat where
    (==) Zero Zero = True
    (==) (Succ x) (Succ y) = (==) x y
    (==) x Zero = False
    (==) Zero x = False

    

data Arb a = Leaf
           | Node a (Arb a) (Arb a)
          
instance (Show a) => Show (Arb a) where
    show Leaf = "()"
    show (Node x a1 a2) = "(" ++ show x ++ show a1 ++ show a2 ++ ")"

instance (Eq a) => Eq (Arb a) where
    (==) Leaf Leaf = True
    (==) Leaf (Node x a1 a2) = False
    (==) (Node x a1 a2) Leaf = False
    (==) (Node x a1 a2) (Node y a3 a4) = ((==) x y) && ((==) a1 a3) && ((==) a2 a4) 

class Pretty a where
    prettyPrint::a->String
     
instance Pretty Nat where
    prettyPrint Zero = "Zero" 
    prettyPrint (Succ x) = "Succ " ++ prettyPrint x

instance (Show a) => Pretty (Arb a) where
    prettyPrint Leaf = "()"    
    prettyPrint (Node x a1 a2) = "(" ++ show x ++ prettyPrint a1 ++ prettyPrint a2 ++ ")" 

class MyNum a where
    toInt :: a->Int 
    
instance MyNum Nat where
    toInt Zero = 0
    toInt (Succ x) = 1 + toInt x    

data List a = Nil 
            | Cons a (List a) 
            
instance (Eq a) => Eq (List a) where
    (==) Nil Nil = True
    (==) Nil (Cons x t) = False
    (==) (Cons x t) Nil = False 
    (==) (Cons x t) (Cons h l) = ((==) x h) && ((==) t l)      
    
-- instance Num Nat where 
--     (+) Zero n = n
--     (+) (Succ m) n = Succ((+) m n)
--     (*) Zero n = Zero
--     (*) (Succ m) n = (+) n ((*) m n) 
--     (-) Zero Zero = Zero
--     (-) n Zero = n
--     (-) (Succ n) (Succ m) = (-) n m  
--     (abs) Zero = Zero
--     (abs) (Succ x) = Succ x
--     (signum) (Succ x) = Succ x
 