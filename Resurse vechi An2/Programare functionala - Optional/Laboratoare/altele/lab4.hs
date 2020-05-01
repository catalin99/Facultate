module Caesar
( encrypt
, decrypt
) where

import Data.Char
encrypt :: (Integral a) => a -> String -> String
encrypt k = map f
    where f x = case generalCategory x of
              LowercaseLetter -> addChar 'a' k x
              UppercaseLetter -> addChar 'A' k x
              _               -> x
decrypt :: (Integral a) => a -> String -> String
decrypt k = encrypt (-k)

addChar :: (Integral a) => Char -> a -> Char -> Char
addChar b o c = chr $ fromIntegral (b' + (c' - b' + o) `mod` 26)
    where b' = fromIntegral $ ord b
          c' = fromIntegral $ ord c