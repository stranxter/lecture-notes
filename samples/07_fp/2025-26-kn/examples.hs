idn :: Int -> Int
idn x = x

f :: Int -> [Int]
f x = x : f x

-- 03436
has5 :: Int -> Bool
has5 x = (x > 0) && (mod x 10 == 5 || has5 (div x 10))

get (x,_,_) 0 = x
get (_,y,_) 1 = y
get (_,_,z) 2 = z


mylen [] = 0 
mylen (_:xs) = 1 + mylen xs

mysum [] = 0 
mysum (x:xs) = x + mysum xs

sum3 [1,2,3] = 6
sum3 [x,y,z] = x + y + z

-- [5,6,1,2] == (x:y:xs) -> x = 5, y = 6, xs = [1,2]

progression [] = True
progression [x] = True
progression (x:y:xs) = x<=y && progression (y:xs)


count _ [] = 0
count y (x:xs) = (count y xs) + if x == y then 1 else 0

mostcommon [x] = (x,1)
mostcommon (x:xs)
   |xn > yn = (x,xn)
   |otherwise = (y,yn)
   where
      xn = 1 + count x xs
      (y,yn) = mostcommon xs

--Истина, ако в списъка има повтарящи се стойности
dup [] = False
dup (x:xs) = elem x xs || dup xs

-- [a,b,c] . [d,e,f] = a*d + b*e + c*f
prod [] [] = 0
prod (x:xs) (y:ys) = x*y + prod xs ys

pref _ [] = []
pref 0 _ = []
pref 1 (x:xs) = [x]
pref n (x:xs) = x:(pref (n-1) xs)

--suf n l = последните n елемента от l

suf _ [] = []
suf n l 
  |n == length l = l
  |otherwise = suf n (tail l)



-- f 5 = 5 : f 5 = 5 : 5 : f5 = 5 : 5 : 5 : f 5 = 5 : 5 : 5 : 5 : f5