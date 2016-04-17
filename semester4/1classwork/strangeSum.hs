strangeSum :: [Double] -> Double
strangeSum xs = strangeSum' 0 1 xs

strangeSum' :: Double -> Double -> [Double] -> Double
strangeSum' numer denom [] = numer / denom
strangeSum' numer denom (x : xs) = strangeSum' (numer + x) (denom * cos(x)) xs