data Term = Var Id
            | App Term Term
            | Lambda Id Term deriving (Show,Eq)

type Id = String

subst :: Id -> Term -> Term -> Term
subst id term (Var id') | id == id' = term
                        | True = (Var id')
subst id term (App term1 term2) = App (subst id term term1) (subst id term term2)
subst id term (Lambda id' term')    
                        | id == id' = (Lambda id' term')
                        | True = (Lambda id' (subst id term term'))

remove :: Id -> [Id] -> [Id]
remove _ [] = []
remove id (hd:tl)   | id == hd = remove id tl
                    | True = hd : (remove id tl)

free :: Term -> [Id]
free (Var id) = [id]
free (App term1 term2) = (free term1) ++ (free term2)
free (Lambda id term) = remove id (free term)

vars :: Term -> [Id]
vars (Var id) = [id]
vars (App term1 term2) = (vars term1) ++ (vars term2)
vars (Lambda id term) = [id] ++ (vars term)

fresh' :: [Id] -> Int -> Id
fresh' ids index = if ("n" ++ (show index)) `elem` ids then fresh' ids (index + 1)
else "n" ++ (show index)
fresh :: [Id] -> Id
fresh ids = fresh' ids (length ids)

fresh_arr :: [Id] -> [Id]
fresh_arr ids = [fresh ids]

casubst :: Id -> Term -> Term -> Term
casubst id term (Var id')
        | id == id' = term
        | True = (Var id')
casubst id term (App term1 term2) = App (subst id term term1) (subst id term term2)
casubst id term t@(Lambda id' term')  
        | id' `elem` (free term) = let id'' = fresh (free term ++ free term')
                                    in casubst id term (Lambda id'' term')
        | True = (Lambda id' (casubst id term term'))

reduce1 :: Term -> Maybe Term
reduce1 (Var id') = Nothing
reduce1 (App (Lambda id term) term') = Just (casubst id term' term) -- beta-reducerea propriu-zisa
reduce1 (App term1 term2) = case reduce1 term1 of
                                Nothing -> case reduce1 term2 of
                                    Nothing -> Just term1
                                    Just term2' -> Just term2
                                Just term1' -> Just (App term1' term2)
reduce1 t@(Lambda id term) = case reduce1 term of
                                Nothing -> Nothing
                                Just term' -> Just (Lambda id term')

reduce :: Term -> Term
reduce term = case reduce1 term of
                Nothing -> term
                Just term' -> term'
                                
reduceFor :: Int -> Term -> Term
reduceFor 0 term = term
reduceFor n term = case reduce1 term of
                    Nothing -> (Var "Error")
                    Just term' -> term'

x = Var "x"
y = Var "y"
z = Var "z"
f = 
term1 = Lambda "x" x
term2 = App term1 term1
term3 = Lambda "y" (Lambda "x" term2)
term4 = App term3 term1
Y = (Lambda )
ex1 = reduce1 term1 -- Nothing
ex2 = reduce1 term2 -- Just (\x.x)
ex3 = reduce1 term3 -- Just \y.\x.(\x.x)
ex4 = reduce1 term4 -- Care este rezultatul?