data Gender = M | F
    deriving (Show,Eq)
data Person = Person {name :: String, gender:: Gender, birthdate :: (Int,Int,Int)}
    deriving (Show,Eq)

people :: [Person] = 
    [Person {name = "Kalin Georgiev", gender = M, birthdate = (01,01,1981)},
     Person {name = "Ivan Petrov", gender = M, birthdate = (01,01,2002)},
     Person {name = "Maria Ivanova", gender = F, birthdate = (05,05,2003)},
     Person {name = "Ivana Marinova", gender = F, birthdate = (20,02,2000)}]

doybefore (d1,m1) (d2,m2) = m1 < m2 || (m1 == m2 && d1 < d2)
yearsdiff today@(d',m',y') (d,m,y) = y' - y - (if doybefore (d,m) (d',m') then 0 else 1)