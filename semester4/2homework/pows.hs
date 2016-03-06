pows :: Int -> [Int]
pows 0 = []
pows n = 2 ^ n : pows (n - 1)