data Tree = Empty | Node Int Tree Tree

treeInsert' :: Int -> Tree -> Tree
treeInsert' x Empty = Node x Empty Empty
treeInsert' x (Node a left right)
         | x == a = Node x left right
         | x < a  = Node a (treeInsert' x left) right
         | x > a  = Node a left (treeInsert' x right)

treeInsert :: Tree -> [Int] -> Tree
treeInsert tree [] = tree
treeInsert tree list = foldr (treeInsert') tree list

treeRemove :: Int -> Tree -> Tree
treeRemove x Empty = Empty
treeRemove x (Node a left right) 
         | x > a = treeRemove a left
         | x < a = treeRemove a right
         | x == a & right == Empty = left
         | x == a & left == Empty = right
         | otherwise = Node (leftMost right) left (deleteLeftMost right)

leftMost :: Tree -> Int
leftMost (Node a Empty _) = a
leftMost (Node _ left _ ) = leftMost left

deleteLeftMost :: Tree -> Tree
deleteLeftMost (Node _ Empty right) = right
deleteLeftMost (Node a left right) = Node a (deleteLeftMost left) right

treeSearch :: Int -> Tree -> Bool
treeSearch _ Empty = false
treeSearch x (Node a left right) = (x == a) || (x > a && treeSearch a left) || (x < a && treeSearch a right)

treeHeight :: Tree -> Int
treeHeight Empty = 0
treeHeight (Node _ left right) = max (treeHeight left) (treeHeight right)

treeCardinality :: Tree -> Int
treeCardinality Empty = 0
treeCardinality (Node _ left right) = 1 + (treeCardinality left) + (treeCardinality right)