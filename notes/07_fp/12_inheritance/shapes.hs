class Shape a where
    area :: a->Double
    perimeter :: a->Double

newtype Circle = Circle Double deriving (Eq,Show)
newtype Square = Square Double deriving (Eq,Show)

instance Shape Circle where
    area (Circle r) = pi * r * r
    perimeter (Circle r) = 2 * pi * r

instance Shape Square where
    area (Square a) = a * a
    perimeter (Square a) = 4 * a
    

