import Data.List

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

class CSVSerializable a where
   attributes :: a -> [(String,String)]

dateToString :: (Int,Int,Int) -> String
dateToString (d,m,y) = show y ++ "-" ++ show m ++ "-" ++ show d

instance CSVSerializable Person where
    attributes p = [("name", name p),("gender", show $ gender p),("birthdate",dateToString $ birthdate p)]


toCSV :: CSVSerializable a => [a] -> String
toCSV objects = intercalate "," keys ++ "\n" ++
                (intercalate "\n" $ map values objects)
    where keys = map fst $ attributes (head objects)
          values = (\object -> intercalate "," $ map snd $ attributes object)

data Country = Country { cname :: String
                       , capital :: String
                       }
    deriving (Show,Eq,Read)

countries = [Country {cname = "Bulgaria", capital = "Sofia"},
             Country {cname = "Germany", capital = "Berlin"},
             Country {cname = "France", capital = "Paris"},
             Country {cname = "Italy", capital = "Rome"}]

instance CSVSerializable Country where
    attributes country = [("name", cname country),("capital", capital country)]




