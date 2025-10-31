import Data.List
import Data.Maybe

data Gender = M | F
    deriving (Show,Eq)
data Person = Person {name :: String, gender:: Gender, birthdate :: (Int,Int,Int)}
    deriving (Show,Eq)

people :: [Person] = 
    [Person {name = "Kalin Georgiev", gender = M, birthdate = (01,01,1981)},
     Person {name = "Ivan Petrov", gender = M, birthdate = (01,01,2002)},
     Person {name = "Maria Ivanova", gender = F, birthdate = (05,05,2003)},
     Person {name = "Ivana Marinova", gender = F, birthdate = (20,02,2000)}]

ints x = x : (ints $ x+1)


myfilter :: (a->Bool) -> [a] -> [a]
myfilter _ [] = []
myfilter p (x:xs)
    |p x = x:rest
    |otherwise = rest
    where rest = myfilter p xs

mymap :: (a->b) -> [a] -> [b]
mymap _ []= []
mymap f (x:xs) = (f x) : (mymap f xs)

--foldr (+) 0 [1,2,3] -> (1 +  ( 2 + (3 + 0)))
--foldl (+) 0 [1,2,3] -> (((0 + 1) + 2) + 3) 

myfoldr :: (elemt->accumt->accumt) -> accumt -> [elemt] -> accumt
myfoldr _ nv [] = nv
myfoldr op nv (x:xs) = op x (myfoldr op nv xs)

myfoldl :: (accumt->elemt->accumt) -> accumt -> [elemt] -> accumt
myfoldl op nv [] = nv
myfoldl op nv (x:xs) = myfoldl op (op nv x) xs

mynegate:: (a->Bool)->(a->Bool)
mynegate = (not .)

maxf f g = \x->max (f x) (g x)

switch f g = \choice x->if choice then f x else g x

--maxfl :: [(a->b)] -> (a->b)
--maxfl [f] = f
--maxfl (f:fs) = \x -> max (f x) ((maxfl fs) x)

maxfl l = foldr1 (\f a-> \x -> max (f x)(a x)) l

