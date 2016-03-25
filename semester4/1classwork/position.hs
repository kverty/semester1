elemPosition :: [Int] -> Int -> Int
elemPosition xs x = foldr (\y acc -> if x == y then 0 else acc + 1) 0 xs