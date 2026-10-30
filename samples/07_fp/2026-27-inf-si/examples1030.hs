firstevens n = take n $ [0,2..]

factlist n lastFact = current : factlist (n + 1) current 
                      where current = n * lastFact

fibList a b = a : fibList b (a+b)

ones = 1 : ones

nats = 1 : (map (+1) nats)

fibList2 = 1 : 1 : zipWith (+) fibList2 (tail fibList2)

count x l = length $ filter (==x) l

histogram [] = []
histogram (x:xs) = (x, count x (x:xs)) : (histogram (filter (/=x) xs))

alphabet = ['a'..'z']++['A'..'Z']++['0'..'9']

h2 l = unique $ [(c,count c l) | c <- l]

unique [] = []
unique (x:xs) = let rest = unique xs in if elem x xs then rest else x:rest

data Season = Winter | Spring | Summer | Autumn
    deriving(Eq,Ord,Show)

seasonn Spring = 1
seasonn Summer = 2
seasonn Autumn = 3
seasonn Winter = 4

data Point = Point Double Double
    deriving(Eq,Ord,Show)

data Shape = Circle Point Double | 
             Rectangle Point Double Double | 
             Triangle Point Point Point |
             Group [Shape]
    deriving(Eq,Ord,Show)

shapes :: [Shape] = [Circle (Point 0 0) 1.0, 
                     Rectangle (Point 0 0) 2 3, 
                     Circle (Point 0 0) 2.0]

--myf x y = Rectangle (x+1) (y+1)

--functions :: [Double->Double->Shape] = [Rectangle,myf]

--data Student = Student String Int Double
data Person = Student {name::String, fn::Int, grade::Double} |
              Teacher {name::String}
       deriving(Show)

myname (Student n _ _) = n
myname (Teacher n) = n
{-
area :: Shape -> Double
area (Circle r) = 3.14 * r * r
area (Rectangle a b) = a * b
-}

boy = Group [Circle (Point 20 100) 5, Rectangle (Point 20 40) 20 30]
girl = Group [Circle (Point 70 100) 5, Triangle (Point 70 90) (Point 50 20) (Point 90 20)]

picture = Group [boy, girl, Rectangle (Point 20 50) 100 100]

tag :: Shape -> String
tag (Circle (Point x y) r) = "<circle cx=\"" ++ show x ++ "\"" ++
                                    " cy=\"" ++ show y ++ "\"" ++
                                    " r=\"" ++ show r ++ "\"" ++
                                    " fill = \"none\" stroke = \"black\"/>\n"
tag (Rectangle (Point x y) w h) 
                            =  "<rect x=\"" ++ show x ++ "\"" ++
                                    " y=\"" ++ show y ++ "\"" ++
                                    " width=\"" ++ show w ++ "\"" ++
                                    " height=\"" ++ show h ++ "\"" ++
                                    " fill = \"none\" stroke = \"black\"/>\n"

tag (Triangle (Point x1 y1) (Point x2 y2)  (Point x3 y3)) 
                            =  "<polygon points=\"" ++ show x1 ++ ", "
                                                    ++ show y1 ++ ", "
                                                    ++ show x2 ++ ", "
                                                    ++ show y2 ++ ", "
                                                    ++ show x3 ++ ", "
                                                    ++ show y3 ++ "\"" ++
                                    " fill = \"none\" stroke = \"black\"/>\n"

tag (Group shapes) = concat $ map tag shapes




