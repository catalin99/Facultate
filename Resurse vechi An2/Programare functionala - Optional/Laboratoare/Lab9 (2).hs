--nada

--succ
--pred
--fromIntegral
--minBound
--maxBound

data Bool' = Adev|Fals deriving Show

data Zi = Lu|Ma|Mi|Jo|Vi|Sa|Du deriving (Show,Enum)

data Fig = Cerc Float Float Float|Drept Float Float Float Float deriving Show

aria::Fig->Float

aria (Cerc _ _ r) = pi * r^2

aria (Drept x1 y1 x2 y2) = abs( x1 - x2 ) * abs( y1 - y2 )

data Punct = Punct Float Float deriving Show

data Fig' = Cerc' Punct Float|Drept' Punct Punct deriving Show

aria'::Fig'->Float

aria' (Cerc' _ r) = pi * r^2

aria' (Drept' (Punct x1 y1) (Punct x2 y2)) = abs(x1-x2) * abs(y1-y2)

f = map (Cerc' (Punct 0 0))

data Box a = Empty|Full a deriving Show

shead::[a]->Box a
shead [] = Empty
shead (x:_) = Full x