type Id = String

data Term = Var Id --- x ---> Var "x"
            | App Term Term --- t1 t2 ---> App t1 t2
            | Lambda Id Term deriving (Show, Eq) --- \x.t ---> Lambda "x" t

-- capturing substitution
subst :: Id -> Term -> Term -> Term
subst x t' (Var y) | x == y = t'
            | otherwise = (Var y)
subst x t' (App t1 t2) = App (subst x t' t1) (subst x t' t2)
subst x t' (Lambda y t) | x == y = (Lambda x t)
            | otherwise = (Lambda y (subst x t' t))

-- helpers
remove :: Id -> [Id] -> [Id]
remove _ [] = []
remove id (hd:tl) | id == hd = remove id tl
            | True = hd : (remove id tl)

free :: Term -> [Id]
free (Var id) = [id]
free (App term1 term2) = (vars term1) ++ (vars term2)
free (Lambda id term) = remove id (vars term)

vars :: Term -> [Id]
vars (Var id) = [id]
vars (App term1 term2) = (vars term1) ++ (vars term2)
vars (Lambda id term) = id : (vars term)

fresh' :: [Id] -> Int -> Id
fresh' ids index = if ("n" ++ (show index)) elem ids then fresh' ids (index + 1)
else "n" ++ (show index)

fresh :: [Id] -> Id
fresh ids = fresh' ids 0

-- capture avoiding substitution
casubst :: Id -> Term -> Term -> [Id] -> Term
casubst id term (Var id') _ | id == id' = term
            | True = (Var id')
casubst id term (App term1 term2) avoid = App (casubst id term term1 avoid)
    (casubst id term term2 avoid)
casubst id term (Lambda id' term') avoid | id == id' = (Lambda id' term')
            | id' elem (free term) =
    let id'' = fresh avoid in
    casubst id term (Lambda id'' (casubst id' (Var id'') term' (id'' : avoid))) (id'' : avoid) 
            | True = Lambda id'
    (casubst id term term' avoid)

reduce1' :: Term -> [Id] -> Maybe Term 
reduce1' (Var id') _ = Nothing
reduce1' (App (Lambda id term) term') avoid =   Just (casubst id term' term avoid)
reduce1' (App term1 term2) avoid = case reduce1' term1 avoid of Nothing -> case reduce1' term2 avoid of Nothing -> Nothing
                                                                                                        Just term2' -> Just (App term1 term2')
                                                                Just term1' -> Just (App term1' term2)
reduce1' (Lambda id term) avoid = case reduce1' term avoid of
    Nothing -> Nothing
    Just term' -> Just (Lambda id term')

reduce1 :: Term -> Maybe Term
reduce1 t = reduce1' t (vars t)

reduce :: Term -> Term
reduce term = case reduce1 term of
    Nothing -> term
    Just term' -> reduce term'

count :: Term -> Int
count term = case reduce1 term of
    Nothing -> 0
    Just term' -> 1 + (count term')

reduceFor :: Int -> Term -> Term
reduceFor 0 term = term
reduceFor n term = case reduce1 term of
    Nothing -> term
    Just term' -> reduceFor (n - 1) term'


tTRUE = Lambda "x" (Lambda "y" (Var "x"))
tFALSE = Lambda "x" (Lambda "y" (Var "y"))
tAND = Lambda "u" (Lambda "v" (App (App u v) u))
--reduceFor 10 (App (App tAND tTRUE) tFALSE)
--reduce1 (App tAND (App tTRUE tTRUE))
tOR = (App (App (Lambda "u" (Lambda "v" (Var "u"))) (tTRUE)) (Var "v"))
tNOT = (App (App (Lambda "u" (Var "u")) tTRUE) tFALSE)
--reduceFor 10 (App tNOT tFALSE)

--0.12
x = (Var "x")
f = (Var "f")
n = (Var "n")
m = (Var "m")
u = (Var "u")
v = (Var "v")
n0 = Lambda "f" (Lambda "x" x)
n1 = Lambda "f" (Lambda "x" (App f x))
n2 = Lambda "f" (Lambda "x" (App f (App f x)))
n3 = Lambda "f" (Lambda "x"  (App f (App f (App f x))))
lSUCC = Lambda "n" (Lambda "f" (Lambda "x" (App (App n f) (App f x))))
--reduceFor 10 (App lSUCC n0)

lPLUS = Lambda "n" (Lambda "m" (Lambda "f" (Lambda "x" (App (App m f) (App n (App f x))))))
--reduce (App (App n0 lPLUS) n1)
tXOR = Lambda "u" (Lambda "v" (App (App u (App tNOT v)) v))

