import Data.List
import Data.Maybe
import Data.Char

data Gender = M | F
    deriving (Show,Eq,Read)
data Person = Person {name :: String, gender:: Gender, birthdate :: (Int,Int,Int)}
    deriving (Show,Eq,Read)

people :: [Person] = 
    [Person {name = "Kalin Georgiev", gender = M, birthdate = (01,01,1981)},
     Person {name = "Ivan Petrov", gender = M, birthdate = (01,01,2002)},
     Person {name = "Maria Ivanova", gender = F, birthdate = (05,05,2003)},
     Person {name = "Ivana Marinova", gender = F, birthdate = (20,02,2000)}]

daybefore (d1,m1) (d2,m2) = m1 < m2 || (m1 == m2 && d1 < d2)
yearsdiff today@(d',m',y') (d,m,y) = y' - y - (if daybefore (d,m) (d',m') then 0 else 1)

test = do
    line1 <- getLine
    let h1 = head line1
    putStrLn $ "First letter: " ++ [h1]
    line2 <- getLine
    let h2 = head line2
    putStrLn $ "Second letter: " ++ [h2]
    let ascii = max (ord h1) (ord h2)
    putStrLn $ "Max ascii: " ++ (show ascii)
    return ascii


split :: (a->Bool) -> [a] -> [[a]]
split p [] = []
split p xs = first : rest
    where
        (first, next) = break p xs 
        rest = case next of
            [] -> []
            x -> split p (tail x)

readPerson :: String -> Person
readPerson s = Person {name = name,
                       gender = read gender,
                       birthdate = (read d, read m, read y)}
               where
                [name,gender,dmy] = split (==',') s
                [d,m,y] = split (=='-') dmy

writePerson :: Person -> String
writePerson p = name p ++ "," ++ 
                show (gender p) ++ "," ++
                show d ++ "-" ++ show m ++ "-" ++ show y
                where
                    (d,m,y) = birthdate p

readPeople :: IO ([Person])
readPeople = do
    contents <- readFile "data.csv"
    return $ map readPerson $ lines contents