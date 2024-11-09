import Data.List
import Data.Maybe

data Gender = M | F
    deriving (Show,Eq)
data Person = Person {name :: String, gender:: Gender, birthdate :: (Int,Int,Int)}
    deriving (Show,Eq)

people :: [Person] = 
    [Person {name = "Kalin Georgiev", gender = M, birthdate = (01,01,1981)},
     Person {name = "Ivan Petrov", gender = M, birthdate = (01,01,2002)},
     Person {name = "Maria Ivanova", gender = F, birthdate = (05,05,2003)},
     Person {name = "Ivana Marinova", gender = F, birthdate = (20,02,2000)}]

doybefore (d1,m1) (d2,m2) = m1 < m2 || (m1 == m2 && d1 < d2)
yearsdiff today@(d',m',y') (d,m,y) = y' - y - (if doybefore (d,m) (d',m') then 0 else 1)

reverse' :: [a] -> [a]
reverse' = foldl (flip (:)) []

allpairs = iterate (\(x, y) -> if y < x then (x, y+1) else (x+1,0)) (0, 0)
fibs = unfoldr (\(x, y) -> Just (x, (y, x + y))) (0, 1)

--unfoldr (\b -> if b == 0 then Nothing else Just (b, b-1)) 10



type Pos = (Int, Int)
data Tile = Road | Wall | Gold
            deriving (Show, Eq)
data Game = Game { pos :: Pos, world :: [[Tile]] }
            deriving (Show)


myWorld :: Game = Game { pos = (0, 0), world = [[Road, Wall, Gold], 
                                                [Road, Wall, Road], 
                                                [Road, Road, Road]] }

foundGold  (Game (x,y) w) = (w !! y) !! x == Gold
stuck  (Game (x,y) w) = dead w (x, y)

dead :: [[Tile]] -> Pos -> Bool
dead w (x, y) = x < 0 || x >= length w ||
                y < 0 || y >= length w || 
                (w !! y) !! x == Wall

move :: Game -> (Pos -> Pos) -> Maybe Game
move (Game p w) mv = if dead w (mv p) then Nothing else Just $ Game (mv p) w

left g = move g (\(x, y) -> (x-1, y))
right g = move g (\(x, y) -> (x+1, y))
up g = move g (\(x, y) -> (x, y-1))
down g = move g (\(x, y) -> (x, y+1))

--findGold :: game visited -> path
findGold :: Maybe Game -> [Pos] -> Maybe [Pos]
findGold Nothing _ = Nothing
findGold (Just g@(Game p w)) visited
    | foundGold g = Just [p]
    | (stuck g) || (elem p visited) || null routes = Nothing
    | otherwise = Just $ p : (head routes)
    where routes = mapMaybe ((flip findGold) (p:visited))
                            [down g, right g, up g, left g] 