import Data.Char;
import System.IO;
import System.Environment;

main01::IO()
main01 = putStrLn("Hello world!")

main02::IO()
main02 = (putStrLn ("Salut")) >>
           (putStrLn ("Ce faci?")) >> 
           (putStrLn ("Foarte bine"))

main03::IO()
main03 = (putStrLn "What is your first name?") >>
         (getLine >>=(\firstName -> (putStrLn("What is your last name?") >> 
         (getLine >>=(\lastName -> putStrLn ("Welcome, " ++ firstName ++ " " ++ lastName ++ "!"))))))

main04 :: IO ()
main04 = do
    putStrLn "What is your first name?"
    firstName <- getLine
    putStrLn "What is your last name?"
    lastName <- getLine 
    putStrLn ("Welcome, " ++ firstName ++ " " ++ lastName ++ "!")           
    
main05::IO()
main05 = (putStrLn "What is your first name?") >>
         (getLine >>=(\firstName -> (putStrLn("What is your last name?") >> 
         (getLine >>=(\lastName -> putStrLn ("Welcome, " ++ firstName ++ " " ++ lastName ++ "!")))))) >> main05

main06 :: IO ()
main06 = do
    putStrLn "What is your first name?"
    firstName <- getLine
    putStrLn "What is your last name?"
    lastName <- getLine 
    putStrLn ("Welcome, " ++ firstName ++ " " ++ lastName ++ "!") 
    main06

main07 :: IO ()
main07 = do
    putStrLn "What is your first name?"
    firstName <- getLine
    putStrLn "What is your last name?"
    lastName <- getLine 
    putStrLn ("Welcome, " ++ firstName ++ " " ++ lastName ++ "!")
    if lastName == "" && firstName == "" then
        return()
    else        
        main04

mapToUpper::[Char]->[Char]
mapToUpper (c:[]) = (toUpper(c):[])
mapToUpper (c:t) = (toUpper(c):mapToUpper(t))

main08::IO()
main08 = do
    result <- getLine
    putStrLn (mapToUpper result)

--09:
--openFile :: FilePath -> IOMode -> IO Handle         System.IO
--hGetContents :: Handle -> IO String                 System.IO
--hGetLine :: Handle -> IO String                     System.IO
--hClose :: Handle -> IO ()                           System.IO
--getArgs :: IO [String]                              System.Environment
--getProgName :: IO String                            System.Environment
--hPutStr :: Handle -> String -> IO ()                System.IO
             
main10::FilePath->IO String
main10 fp = do
    h <- openFile fp ReadMode
    hGetContents h

--main::IO()
--main = (main10 "exemplu.txt") >>= (\continut -> putStrLn(continut))

main::IO [String]->IO()
main getArgs = (main10 getArgs) >>= (\continut -> putStrLn(continut))