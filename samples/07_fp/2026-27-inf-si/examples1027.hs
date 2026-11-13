rev l = foldl (\accum current -> current : accum) [] l

myfoldl :: (b->a->b) -> b -> [a] ->b
--myfoldl op nullv list 

myfoldl _ nullv [] = nullv
myfoldl op nullv (x:xs) = myfoldl op (op nullv x) xs

suml [] = 0
suml (x:xs) = x + suml xs

sumlt [] s = s
sumlt (x:xs) s  = sumlt xs (s+x)

splitl :: (a->Bool) -> [a] -> ([a],[a])
-- split even [42,35,46,57,8,732,5325,234,24]

--splithelp pred list yes no

splitl pred list = splithelp pred list [] []

splithelp _ [] yes no = (yes,no)
{-splithelp pred (x:xs) yes no = splithelp pred xs (if pred x then x:yes else yes) 
                                                 (if pred x then no else x:no)-}

splithelp pred (x:xs) yes no = if pred x then splithelp pred xs (x:yes) no
                                         else splithelp pred xs yes (x:no)

sq x = x*x
cube x = x*x*x

lfs = [sq,\x->x,\x->x+1]

makeh f g = \x -> if x > 0 then f x else g x

-- по списък от функции (N->N) връща функция, която получава най-голямата стойност на функциите от списъка за даден аргумент

-- (mafl [sq,cube]) 2 -> 8
-- (mafl [sq,cube]) 0.5 -> 0.25

--maxfl lf = \x -> maximum $ map (\f->f x) lf
maxfl lf = \x -> maximum $ [ f x | f <- lf ]

--(elpred [20..100]) 40 -> True
--(elpred [20..100]) 400 -> False

elpred l = \x -> elem x l

myevenlesthan100 = elpred [0,2..100]

delta = 0.000001

derive f = \x -> ((f (x+delta)) - (f x)) / delta

cube' = derive cube

mult n = \x -> x * n

m10 = mult 10
m100 = mult 100

std::cout << ([n](int x)->int{return x+n;}) 10

