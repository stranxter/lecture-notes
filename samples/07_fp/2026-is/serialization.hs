data Gender = M | F
    deriving (Show,Eq,Read)
data Person = Person {name :: String, 
                      gender:: Gender, 
                      birthdate :: (Int,Int,Int)}
    deriving (Show,Eq,Read)

people :: [Person] = 
    [Person {name = "Kalin Georgiev", gender = M, birthdate = (01,01,1981)},
     Person {name = "Ivan Petrov", gender = M, birthdate = (01,01,2002)},
     Person {name = "Maria Ivanova", gender = F, birthdate = (05,05,2003)},
     Person {name = "Ivana Marinova", gender = F, birthdate = (20,02,2000)}]


kalin = Person {name = "Kalin Georgiev", gender = M, birthdate = (01,01,1981)}


saveToCSV :: [Person] -> String -> IO ()
saveToCSV people file = do
       writeFile file $ toCSVLines people

toCSVLines :: [Person] -> String
toCSVLines people = concat $ map personToString people

dateToString :: (Int,Int,Int) -> String
dateToString (d,m,y) = show y ++ "-" ++ show m ++ "-" ++ show d

personToString :: Person -> String
personToString p = name p ++ "," ++ show (gender p) ++ "," ++ dateToString (birthdate p) ++ "\n"

split :: (Char->Bool) -> String -> [String]
split _ "" = []
split pred s = 
        case rest of
            "" -> [first]
            r -> first : (split pred (tail rest))
        where
           (first,rest) = break pred s

stringToDate :: String -> (Int,Int,Int)
stringToDate s = (read d, read m, read y) 
        where   [y,m,d] = split (=='-') s

stringToPerson :: String -> Person
stringToPerson s =
        Person {name = n, gender = read g, birthdate = stringToDate d}
     where 
          [n,g,d] = split (==',') s


example = do
     x <- readFile "otput.txt"
     let y = head x : "blah"
     return $ y


loadFromFile :: String -> IO [Person]
loadFromFile file = do
    cont <- readFile file
    let peopleStrings = split (=='\n') cont 
    let people = map stringToPerson peopleStrings
    return people



         
