main :: IO ()
main =  (putStrLn "What is your name?") >>
        (getLine >>=
            (\firstName -> (putStrLn "What is your last name?") >>
            (getLine >>= 
                (\lastName -> (putStrLn ("Hello, " ++ firstName ++ " " ++ lastName ++ "!" )))))) >>
        main