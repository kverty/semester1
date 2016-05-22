data Polynom a = Polynom [a]

listSum :: (Num a) => [a] -> [a] -> [a]
listSum (x1 : l1) (x2 : l2) = (x1 + x2) : (listSum l1 l2)
listSum [] l2 = l2
listSum l1 [] = l1

listMult :: (Num a) => [a] -> [a] -> [a]
listMult (x1 : l1) l2 = listSum (map (*x1) l2) (0 : (listMult l1 l2))
listMult [] ls = []

showCoef :: (Num a, Show a, Eq a, Ord a) => a -> Bool -> String
showCoef c isFirst
    | c == 1 && isFirst = " 1"
    | c == 1 && not isFirst = "+"  
    | c == -1 = "-"
    | c < 0 = show c
    | c > 0 && isFirst = " " ++ show c
    | otherwise = "+" ++ show c

showExp :: Int -> Int -> Bool -> String
showExp coefsLeft deg coefIs1
    | currDeg == 0 = ""
    | currDeg == 1 = "X"
    | otherwise = sign ++ "X^" ++ show currDeg
    where currDeg = deg - coefsLeft - 1
          sign
              | coefIs1 = ""
              | otherwise = "*"

showList :: (Num a, Show a, Eq a, Ord a) => [a] -> Bool -> Int -> String
showList [] _ _ = ""
showList (c : coefs) isFirst l
    | c == 0 = Main.showList coefs isFirst l
    | otherwise = (showCoef c isFirst) ++ (showExp (length coefs) l (c == 1 || c == -1)) ++ (Main.showList coefs False l)

add :: (Num a) => Polynom a -> Polynom a -> Polynom a
add (Polynom coefs1) (Polynom coefs2) = Polynom (listSum coefs1 coefs2)

mult :: (Num a) => Polynom a -> Polynom a -> Polynom a
mult (Polynom coefs1) (Polynom coefs2) = Polynom (listMult coefs1 coefs2)

instance (Num a, Show a, Ord a, Eq a) => Show (Polynom a) where
    show (Polynom coefs) = Main.showList coefs True (length coefs)

main = do
    let p = Polynom [0, -1, 2, -3, 5, 1]
    putStrLn("p =" ++ show p)
    let q = Polynom [3, -1, 2]
    putStrLn("q =" ++ show q)
    let r = Polynom [1, 0, 1]
    putStrLn("r =" ++ show r)
    putStrLn("p + q =" ++ show (add p q))
    putStrLn("p * q =" ++ show (mult p q))
