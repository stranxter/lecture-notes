data Season = Spring | Summer | Autumn | Winter 
    deriving(Eq, Show, Ord, Enum, Read)

startsWithWinter (Winter:_) = True
startsWithWinter _ = False

sn Winter = 0
sn Spring = 1
sn Summer = 2
sn Autumn = 3

sbn  0 = Winter
sbn  1 = Spring
sbn  2 = Summer
sbn  3 = Autumn

data Point = Point Double Double
    deriving(Show,Eq)

data Shape = Circle Double | Rectangle {a::Double, b::Double}
    deriving(Show)

area :: Shape -> Double
area (Circle r) = pi * r * r
area (Rectangle a b) = a * b

data MyIntList = L Int MyIntList | Empty 
    deriving(Show)

mynull :: MyIntList -> Bool
mynull Empty = True
mynull _ = False

myhead :: MyIntList -> Int
myhead (L h t) = h

mytail :: MyIntList -> MyIntList
mytail (L h t) = t

myshow :: MyIntList -> String
myshow Empty = "$"
myshow (L h t) = (show h) ++ ":" ++ (myshow t)

data Point a = Point a a

