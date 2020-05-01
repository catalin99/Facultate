import Data.Char
import System.IO

main :: IO ()
main = do
        hSetBuffering stdout NoBuffering
        putStr "Input: "
        string <- getLine 
        putStrLn (map toUpper string)
        main