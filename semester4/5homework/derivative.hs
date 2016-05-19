data Expression = X 
    | Const Int
    | Sum Expression Expression
    | Mult Expression Expression 
    | Sub Expression Expression
    | Div Expression Expression
    | Pow Expression Int
    deriving (Show, Eq)

derive :: Expression -> Expression
derive X = (Const 1)
derive (Const a) = Const 0
derive (Sum exp1 exp2) = Sum (derive exp1) (derive exp2)
derive (Sub exp1 exp2) = Sub (derive exp1) (derive exp2)
derive (Mult exp1 exp2) = Sum (Mult exp1 (derive exp2)) (Mult (derive exp1) exp2)
derive (Div exp1 exp2) = Div (Sub (Mult (derive exp1) exp2) (Mult exp1 (derive exp2))) (Mult exp1 exp2)
derive (Pow exp1 deg) = Mult (Mult (Const deg) (derive exp1)) (Pow exp1 (deg - 1))

simplify :: Expression -> Expression
simplify (Sum (Const a) (Const b)) = Const (a + b)
simplify (Sub (Const a) (Const b)) = Const (a - b)
simplify (Mult (Const a) (Const b)) = Const (a * b)
simplify (Div (Const a) (Const b)) = Const (div a b)
simplify (Pow (Const a) b) = Const (a ^ b)

simplify (Sum (Const 0) exp) = simplify exp
simplify (Sub (Const 0) exp) = simplify (Mult (Const (-1)) exp)
simplify (Mult (Const 0) exp) = Const 0
simplify (Mult (Const 1) exp) = simplify exp
simplify (Sum exp (Const 0)) = simplify exp
simplify (Sub exp (Const 0)) = simplify exp
simplify (Mult exp (Const 0)) = Const 0
simplify (Mult exp (Const 1)) = simplify exp
simplify (Pow exp 0) = Const 1
simplify (Pow exp 1) = simplify exp
simplify (Div exp (Const 1)) = simplify exp

simplify (Sum exp1 exp2) = Sum (simplify exp1) (simplify exp2)
simplify (Sub exp1 exp2) = Sub (simplify exp1) (simplify exp2)
simplify (Mult exp (Const a)) = simplify (Mult (Const a) exp)
simplify (Mult exp1 exp2) = Mult (simplify exp1) (simplify exp2)
simplify (Div exp1 exp2) = Div (simplify exp1) (simplify exp2)
simplify (Pow exp1 deg) = Pow (simplify exp1) deg

simplify exp = exp

multiSimplify :: Expression -> Expression
multiSimplify exp 
    | exp == simplify exp = exp
    | otherwise = multiSimplify (simplify exp)

main = do
        putStrLn (show $ derive (Sum (Mult (Const 3) (Pow X 4)) (Sub (Pow X 3) (Sum (Mult (Const 5) X) (Const (-3))))))
        putStrLn (show $ multiSimplify $ derive (Sum (Mult (Const 3) (Pow X 4)) (Sub (Pow X 3) (Sum (Mult (Const 5) X) (Const (-3))))))

        putStrLn (show $ multiSimplify $ derive (Sum (Const 1) (X)))