import System.IO
import System.Environment
import Data.Char

main :: IO ()
main = do
        args <- getArgs
        if args == [] then do
            progName <- getProgName
            putStrLn (progName ++ " <filename>")
            return ()
        else do
            handle <- openFile (head args) ReadMode
            content <- hGetContents handle
            putStrLn (map toUpper content)
            hClose handle