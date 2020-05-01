main :: IO ()
main = do
        putStrLn "What is your name?"
        name <- getLine
        if name == "" then
            return ()
        else do
            putStrLn "What is your last name?"
            lastName <- getLine
            if lastName == "" then do
                return ()
            else do
                putStrLn ("Hello, " ++ name ++ "!")
                main
