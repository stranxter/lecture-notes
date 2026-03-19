import Data.List

_filter :: (Int->Bool) -> [Int] -> [Int]
_filter _ [] = []
_filter pred (x:xs)
   | pred x = x : (_filter pred xs)
   | otherwise = _filter pred xs

choice arg pred iftrue iffalse = if (pred arg) then iftrue else iffalse

div4 x = mod x 10 == 4

--inters [1,2,3] [2,3] -> [2,3]
inters [] _ = []
inters _ [] = []
inters (x:xs) l = if elem x l then x:(inters xs l) else (inters xs l)

-- l1 - l2
diff l1 l2 = filter (\x-> not $ elem x l2) l1

--intf l1 l2 = filter (\x->elem x l2) l1
intf l1 l2 = filter ((flip elem) l2) l1


--splite [1,2,3,4,5,6] -> ([1,3,5,7],[2,4,6,8])

--splite [] n = ([],[])
--splite (x:xs) n = let (l,r) = (splite xs (n+1)) in if odd n then (x:l,r) else (l,x:r)

splite l = let lt = map fst  $ filter (\(_,c)->odd c) (zip l [1..])
               rt = map fst  $ filter (\(_,c)->even c) (zip l [1..])
               in (lt,rt)

_zip _ [] = []
_zip [] _ = []
_zip (x:xs) (y:ys) = (x,y) : (zip xs ys)

--map [] _ = []
--map (x:xs) f = (f x):(map xs f)


--вторите степени само на четните числа
p2evens l = map (\x->x^2) (filter even l)

--foldr (+) 0 [1..10]

_foldr _ nv [] = nv
_foldr f nv (x:xs) = f x (_foldr f nv xs)

elemf e l = foldr (\current accumulated->(current==e) || accumulated) False l

    --elemf 7 [1,35,64,567,879,7,2345]


mapf f l = foldr (\current accumulated->(f current):accumulated) [] l
filterf p l = foldr (\current accumulated->if p current then current:accumulated else accumulated)  [] l

students :: [(String,Int,[Int])] =   [("Ivan",42424,[6,6,5,6]),
                                      ("Maria",757575,[6,6,6,6,6,6]),
                                      ("Kalin",2424,[5,5])]

studenttoexamine l = let  countgrades = map (\(name,fn,grades)->(name,length grades)) l
                          mingradecount = minimum $ map (\(_,c)->c) countgrades
                          fewestgrades = filter (\(_,c)->c==mingradecount) countgrades
                          in fst $ head fewestgrades

--

average l = div (sum l) (length l)

bestGrade s = head $ reverse $ sort $ map (\(_,_,grades)->average grades) s

allpairs = concat [ if x==y then [(x,y)] else  [(x,y),(y,x)] |x<-[0..],y<-[0..x]]

power n = \x -> x ^ n -- flip (^) n -- (^n)


--curry f x = \y->f x y

--negate p --(negate even) 7 -> True

negate p = \x -> not $ p x

-- (cut (\x->x*x) 0) 10 -> 100
-- (cut (\x->x*x) 0) (-10) -> 0

cut :: (Int->Int) -> Int -> (Int->Int)
cut f z = \x->if x >= z then f x else 0

restrict :: (Int->Int) -> Int -> Int -> (Int->Int)
--restrict f ymin ymax
restrict f ymin ymax = \x->if f x > ymax then ymax else
                           if f x < ymin then ymin else f x
--restrict f ymin ymax = \x->min ymax (max ymin (f x))

rsq = restrict (\x->x*x) 5 25
--rsq 4 -> 16
--rsq (-6) -> 25 (а не 36)

--sumf f g

sq x = x*x
cube x = x*x*x

sumf::(Int->Int)->(Int->Int)->(Int->Int)
sumf f g = \x -> (f x) + (g x)

--newf = sumf sq cube

--newf 10 -> 1100 (1000 + 100)

switch::(Int->Int)->(Int->Int)->(Int->Bool)->(Int->Int)
switch f g p = \x -> if p x then f x else g x

--s1 = switch sq cube even
--s1 4 -> 16
--s1 5 -> 125


maxf::(Int->Int)->(Int->Int)->(Int->Int)
maxf f g = \x -> max (f x) (g x)

maxfl::[(Int->Int)]->(Int->Int)
maxfl l = \x-> maximum $ map (\f->f x) l





