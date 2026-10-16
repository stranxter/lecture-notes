maxlist [x] = x
maxlist (x:xs) = max x (maxlist xs) 

inc [] = []
inc (x:xs) = (x+1) : (inc xs)

{-incevens [] = []
incevens (x:xs)  
    | even x = (x+1) : rest
    | otherwise = x : rest
    where rest = (incevens xs)-}

incevens [] = []
incevens (x:xs) = (if even x then x+1 else x):(incevens xs) 


--multiplyall [] [] = []
multiplyall [] _ = []
multiplyall _ [] = []
multiplyall (x:xs) (y:ys) = (x*y) : (multiplyall xs ys)

--prefix ::= take

--prefix n l
prefix _ [] = []
prefix 0 _ = []
prefix n (x:xs) = x : prefix (n-1) xs

--dups -> True или False в зависимост дали в списъка има повторение на елементи

dups [] = False
--dups (x:xs) = (dups xs) || (elem x xs)
dups (x:xs) = (elem x xs) || (dups xs)

alldups [] = []
alldups (x:xs) = let rest = (alldups xs) in if elem x xs then x:rest else rest

{-
myElem x [] = False
myElem x (h:t) = x == h || (myElem x t)

hasEvens [] = False
hasEvens (x:xs) = even x || (hasEvens xs)

hasSpecial [] = False
hasSpecial (x:xs) = (x > 5 && x < 10) || hasSpecial xs
-}
--find p l
find :: (a->Bool) -> [a] -> Bool
find _ [] = False
find p (x:xs) = p x || find p xs

myMap :: (a->b) -> [a] -> [b]
myMap f [] = []
myMap f (x:xs) = (f x) : (myMap f xs)

group = [("Kalin", 5, "FP"), ("Maria",6,"OOP"), ("Ivan", 4, "FP"), ("Petya",5,"OOP"),("Stoyna",6,"Algebra")]

maxgrade l = maximum $ map (\(_,g,_)->g) l

maxgradesubj l subj = maxgrade $ filter (\(_,_,s)->s==subj) l 

maxgradesubjs l subjs = maxgrade $ filter (\(_,_,s)-> elem s subjs) l 

beststudents l subj = let mg = maxgradesubj l subj in filter (\(_,g,s) -> g==mg && s == subj) l


{----------------}

myfoldr1 :: (a->a->a) -> [a] -> a
myfoldr1 f [x] = x
myfoldr1 f (x:xs) = f x (myfoldr1 f xs)

myfoldr :: (a->a->a) -> a -> [a] -> a
myfoldr f null_val [] = null_val
myfoldr f  null_val (x:xs) = f x (myfoldr f null_val xs)


l = [253,645,85,965,7643,634,35,42323,435,6,45765,87,9670,567,44,123,235,645678]

countall l = foldr (\current accum->1+accum) 0 l
countevens l = foldr (\current accum->(if even current then 1 else 0)+accum) 0 l
hasevens l = foldr (\current accum->accum || (even current)) False l
