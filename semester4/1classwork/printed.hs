data Printed = Magazine String Int Int Int | Book String String Int
     deriving (Show)

sumPrice :: [Printed] -> Int
sumPrice [] = 0
sumPrice (Magazine _ _ _ price : xs) = price + sumPrice xs
sumPrice (Book _ _ price : xs) = price + sumPrice xs