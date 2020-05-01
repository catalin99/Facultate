class MyEq a where
    (===) :: a -> a -> Bool
    (=/=) :: a -> a -> Bool
	
data Shape = Triangle | Circle

instance MyEq Shape where
    Triangle === Triangle = True
    Circle === Circle = True
    _ === _ = False
    x =/= y = not (x === y)

class Comparable a where
  lt, le, gt, ge :: a -> a -> Bool

instance Comparable Shape where
  lt Triangle Circle = True
  lt _ _ = False
  le Circle Triangle = False
  le _ _ = True
  gt x y = not (le x y)
  ge x y = not (lt x y)
