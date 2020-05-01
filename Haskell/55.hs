-- data Nat = Succ Nat
--          | Zero
--          deriving (Show, Eq)

-- instance Ord Nat where
--          Zero <= _ = True
--          Succ _ <= Zero = False
--          Succ x <= Succ y = x <=y

data Nat = Zero
         | Succ Nat

instance Show Nat where
    show Zero = "o"
    show (Succ x) = "s"

data Arb a = Leaf
    | Node a (Arb a) (Arb a)

instance (Show a) => Show (Arb a) where
    