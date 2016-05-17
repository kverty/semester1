listOfMult :: Int -> [Int]
listOfMult n = [1..n] >>= (\x -> map (\y -> y* x) [1..n])

listOfMult2 :: Int -> [String]
listOfMult2 n = [1..n] >>= (\x -> map (\y -> (show y ++ "*" ++ show x)) [1..n])