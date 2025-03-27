data Point a = Point a a 
    deriving(Show)


myDiv :: Int -> Int -> Maybe Int
myDiv x y
  | y /= 0 = Just (div x y)
  | otherwise = Nothing

takeInt (Just x) = x