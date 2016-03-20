foldrOddCount :: [Int] -> Int
foldrOddCount = foldr (\x acc -> acc + rem x 2) 0

mapOddCount :: [Int] -> Int
mapOddCount list = sum $ map (flip rem 2) list 

foldrEvenCount :: [Int] -> Int
foldrEvenCount list = length (list) - foldrOddCount list

mapEvenCount :: [Int] -> Int
mapEvenCount list = length (list) - mapOddCount list 

filterEvenCount :: [Int] -> Int
filterEvenCount list = length $ filter even list
