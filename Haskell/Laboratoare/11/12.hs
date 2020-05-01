import Data.Maybe

data Type = TyBool
            | TyNat
            | TyArrow Type Type deriving (Show,Eq)

type Id = String

data Term = Var Id
            | Lam Id Type Term
            | App Term Term
            | TTrue
            | TFalse
            | TIte Term Term Term
            | TZero
            | Succ Term
            | Plus Term Term
            | IsZero Term deriving (Show,Eq)

isvalue :: Term -> Bool
isvalue TTrue = True
isvalue TFalse = True
isvalue TZero = True
isvalue (Succ t) = isvalue t
_ = False

data Context = Empty
            | Bind Id Type Context deriving (Show)

update :: Context -> Id -> Type -> Context
update gamma x ty = Bind x ty gamma

search :: Context -> Id -> Maybe Type
search Empty _ = Nothing
search (Bind x ty gamma) y
    | x == y = Just ty
    | otherwise = search gamma y


typecheck :: Context -> Term -> Maybe Type
typecheck gamma (Var id) = search gamma id
typecheck gamma TTrue = Just TyBool
typecheck gamma TFalse = Just TyBool
typecheck gamma TZero = Just TyNat
typecheck gamma (Succ t) = case typecheck gamma t of
    Just TyNat -> Just TyNat
    _ -> Nothing
typecheck gamma (Plus t1 t2) = case (typecheck gamma t1, typecheck gamma t2) of
    (Just TyNat, Just TyNat) -> Just TyNat
    _ -> Nothing
typecheck gamma (IsZero t) = case typecheck gamma t of
    Just TyNat -> Just TyBool
    _ -> Nothing
typecheck gamma (TIte t1 t2 t3) =
    case typecheck gamma t1 of
        Nothing -> Nothing
        Just TyBool -> let tyt2 = typecheck gamma t2 in
                        let tyt3 = typecheck gamma t3 in
                            if tyt2 == tyt3 then
                            tyt2
                            else
                            Nothing
        Just _ -> Nothing
typecheck gamma (App t1 t2) = 
    case typecheck gamma t1 of
        Just t1'@(TyArrow ty1 ty2) -> case typecheck gamma t2 of
            Just t2' -> if ty1== t2' 
                        then Just ty2 
                        else Nothing
            _ -> Nothing
        _ -> Nothing
typecheck gamma (Lam x ty t) =
    case typecheck (update gamma x ty) t of
        Just ty' -> Just (TyArrow ty ty')
        _ -> Nothing


remove :: Id -> [Id] -> [Id]
remove _ [] = []
remove id (hd:tl)
   | id == hd   = remove id tl
   | otherwise  = hd : (remove id tl)

free :: Term -> [Id]
free (Var id) = [id]
free (App t1 t2)    = free t1 ++ free t2
free (Lam id _ t)   = remove id (free t)
free (TIte _ t2 t3) = free t2 ++ free t3
free _ = []

vars :: Term -> [Id]
vars (Var id) = [id]
vars (App t1 t2)    = vars t1 ++ vars t2
vars (Lam id _ t)   = [id] ++ vars t
vars (TIte _ t2 t3) = vars t2 ++ vars t3

fresh' :: [Id] -> Int -> Id
fresh' ids index  = if ("n" ++ (show index)) `elem` ids 
                    then fresh' ids (index + 1)
                    else "n" ++ (show index)
fresh :: [Id] -> Id
fresh ids = fresh' ids (length ids)


casubst :: Id -> Term -> Term -> [Id] -> Term
casubst id t (Var id') _
        | id == id' = t
        | otherwise = (Var id')
casubst id t (App term1 term2) avoid = App (casubst id t term1 avoid) (casubst id t term2 avoid)
casubst id term t@(Lam id' ty' term') avoid
        | id == id' = t
        | id' `elem` (free term) = let id'' = fresh (free term ++ free term' ++ avoid)
                                    in casubst id term (Lam id'' ty' term') avoid
        | otherwise = (Lam id' ty' (casubst id term term' avoid))

reduce1' :: Term -> [Id] -> Maybe Term
reduce1' (Var id') _ = Nothing
reduce1' (App (Lam id ty term) term') avoid = Just (casubst id term' term avoid) -- beta-reducerea propriu-zisa
reduce1' t@(App term1 term2) avoid = case reduce1' term1 avoid of
                                Nothing -> case reduce1' term2 avoid of
                                    Nothing -> Nothing
                                    Just term2' -> Just (App term1 term2')
                                Just term1' -> Just (App term1' term2)
reduce1' t@(Lam id ty term) avoid = case reduce1' term avoid of
                                Nothing -> Nothing
                                Just term' -> Just (Lam id ty term')

reduce1 :: Term -> Maybe Term
reduce1 t = reduce1' t (vars t)

-- normal order strategy
reduce :: Term -> Term
reduce term = case reduce1 term of
                Nothing -> term
                Just term' -> reduce term'

                
cbnReduce1' :: Term -> [Id] -> Maybe Term
cbnReduce1' (Var id) _ = Nothing
cbnReduce1' (App (Lam id ty term) term') avoid = Just (casubst id term' term avoid) -- beta-reducerea propriu-zisa
cbnReduce1' t@(App term1 term2) avoid = case cbnReduce1' term1 avoid of
                                Nothing -> case cbnReduce1' term2 avoid of
                                    Nothing -> Nothing
                                    Just term2' -> Just (App term1 term2')
                                Just term1' -> Just (App term1' term2)
cbnReduce1' t@(Lam id ty term) avoid = Nothing
cbnReduce1' (TIte t1 t2 t3) avoid = case cbnReduce t1 of
    TTrue -> cbnReduce1 t2
    TFalse -> cbnReduce1 t3
cbnReduce1' TTrue avoid = Nothing
cbnReduce1' TFalse avoid = Nothing
cbnReduce1' TZero avoid = Nothing
cbnReduce1' (Succ t1) avoid = Nothing
cbnReduce1' (Plus t1 t2) avoid = case (t1,t2) of
    (TZero,t2') -> Just t2'
    (t1',TZero) -> Just t1'
    (Succ t1', t2') -> Just (Succ (Plus t1' t2'))
cbnReduce1' (IsZero t) avoid = case cbnReduce1' t avoid of
    Just TZero -> Just TTrue
    _ -> Just TFalse


cbnReduce1 :: Term -> Maybe Term
cbnReduce1 t = cbnReduce1' t (vars t)


cbnReduce :: Term -> Term
cbnReduce term = case cbnReduce1 term of
                Nothing -> term
                Just term' -> cbnReduce term'


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

ex2     = Lam "x" TyBool x
gamma0  = Empty 
gamma1  = Bind "x" TyBool Empty
t1      = App (Lam "x" TyBool (Var "x")) TTrue
t2      = App (Lam "y" TyBool y) (Lam "x" (TyArrow TyBool TyBool) x)