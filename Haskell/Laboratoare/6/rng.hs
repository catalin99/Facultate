import System.IO
import System.Environment

-- greated then middle element?
gtme :: [a] -> String -> Maybe [a]
gtme xs "Da" = Just (drop ((length xs) `div` 2) xs)
gtme xs "Nu" = Just (take ((length xs) `div` 2) xs)
gtme xs _ = Nothing

main :: Int ->  IO ()
main status = do
        secret <- getArgs
        let pool = [1..100]
        play
        -- putStrLn (head secret)
        return ()