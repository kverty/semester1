maxSum :: [Int] -> Int
maxSum [_] = -1
maxSum [_,_] = 0 
maxSum (x : list) = if (x + head list > (list !! maxSum list) + (list !! (1 + maxSum list)))
                    then 0
                    else (1 + maxSum list)
