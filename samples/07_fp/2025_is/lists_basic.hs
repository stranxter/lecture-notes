g :: Int -> Int -> Int -> Int
g a b c = a + b + c

mylast :: [a] -> a
mylast l = if null (tail l) 
           then head l 
           else mylast (tail l)


lazy x y = y


myelem x l = if null l 
             then False 
             else if head l == x 
                  then True
                  else myelem x (tail l) 

mylength l = if null l then 0 else 1 + mylentgh (tail l)

count x l = if null l 
            then 0
            else (count x (head l)) + (if head l == x then 1 else 0)