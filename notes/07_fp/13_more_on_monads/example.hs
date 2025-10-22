io = do 
    x <- getLine
    putStrLn ("You entered: " ++  x)
    putStrLn "Thank you!"
    return x

lexample = do
    x <- [1,2,3]
    n <- "abc"
    return (x,n)

getInt :: IO Int = do
    x <- getLine
    return (read x :: Int)