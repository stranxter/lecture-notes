data Season = Winter | Spring | Summer | Autumn
    deriving(Eq, Show, Enum)

seasonn Spring = 1
seasonn Summer = 2
seasonn Autumn = 3
seasonn Winter = 4

data Point = Point Double Double
    deriving(Eq, Show, Ord)


data Shape = Circle Double | Rectangle Double Double
    deriving(Eq, Show, Ord)

area :: Shape -> Double
area (Circle r) = pi * r * r   --  Rectangle 2 4 == (Cricle r)
area (Rectangle a b) = a * b   --  Rectangle 2 4 == (Rectangle a b)
                               --  a = 2 b = 4

data Student = Student {name :: String
                        ,fn :: String
                        ,grades :: [(String,Double)]}
    deriving(Eq, Show, Ord)

data Couple a = Couple a a



