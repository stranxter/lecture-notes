

inputplus1 :: IO Int
inputplus1 = fmap (+1) readLn

lexample = do
    x <- [1,2,3]
    c <- "abc"
    return (x,c)
