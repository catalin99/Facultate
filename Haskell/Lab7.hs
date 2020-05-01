type Id = String -- alias

data Term = Var Id
          | App Term Term
          | Lambda Id Term 
          deriving (Show, Eq)

subst :: Id -> Term -> Term -> Term

--x[x/t] -> t
--y[x/t] -> y
subst id term (Var id') | id == id' = term
                        | True      = (Var id')

--(e1 e2)[x/t] -> (e1[x/t] e2[x/t])           
subst id term (App term1 term2) = App (subst id term term1) (subst id term term2)

--(\x.t')[x/t] = \x.t'
--(\y.t')[x/t] = \y.t'[x/t]
subst id term (Lambda id' term') | id == id' = (Lambda id' term')
                                 | True      = (Lambda id' (subst id term term'))

remove :: Id -> [Id] -> [Id]
remove _ [] = []
remove id (hd:tl) | id == hd = remove id tl
                  | True     = hd : remove id tl  
                  
free :: Term -> [Id]
free (Var id) = [id]
--concatenarea var din termeni
free (App term1 term2) = (free term1) ++ (free term2)
-- id-urile care apar in term egale cu id, nu apar in lista    
free (Lambda id term) = remove id (free term)           