getPeople = do
    contents <- readFile "test.txt"
    let modified = [ l ++ "!" | l <- lines contents]
    return $ modified
