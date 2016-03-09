firstApp :: Int -> [Int] -> Int
firstApp x list = firstApp' x list 0

firstApp' :: Int -> [Int] -> Int -> Int
firstApp' _ [] _ = -1
firstApp' x (y : xs) pos = if x == y
                          then pos
                          else firstApp' x xs (pos + 1)
