primes4 :: [Int]
primes4 = [x | x <- [2..], foldl (&&) True [rem x p /= 0 | p <- primes4]] 