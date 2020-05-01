--putStrLn :: String -> IO () 
--getLine :: IO String

main = do
		 helloName
   		 sumOfTwo
   		 
helloName = do
		 putStrLn "Hello, what's your name?"  
  		 name <- getLine  
   		 putStrLn ("Hey " ++ name ++ ", you rock!")  

sumOfTwo = do
		 putStrLn "Give me 2 numbers"
   		 x <- getLine
   		 y <- getLine
   		 let sum = read x + read y
   		 putStrLn ("The sum is "++show(sum))

data Poate a = Doar a | Nimic
	deriving Show

data Pers = Pers String (Poate Pers, Poate Pers)
	deriving Show

_Ion = Pers "Ion"	(
        Doar ( Pers "Tata Gheorghe" (
            Doar (Pers "Tata tatei Grigore" (
                Doar (Pers "Strabunicu Matei" (Nimic, Nimic)),
                Nimic)
            ),
            Nimic
            )
        ),
        Doar (Pers "Mama Maria" (
            --Nimic,
            Doar (Pers "Tata mamei Ghita" (
                Nimic,
                Nimic
                )
            ),
            Doar (Pers "Mama mamei Ioana" (
                Nimic,
                Nimic
                )
            )
            )
        )
    )

getDad::Pers->Poate Pers
getDad (Pers _ ( d , _ ) ) = d
getMom::Pers->Poate Pers
getMom (Pers _ ( _ , m ) ) = m

getMomDad::Pers->Poate Pers
getMomDad p = case ( getMom p ) of
			Nimic -> Nimic
			Doar m -> (getDad m)

getDadDad::Pers->Poate Pers
getDadDad p = case ( getDad p ) of
			Nimic -> Nimic
			Doar d -> (getDad d)

getGrandDads::Pers->(Poate Pers,Poate Pers)
getGrandDads p = (getMomDad p , getDadDad p)

getGrandDads2::Pers->(Poate Pers,Poate Pers)
getGrandDads2 p =   case ( getMom p ) of
					Nimic ->   ( case ( getDad p )  of
							 	 Nimic -> (Nimic,Nimic)
								 Doar d -> (Nimic,getDad d) )
					Doar m ->  ( case ( getDad p ) of
							 	 Nimic -> (getDad m,Nimic)
								 Doar d -> ( getDad m , getDad d ) )


--PoatePers->(Pers->Poate Pers)->Poate Pers
--(>>=) :: Monad m => m a -> (a -> m b) -> m b
--return :: Monad m => a -> m a

instance Monad Poate where
	Nimic >>= _ = Nimic
	Doar p >>= f = f p
	return p = Doar p

getMomsDad p = getMom p >>= getDad

modDad p= do
		m <- getMom p
		bm <- getDad m
		return bm