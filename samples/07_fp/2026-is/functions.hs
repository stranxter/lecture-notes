--fact x = if x > 1 then x * fact (x -1) else x

mult 0 _ = 0
mult 1 y = y
mult x y = y + mult (x - 1) y

my1 (x,y,z) = x
my2 (x,y,z) = y
my3 (x,y,z) = z

-- [1,2,3,4,5,6,7,7,8,9] 7 -> (6,2,2)

--split l n
{--
split [] _ = (0,0,0)
split l n = let t = split (tail l) n in -- t = (10,20,30)
               if head l < n then (my1 t + 1, my2 t, my3 t)  else
                  if head l == n then (my1 t, my2 t + 1, my3 t) else 
                      (my1 t, my2 t, my3 t + 1)
--}

split [] _ = (0,0,0)
split l n  
        |head l < n = (smaller + 1, equal, bigger)
        |head l == n = (smaller, equal + 1, bigger)
        |otherwise = (smaller, equal, bigger + 1)
        where (smaller,equal,bigger) = split (tail l) n
                                   

--mylen l
mylen [] = 0
mylen (x:xs) = 1 + mylen xs

check [1,x,3] = x
check _ = 0

--progression l : [1,2,3,4,..]

{--
prog [] = True
prog [_] = True
prog (x:y:xs) = if x >= y then False
                          else prog (y:xs)

--}

prog [] = True
prog [_] = True
prog (x:t@(y:xs)) = if x >= y then False
                          else prog t


sum [] = 0
--sum [x] = x
sum (x:xs) = x + sum xs

maxl [x] = x
maxl (x:xs) = max x (maxl xs)

--find l x
find [] _ = False
find (x:xs) s
    |x == s = True
    |otherwise = find xs s