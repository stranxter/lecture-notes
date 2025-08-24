import Data.List
import Data.Maybe

class CSVSerializable a where
    columns :: a -> [String]
    value :: String -> Maybe (a -> String)

data Gender = M | F
    deriving (Show,Eq,Read)
data Person = Person { name :: String
                     , gender:: Gender
                     , birthdate :: (Int,Int,Int)
                     }
    deriving (Show,Eq,Read)

people :: [Person] = 
    [Person {name = "Kalin Georgiev", gender = M, birthdate = (01,01,1981)},
     Person {name = "Ivan Petrov", gender = M, birthdate = (01,01,2002)},
     Person {name = "Maria Ivanova", gender = F, birthdate = (05,05,2003)},
     Person {name = "Ivana Marinova", gender = F, birthdate = (20,02,2000)}]


instance CSVSerializable Person where
    columns p = ["name", "gender", "birthdate"]
    value "name" = Just (name)
    value "gender" = Just (show . gender)
    value "birthdate" = Just (show . birthdate)
    value _ = Nothing

 
toCSV :: CSVSerializable a => [a] -> String
toCSV [] = ""
toCSV list = let cols = columns (head list) in
             (intercalate "," cols) ++ "\n" ++
             (intercalate "\n" $ map row list)

row :: CSVSerializable a => a -> String
row p = let cols = columns p 
            vals = mapMaybe value cols in
            intercalate "," $ map (\v -> v p) vals
         --   intercalate "," $ map (flip ($) p) vals


data Country = Country { cname :: String
                       , capital :: String
                       }
    deriving (Show,Eq,Read)

countries = [Country {cname = "Bulgaria", capital = "Sofia"},
             Country {cname = "Germany", capital = "Berlin"},
             Country {cname = "France", capital = "Paris"},
             Country {cname = "Italy", capital = "Rome"}]

instance CSVSerializable Country where
    columns c = ["name", "capital"]
    value "name" = Just (cname)
    value "capital" = Just (capital)
    value _ = Nothing
