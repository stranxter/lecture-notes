
data Gender = M | F
    deriving (Show, Eq)

data Person = Person {name :: String,
                      birthdate :: (Int,Int,Int),
                      gender :: Gender,
                      height :: Float}
                deriving (Show)


people = [Person {name = "Ivan Petrov",birthdate = (1998,01,01),gender = M,height = 185},
          Person {name = "Petar Ivanov", birthdate = (2002,05,01),gender = M,height = 179},
          Person {name = "Maria Ivanova",birthdate = (2003,06,11),gender = F,height = 182},
          Person {name = "Ivan Marinova",birthdate = (2003,01,01),gender = F,height = 193}]


data Point = Point Float Float
    deriving (Show, Eq)

getname (Person name  _  _  _) = name

intersection l1 l2 = filter ((flip elem) l2) l1

myunion l1 l2 = l1 ++ filter (\e -> not (elem e l1)) l2
-- l1 ++ diff (l2 l1)

mydiff l1 l2 = filter (\e -> not (elem e l2)) l1

haseven l = elem True (map even l)

fns = [(+1), (*2), (\x -> x * x)]

--брой на елементите от списъка с функции l,
--чиито стойности в точката x са по-големи от y
gtf l x y = length $ filter (\f -> f x > y) l

countelem e l = foldr (\x sum -> sum + (if x == e then 1 else 0)) 0 l

myelem e l = foldr (\x sum -> (x == e) || sum) False l

mymap f l = foldr (\x accum -> (f x) : accum) [] l

myfilter p l = foldr (\x accum -> if p x then x : accum else accum) [] l 

--myreverse l = foldl (flip (:)) [] l
myreverse l = foldl (\accum x -> x : accum) [] l

fib = iterate (\(a,b) -> (b,a+b)) (1,1)

next (x,y) = (if x <= y then x+1 else x,if x <= y then 0 else y+1)