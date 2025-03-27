type Pos = (Int, Int)
data Tile = Road | Wall | Gold
            deriving (Show, Eq)

data Game = Game { pos :: Pos, world :: [[Tile]] }
            deriving (Show)

myMap = [[Road, Wall, Gold], 
         [Road, Wall, Road], 
         [Road, Road, Road]]

myGame :: Game = Game { pos = (0, 0), world = myMap }

dead :: [[Tile]] -> Pos -> Bool
dead w (x, y) = x < 0 || x >= length w ||
                y < 0 || y >= length w || 
                (w !! y) !! x == Wall

failgame (Game pos w) = dead w pos

move :: Game -> (Pos -> Pos) -> Maybe Game
move (Game p w) mv
   | dead w moved = Nothing
   | otherwise = Just $ Game moved w
   where moved = mv p

left g = move g (\(x, y) -> (x-1, y))
right g = move g (\(x, y) -> (x+1, y))
up g = move g (\(x, y) -> (x, y-1))
down g = move g (\(x, y) -> (x, y+1))


