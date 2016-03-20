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

treeMaxHeight :: MyTree -> Int
treeMaxHeight Empty = -1
treeMaxHeight (Node _ left right) = (max (treeMaxHeight (left)) (treeMaxHeight (right))) + 1

treeMinHeight :: MyTree -> Int
treeMinHeight (Node _ Empty Empty) = 0
treeMinHeight (Node _ left Empty) = treeMinHeight (left) + 1
treeMinHeight (Node _ Empty right) = treeMinHeight (right) + 1
treeMinHeight (Node _ left right) = (min (treeMinHeight (left)) (treeMinHeight (right))) + 1