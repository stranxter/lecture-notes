listsum :: (Num a) => [a] -> a
listsum [] = 0 
listsum (x:xs) = x + listsum xs 

listmax :: (Ord a) => [a] -> a
listmax [x] = x
listmax (x:xs) = max x (listmax xs)

prog :: (Ord a) => [a] -> Bool
prog [] = True
prog [x] = True
prog (x1:x2:xs) = x1 <= x2 && prog (x2:xs)

find :: (Eq a) => [a]->a->Bool
find [] _ = False
find (x:xs) y = (x == y) || (find xs y) 

range :: (Ord a,Num a) => a -> a -> [a]
range start end
     |start > end = []
     |start == end = [start]
     |otherwise =  start : (range (start + 1) end)


--evens :: [a]->[a]
--Намиране на списък само с четните елементи на списък от числа
--l=[1,2,3], l=[2,3,4]
evens [] = []
evens (x:xs)
   |mod x 2 /= 0 = evens xs
   |otherwise = x : (evens xs)

--incl :: [a]->[a]
--Увеличава всички елементи на списъка с 1
-- inc [1,2,3] -> [3,42,]
inc [] = []
inc (x:xs) = (x+1):(inc xs)

--mae = makealleven
--mae [1,2,3,4,5] -> [2,2,4,4,6]
incevens [] = []
--mae (x:xs) = let rest = mae xs in if even x then x : rest else (x+1):rest
incevens (x:xs) = (if even x then x else x+1):(incevens xs)

--намиране на повтарящи се елементи в списък
--dup [1,2,1,3,5,4,5] -> [1,5]

dup [] = []
dup (x:xs) 
   |elem x xs = x:(dup xs)
   |otherwise = dup xs

--unique [1,2,2,6,5,7,7] -> [1,2,6,5,7]
unique [] = []
unique (x:xs)
    |elem x xs = unique xs
    |otherwise = x : (unique xs)


--count [1,2,3,4,5,3,2,1,2,3,2,1] -> [(1,3),(2,4),..]
count [] = []
count (x:xs) = inccount x (count xs)

--inccount 1 [..,(1,2),...] -> [...,(1,3),....]
inccount x [] = [(x,1)]
inccount x ((num,count):ys) 
        |x == num = (num,count+1):ys
        |otherwise = (num,count):(inccount x ys)


--commonprefix
--commonprefix [1,2,7,4,5,6]  [1,2,7,4,5,6,7,8,9] 

--commonprefix [] [] = []
commonprefix _ [] = []
commonprefix [] _ = []
commonprefix (x:xs) (y:ys)
    |x == y = x:(commonprefix xs ys)
    |otherwise = []









