module Main where
 
import Prelude hiding (Either(..))
import qualified Data.List as L
import Data.Maybe (mapMaybe)
import System.IO (getChar, hSetEcho, stdin)
 
type Coordonate = (Int,Int)
 
(|+|) :: Coordonate -> Coordonate -> Coordonate
(a,b) |+| (c,d) = (a+c, b+d)
 
data Miscari = Up | Down | Left | Right deriving (Show,Eq)
 
data Elemente = Elemente  {perete, lada, puncteX :: [Coordonate], jucator :: Coordonate, pasi  :: Int, gameOver :: [Coordonate]} deriving (Eq)
 
modPerete  f st = st{perete  = f . perete  $ st}
modLada    f st = st{lada    = f . lada    $ st}
modPunctX  f st = st{puncteX = f . puncteX $ st}
modJucator f st = st{jucator = f . jucator $ st}
modPas     f st = st{pasi = f . pasi $ st}
modGameOver f st = st{gameOver = f . gameOver $ st}
 
coodonatePentruMiscari :: Miscari -> Coordonate
coodonatePentruMiscari Up    = ( 0,-1)
coodonatePentruMiscari Down  = ( 0, 1)
coodonatePentruMiscari Left  = (-1, 0)
coodonatePentruMiscari Right = ( 1, 0)

--avand la dispozitie o stare si o mutare, trebuie sa ne dam seama in ce stare ajungem
pas :: Miscari -> Elemente -> Elemente
pas mutare stare 
  | estePerete next1 = stare
  | esteLada next1   =
      if estePerete next2 || esteLada next2 || esteGameOver next1
        then stare
        else modLada ((next2:) . (filter (next1/=))) mutaJucator
  | otherwise = mutaJucator
  where Elemente{perete = pt, lada = ld, jucator = jc, gameOver = gm} = stare
        coordonateMiscari = coodonatePentruMiscari mutare
        next1             = jc |+| coordonateMiscari
        next2             = next1  |+| coordonateMiscari
        esteLada          = (`elem` ld)
        estePerete        = (`elem` pt)
        esteGameOver      = (`elem` gm)
        mutaJucator       = modPas (+1) stare{jucator = next1}
 

desen :: Elemente -> [String]
desen stare@Elemente{perete = pt, lada = ld, puncteX = px, jucator = jc, pasi = ps} =
  show ps : [[charRep (x,y) | x <- [0..maxX]] | y <- [0..maxY]]
  where 
    maxX = maximum $ map fst pt
    maxY = maximum $ map snd pt
 
    charRep coord
      | esteJucator && estePunctX = '+'
      | esteLada  && estePunctX = '*'
      | esteJucator  = 'j'
      | esteLada = 'l'
      | estePunctX = 'x'
      | estePerete = '-'
      | estePerete && esteLada = '%'
      | otherwise = ' '
      where esteJucator  = coord == jc
            esteLada   = coord `elem` ld
            estePunctX = coord `elem` px
            estePerete    = coord `elem` pt
 
instance Show Elemente where
  show = unlines . desen
 
--reprezentare nivel
nivel :: [String] -> Elemente
nivel level = foldl celule instantiere $ (concat campuri)
  where campuri = map (\(y,xs) -> zipWith (\x c -> ((x,y),c)) [0..] xs) 
                    (zip [0..] level)
        celule st (coord,char) =            
          case char of
            '-' -> modPerete  (coord:) st
            'l' -> modLada    (coord:) st
            'x' -> modPunctX  (coord:) st
            '*' -> modPunctX  (coord:) . modLada (coord:)         $ st
            '%' -> modGameOver  (coord:) . modLada (coord:)         $ st
            '+' -> modPunctX  (coord:) . modJucator (const coord) $ st
            'j' -> modJucator (const coord) st
            otherwise -> st
 
instantiere = Elemente {perete = [], puncteX = [], lada = [], jucator = (0,0), pasi = 0, gameOver=[]}

--se verifica daca nivelul e gata atunci cand avem toate puncteleX cu lazi in ea
nivelTerminat :: Elemente -> Bool
nivelTerminat Elemente{lada = ld, puncteX = px} = L.sort px == L.sort ld

--input
loop st = do
  print st
  c <- getChar
  let mutare = case c of 
                'a' -> pas Left
                's' -> pas Down
                'd' -> pas Right
                'w' -> pas Up
                otherwise -> id
      st' = mutare st
  if nivelTerminat st' 
    then print st' >> print "Felicitari! Ati castigat!"
    else loop st'


main = do
  print "Pentru a juca folositi tastele w->sus, s->jos, a->stanga, d->dreapta"
  print "j -> jucator"
  print "l -> lada"
  print "x -> punctul unde se baga lada"
  print "- -> perete"
  print "% -> gameOver"
  hSetEcho stdin False
  loop $ nivel level_1
  hSetEcho stdin True
level_1 = [
  "---------",
  "-       -",
  "-    j lx---",
  "-  ll    xx-",
  "-      ---",
  "---------"
  ]