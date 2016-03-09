myReverse :: [a] -> [a]
myReverse list = foldl (\acc x -> x : acc) [] list