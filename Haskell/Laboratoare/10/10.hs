import Data.Maybe

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

casubst :: Id -> Term -> Term -> [Id] -> Term
casubst id term (Var id') _
        | id == id' = term
        | True = (Var id')
casubst id term (App term1 term2) _ = App (casubst id term term1) (casubst id term term2)
casubst id term t@(Lambda id' term') avoid
        | id == id' = t
        | id' `elem` (free term) = let id'' = fresh (free term ++ free term' ++ avoid)
                                    in casubst id term (Lambda id'' term') avoid
        | True = (Lambda id' (casubst id term term' avoid))

reduce1' :: Term -> [Id] -> Maybe Term
reduce1' (Var id') _ = Nothing
reduce1' (App (Lambda id term) term') avoid = Just (casubst id term' term avoid) -- beta-reducerea propriu-zisa
reduce1' t@(App term1 term2) avoid = case reduce1' term1 avoid of
                                Nothing -> case reduce1' term2 avoid of
                                    Nothing -> Nothing
                                    Just term2' -> Just (App term1 term2')
                                Just term1' -> Just (App term1' term2)
reduce1' t@(Lambda id term) avoid = case reduce1' term avoid of
                                Nothing -> Nothing
                                Just term' -> Just (Lambda id term')

reduce1 :: Term -> Maybe Term
reduce1 t = reduce1' t (vars t)


-- normal order strategy
reduce :: Term -> Term
reduce term = case reduce1 term of
                Nothing -> term
                Just term' -> reduce term'
                                
reduceFor :: Int -> Term -> Term
reduceFor 0 term = term
reduceFor n term = case reduce1 term of
                    Nothing -> (Var "Error")
                    Just term' -> reduce term'

-- lab10

cbnReduce1' :: Term -> [Id] -> Maybe Term
cbnReduce1' (Var id') _ = Nothing
cbnReduce1' (App (Lambda id term) term') avoid = Just (casubst id term' term avoid) -- beta-reducerea propriu-zisa
cbnReduce1' t@(App term1 term2) avoid = case cbnReduce1' term1 avoid of
                                Nothing -> case cbnReduce1' term2 avoid of
                                    Nothing -> Nothing
                                    Just term2' -> Just (App term1 term2')
                                Just term1' -> Just (App term1' term2)
cbnReduce1' t@(Lambda id term) avoid = Nothing

cbnReduce1 :: Term -> Maybe Term
cbnReduce1 t = cbnReduce1' t (vars t)


cbnReduce :: Term -> Term
cbnReduce term = case cbnReduce1 term of
                Nothing -> term
                Just term' -> cbnReduce term'
    


-- practice

x = Var "x"
y = Var "y"
z = Var "z"
f = Var "f"
n = Var "n"
m = Var "m"
p = Var "p"
x1 = Var "x1"
x2 = Var "x2"
x3 = Var "x3"
g = Var "g"
h = Var "h"
u = Var "u"

term1 = Lambda "x" x
term2 = App term1 term1
term3 = Lambda "y" (Lambda "x" term2)
term4 = App term3 term1

ex1 = reduce1 term1 -- Nothing
ex2 = reduce1 term2 -- Just (\x.x)
ex3 = reduce1 term3 -- Just \y.\x.(\x.x)
ex4 = reduce1 term4 -- Care este rezultatul?

tTRUE = Lambda "x" (Lambda "y" x)
tFALSE = Lambda "x" (Lambda "y" y)
tAND = Lambda "x" (Lambda "y" (App (App x y) x))
tOR = Lambda "x" (Lambda "y" (App (App x x) y))
tNOT = Lambda "x" (App tFALSE tTRUE)
tXOR = Lambda "x" (Lambda "y" (App (App x (App tNOT y)) y))

tZero = Lambda "f" (Lambda "x" x)
tOne = Lambda "f" (Lambda "x" (App (App f x) x))
tSucc = Lambda "n" (Lambda "f" (Lambda "x" (App (App n f) (App f n))))
tPlus = Lambda "n" (Lambda "m" (Lambda "f" (Lambda "x" (App (App n f) (App (App m f) x)))))
tIsZero = Lambda "n" (App (App n (Lambda "x" tFALSE)) tTRUE)
tMult = Lambda "n" (Lambda "m" (Lambda "f" (Lambda "x" (App (App n (App m f)) x))))

tPair = Lambda "x" (Lambda "y" (Lambda "z" (App (App z x) y)))
tFirst = Lambda "p" (App p tTRUE)
tSecond = Lambda "p" (App p tFALSE)


q1 = App (Lambda "x1" x1) (App (Lambda "x2" x2) (Lambda "z" (App (Lambda "x3" x3) z)))
q1' = reduce1 (fromJust (reduce1 q1))
q1'' = reduce1 (fromJust (reduce1 ( fromJust (reduce1 q1))))

