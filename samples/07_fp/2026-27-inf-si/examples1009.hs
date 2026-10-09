
--fact n = if n > 1 then n * fact (n - 1) else 1

fact 0 = 1                       -- 0 = 5?
fact 1 = 1                       -- 1 = 5?
fact n = n * fact (n - 1)        -- n ::= 5


threeOfFour (0,b,c,d) = succ c
threeOfFour (a,b,c,d) = c -- (a,b,c,d)=(1,"Kalin",'a',6.00)

{-
    1. [] е списък
    2. ако l е списък, а x-елемент, то l2 = x : l е списък (с глава x и опашка l)
-}

l = ["Kalin","Ivan","Mariya"]

myCountK l = snd $ last $  zip l [1..]
myCountB l count = if null l then count else myCountB (tail l) (count + 1)
myCount l = if null l then 0 else 1 + (myCount (tail l))
--mySum l = if null l then 0 else (head l) + (mySum (tail l))

--mySum [1..10]

mySum [] = 0                    --[] = [1..10]
mySum (h:t) = h + (mySum t)     --(h:t) = [1..10]   | h = 1, t = [2..10]

--myElem x l

myElem x [] = False
--myElem x [y] = x == y
myElem x (h:t) = x == h || (myElem x t)

--countElem e l - брой срещания на елемента x в списъка l

--          X : [Z,F,G,H,R,T,Y]

countElem e [] = 0
countElem e (x:xs) = (countElem e xs) + (if e == x then 0 else 1)

-- progression l - дали е подрден в нарестващ ред
-- preogression [1,2,3] -> True
-- preogression [1,2,1] -> False   [5,6,1,2]

progression [] = True
progression [x] = True
progression (e1:e2:t) = e1 < e2 && progression (e2:t)

--int a b 
--int 0 5 = [0,1,2,3,4,5]


int a b = if a > b then [] else a : (int (a+1) b)

--evens l -> само четните числа в списъка l
--evens [1,2,3,4]->[2,4]

evens [] = []
evens (h:t) = let rest = (evens t) in if even h then h : rest else rest