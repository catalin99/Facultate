type Id = String
data Type = TyBool 
            | TyNat 
            | TyArrow Type Type 
            | TyVar Id deriving (Eq, Show)
            
data Term = Var Id
            | Lam Id Term
            | App Term Term
            | TTrue
            | TFalse
            | TIte Term Term Term
            | TZero
            | Succ Term
            | Plus Term Term
            | IsZero Term deriving (Show,Eq)

data Context = Empty 
            | Cons Id Type Context

search :: Context -> Id -> Maybe Type
search Empty _ = Nothing
search (Cons x ty gamma') y = if x == y then Just ty else search gamma' y

update :: Context -> Id -> Type -> Context
update gamma x ty = Cons x ty gamma

data Equation = E Type Type deriving (Eq, Show) -- ecuatie
type Eqs = [Equation] -- lista de ecuatii = sistem de ecuatii

fresh_aux :: [Id] -> Int -> Id
fresh_aux ids n =   if ("X" ++ (show n)) `elem` ids then
                    fresh_aux ids (n + 1)
                    else
                    ("X" ++ (show n))

fresh :: [Id] -> Id
fresh ids = fresh_aux ids 1

ti :: Context -> Term -> [Id] -> (Maybe Type, [Id], Eqs)
ti gamma (Var x) ids =
    case search gamma x of
        Just ty -> (Just ty, ids, [])
        Nothing -> (Nothing, [], [])
ti gamma (App t1 t2) ids = 
    case ti gamma t1 ids of
        (Nothing, _, _) -> (Nothing, [], [])
        (Just ty1, ids', eqs1) -> 
            case ti gamma t2 ids' of
                (Nothing, _, _) -> (Nothing, [], [])
                (Just ty2, ids'', eqs2) -> 
                    let id = fresh ids'' in
                    let x = TyVar id in 
                    let l = ty1 in
                    let r = TyArrow ty2 x in
                        (Just x, ids'' ++ [id], eqs1 ++ eqs2 ++ [(E l r)])
ti gamma (Lam x t) ids = 
    let idX = fresh ids in
    let idY = fresh (ids ++ [idX]) in
        case ti (update gamma x (TyVar idX)) t (ids ++ [idX, idY]) of
            (Nothing, _, _) -> (Nothing, [], [])
            (Just ty, ids', eqs) -> let l = TyVar idY in
                                    let r = TyArrow (TyVar idX) ty in
                                    (Just l, ids', eqs ++ [(E l r)])
ti gamma TTrue ids  = (Just TyBool, ids, [])
ti gamma TFalse ids = (Just TyBool, ids, [])
ti gamma (TIte t1 t2 t3) ids = case ti gamma t1 ids of
    (Just ty, ids', eqs1) -> 
        case ti gamma t2 (ids ++ ids') of
            (Just ty2, ids'', eqs2) ->
                case ti gamma t3 (ids ++ ids' ++ ids'') of
                    (Just ty3, ids3, eqs3) -> 
                        let allIds = (ids ++ ids' ++ ids'' ++ ids3)  in 
                        let allEqs = (eqs1 ++ eqs2 ++ eqs3 ++ [(E ty2 ty3)] ++ [(E ty TyBool)]) in
                        let iteTy  = TyArrow (TyBool) (TyArrow (ty2) (TyArrow (ty3) (ty2))) in
                        (Just iteTy, allIds, allEqs)
                    (Nothing, _, _) -> (Nothing, [], [])
            (Nothing, _, _) -> (Nothing, [], [])
    _ -> (Nothing, [], [])

ti gamma TZero ids = (Just TyNat, ids, [])
ti gamma (Succ t) ids = case ti gamma t ids of
    (Just TyNat, ids', eqs) -> (Just TyNat, ids ++ ids', eqs)
ti gamma (Plus t1 t2) ids = 
    case ti gamma t1 ids of
        (Just TyNat, ids', eqs1) ->
            case ti gamma t2 ids of
                (Just TyNat, ids'', eqs2) -> 
                    let allIds = (ids ++ ids' ++ ids'')  in 
                    let allEqs = (eqs1 ++ eqs2) in
                    let plusTy = (TyArrow (TyNat) (TyArrow (TyNat) (TyNat))) in
                    (Just plusTy , allIds, allEqs)
                _ -> (Nothing, [], [])
        _ -> (Nothing, [], [])
ti gamma (IsZero t) ids = case ti gamma t ids of
    (Just TyNat, ids', eqs) -> (Just (TyArrow TyBool TyNat), ids ++ ids', eqs)
    _ -> (Nothing, [], [])


itOfTrue = ti Empty TTrue []
itOfFalse = ti Empty TFalse []
itOfZero = ti Empty (Plus TZero (Succ TZero)) []
itOfPlus = ti Empty (Plus TZero (Succ TZero)) []
itOfIte = ti Empty (TIte (IsZero TZero) t1 t1) []

t1 = Lam "x" (Var "x")
t2 = App t1 t1
