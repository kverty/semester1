import Control.Monad

dealWithTriple :: (Int, Int, Int) -> Maybe Int
dealWithTriple (x, y, z) | x < y && y > z = Just y
                         | otherwise = Nothing

firstLocalMax :: [Int] -> Maybe Int
firstLocalMax (x : y : z : xs) = mplus (dealWithTriple (x, y, z)) (firstLocalMax (y : z : xs))
firstLocalMax _ = Nothing