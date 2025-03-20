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

left (Game (x, y) w) = Game (x-1, y) w
right (Game (x, y) w) = Game (x+1, y) w
up (Game (x, y) w) = Game (x, y-1) w
down (Game (x, y) w) = Game (x, y+1) w

(->>) :: Game -> (Game->Game) -> Game
g ->> f = f g