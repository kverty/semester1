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

treeSearch :: MyTree -> (Int -> Bool) -> Maybe Int
treeSearch Empty _ = Nothing
treeSearch (Node a left right) cond = if (cond a) 
                                      then Just a
                                      else if (leftAns /= Nothing)
                                           then leftAns
                                           else rightAns
                                      where leftAns = treeSearch left cond
                                            rightAns = treeSearch right cond

treeFold :: (Int -> Int -> Int) -> Int -> MyTree -> Int
treeFold _ acc Empty = acc
treeFold func acc (Node a left right) = treeFold func (func (treeFold func acc left) a) right 