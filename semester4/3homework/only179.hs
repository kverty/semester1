numbers :: [Int]
numbers = [1, 7, 9] ++ [digit + 10 * x | x <- numbers, digit <- [1, 7, 9]]