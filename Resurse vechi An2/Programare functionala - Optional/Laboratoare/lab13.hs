import Data.Char

data Parser a = Parser (String -> [(a,String)])

success::a->Parser a

success v = Parser (\input->[(v,input)])

failure = Parser(\ _ ->[])

item = Parser (\input->case input of
						[] -> []
						(c:cs)->[(c,cs)])


--parse :: Parser a -> String -> [(a, String)]

parse (Parser p) s = p s


instance Monad Parser where
	 return = success
	 p >>= f = Parser(\input->case parse p input of
	 						  [] -> []
	 						  [(v,r)]-> parse (f v) r)

(+++) :: Parser a -> Parser a -> Parser a 
(+++) p q = Parser (\input->case parse p input of
	 						   [] -> parse q input
	 						   s->s )




p13 :: Parser (Char, Char)
p13 = do
	c1<-item
	c2<-item
	c3<-item
	return(c1,c3)
 
sat :: (Char -> Bool) -> Parser Char
sat p = do
 		  c <- item
 		  if p c 
 		  then return c
 	   	  else failure
digit :: Parser Char
digit = sat (`elem`['0'..'9'])

digit2 = sat isDigit