f1 :: (Int,Int) -> Maybe (Int,Int)
f1 (x,y) = Just (x + 1,y + 1)

f2 :: (Int, Int) -> Maybe Int
f2 (x,_) = Just x