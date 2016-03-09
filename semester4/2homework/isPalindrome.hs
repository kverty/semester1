isPalindrome :: String -> Bool
isPalindrome str = isPalindrome' str 0 (length(str) - 1)

isPalindrome' :: String -> Int -> Int -> Bool
isPalindrome' str leftIndex rightIndex = if leftIndex >= rightIndex
                                         then True
                                         else if (str !! leftIndex) /= (str !! rightIndex)
                                              then False
                                              else isPalindrome' str (leftIndex + 1) (rightIndex - 1)