isCorrect :: String -> Bool
isCorrect str = isCorrect' str []

isOpened :: Char -> Bool
isOpened c = c == '(' || c == '{' || c == '['

isSameType :: Char -> Char -> Bool
isSameType br1 br2 = (br1 == ')' && br2 == '(') || (br1 == '}' && br2 == '{') || (br1 == ']' && br2 == '[')

notBracket :: Char -> Bool
notBracket c = not (elem c "(){}[]")

isCorrect' :: String -> [Char] -> Bool
isCorrect' [] [] = True
isCorrect' [] _ = False
isCorrect' (c:str) []
    | isOpened c = isCorrect' str [c]
    | notBracket c = isCorrect' str []
    | otherwise = False
isCorrect' (c:str) (last:stack) 
    | isOpened c = isCorrect' str (c:last:stack)
    | isSameType c last = isCorrect' str stack
    | notBracket c = isCorrect' str (last:stack)
    | otherwise = False 