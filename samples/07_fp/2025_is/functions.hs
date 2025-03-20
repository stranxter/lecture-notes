--fib n = if n < 2 then n else fib (n-1) + fib (n-2)

fib 0 = 1
fib 1 = 1
fib n = fib (n-1) + fib (n-2)


--f 0 5

f 0 1 = 1
f 0 y = 2 
f x 3 = 3
f x y = 4 

g (x,_) = x

get4of6 (_,_,_,x,_,_) = x


magn7 (7:_) = True
magn7 _ = False

--hasone (_:[]) = True
hasone [_] = True
hasone _ = False

sumtail (_:t) = sum t

{-

myzip l1 l2 = if (null l1) || 
                 (null l2) then []
                                else (head l1, head l2) : myzip (tail l1) (tail l2)

-}

myzip [] _ = []
myzip _ [] = []
myzip (h1:t1) (h2:t2) = (h1,h2) : myzip t1 t2

shrink [] = []
shrink [_] = []
shrink (x1:x2:t) = (x1+x2):shrink t

count :: Eq a => a -> [a] -> Int
--count x l = брой срещания на x  в l
count _ [] = 0
count x (y:xs) 
  | x == y = 1 + rest
  | otherwise = rest
  where rest = count x xs

mostcommon [x] = (x,1)
mostcommon (x:xs)
  | xn > yn = (x,xn)
  | otherwise = (y,yn)
  where
       xn = count x (x:xs) 
       (y,yn) = mostcommon xs
           
h x
 | even x = 1
 | x > 10 = 2

mysum [] = 0
mysum (x:xs) = x + mysum xs

dup [] = False
dup (x:xs) = dup xs || elem x xs

mytake 0 _ = []
mytake _ [] = []
mytake n (x:xs) = x : mytake (n-1) xs

common [] _ = []
common _ [] = []
common (x:xs) (y:ys) 
 | x /= y = []
 | otherwise = x : common xs ys 

merge [] l = l
merge l [] = l
merge (x:xs) (y:ys)
  |x < y = x : merge xs (y:ys)
  |otherwise = y : merge (x:xs) ys


p1 [] = []
p1 (x:xs) = (x+1):p1 xs

sql [] = []
sql (x:xs) = (x*x):p1 xs

op1 x = x + 1
opsqx x = x * x 


mymap :: (a->b) -> [a] -> [b]
mymap f [] = []
mymap f (x:xs) = (f x):mymap f xs

sq2 = \x -> x * x