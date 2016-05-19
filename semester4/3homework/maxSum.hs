maxSum :: [Int] -> Int
maxSum [_] = -1
maxSum [_,_] = 0 
maxSum (x : list) = 
    let i = maxSum list
    in if (x + head list > (list !! i) + (list !! (1 + i)))
                    then 0
                    else (1 + i)
