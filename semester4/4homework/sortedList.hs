addValue :: [Int] -> Int -> [Int]
addValue [] value = [value]
addValue (x:xs) value = if (x < value)
                            then (x : (addValue xs value))
                            else (value : x : xs)

deleteValue :: [Int] -> Int -> [Int]
deleteValue [] _ = []
deleteValue (x:xs) value = if (x == value)
                               then xs
                               else if (x > value)
                                        then (x : xs)
                                        else (x : (deleteValue xs value))

iteration :: [Int] -> IO ()
iteration list = do
    putStrLn "Enter number of the command : "
    c <- getLine
    case head c of
        '0' -> putStrLn "Exit"
        '1' -> do putStrLn "Enter new number: "
                  value <- readLn  
                  iteration (addValue list value)
        '2' -> do putStrLn "Enter number you want to delete: " 
                  value <- readLn
                  iteration (deleteValue list value)
        '3' -> do print list
                  iteration list
        otherwise -> do putStrLn "Wrong number of command"
                        iteration list

main = do 
     putStr "0 - exit \n1 - add value to sorted list \n2 - remove value from list \n3 - print list\n"
     iteration [] 