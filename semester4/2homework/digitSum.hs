digitSum :: Integer -> Integer
digitSum x
    | x < 10 = x
    | otherwise = (rem x 10) + digitSum (div x 10)