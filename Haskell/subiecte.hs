powers :: Int -> Int -> [Int]
powers x 0 = [1]
powers x l = (powers x (l-1)) ++ [x^l]

nrElem :: [Int] -> Int
nrElem [] = 0
nrElem (hd:tl) = 1 + nrElem tl

insertAtPoz :: [Int] -> Int -> Int -> [Int]
-- insertAtPoz [h] x 0 = 
insertAtPoz (hd:tl) x poz = if (poz==0) then [x] ++ [hd] ++ tl else [hd] ++ (insertAtPoz tl x (poz-1)) 

insert :: Int -> [Int] -> [Int]
insert x [] = [x]
insert x l = insertAtPoz l x ((nrElem l) `div` 2)

afisareDiv3 :: [Int] -> [Int]
afisareDiv3 [] = []
afisareDiv3 (hd:tl) = if ((hd `mod` 3)==0) then [hd] ++ (afisareDiv3 tl) else afisareDiv3 tl

-- aplicaFunct :: (a -> b -> b) -> b -> [a] -> [b]
-- aplicaFunct f x [] = []
-- aplicaFunct f x (hd:tl) = if ((f hd x)==True) then [hd] ++ (aplicaFunct f x tl) else aplicaFunct f x tl

concat143 :: [Int] -> [Int] -> [Int]
concat143 [] [] = []
concat143 l l2 = l ++ l2 

reverse' :: [Int] -> [Int]
reverse' [] = []
reverse' (hd:tl) = reverse' tl ++ [hd] 