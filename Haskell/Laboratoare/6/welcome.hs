main :: IO ()
main = do
        putStrLn "Enter your first name:"
        firstName <- getLine 
        putStrLn "Enter your last name:" 
        lastName <- getLine
        putStrLn("Hello " ++ firstName ++ " " ++ lastName ++ " !")