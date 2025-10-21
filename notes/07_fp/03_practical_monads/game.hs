type Pos = (Int, Int)
data Tile = Road | Wall | Gold
            deriving (Show, Eq)
data Game = Game { pos :: Pos, world :: [[Tile]] }
            deriving (Show)

state0 :: Game = Game { pos = (0, 0), world = [[Road, Wall, Gold], 
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

movee :: Game -> (Pos -> Pos) -> Either String Game
movee (Game (x,y) w) mv 
  | newx < 0 || newx >= length w ||
    newy < 0 || newy >= length w       = Left "Dropped offworld."
  | (w !! newy) !! newx == Wall        = Left "Hit a wall."
  | otherwise                          = Right $ Game (newx,newy) w
  where (newx,newy) = mv (x,y)

left g = movee g (\(x, y) -> (x-1, y))
right g = movee g (\(x, y) -> (x+1, y))
up g = movee g (\(x, y) -> (x, y-1))
down g = movee g (\(x, y) -> (x, y+1))
