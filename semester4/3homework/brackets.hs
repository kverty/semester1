isCorrect :: String -> Bool
isCorrect str = isCorrect' str 0

isCorrect' :: String -> Int -> Bool
isCorrect' [] 0 = True
isCorrect' [] _ = False
isCorrect' (c:str) num = if num < 0
                         then False
                         else if c == '('
                              then isCorrect' str (num + 1)
                              else if c == ')'
                                   then isCorrect' str (num - 1)
                                   else isCorrect' str num