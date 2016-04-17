data MyTree = Empty | Node Int MyTree MyTree deriving (Show)

treeInsert' :: Int -> MyTree -> MyTree
treeInsert' x Empty = Node x Empty Empty
treeInsert' x (Node a left right)
         | x == a = Node x left right
         | x < a  = Node a (treeInsert' x left) right
         | x > a  = Node a left (treeInsert' x right)

treeInsert :: MyTree -> [Int] -> MyTree
treeInsert tree [] = tree
treeInsert tree list = foldr (treeInsert') tree list

allNegative :: MyTree -> [Int]
allNegative tree = allNegative' tree []

allNegative' :: MyTree -> [Int] -> [Int]
allNegative' Empty ans = ans
allNegative' (Node a left right) ans = 
    let negativeChildren = allNegative' right $ allNegative' left ans
    in if a < 0 
       then a : negativeChildren 
       else negativeChildren 