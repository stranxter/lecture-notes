type Pos = (Int, Int)
  
data Tile = Road | Wall | Gold
            deriving (Show, Eq)
  
data Game = Game { pos :: Pos, world :: [[Tile]]}
            deriving (Show)
  
state0 :: Game = Game { pos = (0, 0), 
                        world = [[Road, Wall, Gold], 
                                 [Road, Wall, Road], 
                                 [Road, Road, Road]]}

data ErrorInfo = ErrorInfo String Pos
    deriving (Show)

move :: Game -> (Pos->Pos) -> Either ErrorInfo Game
move (Game p w) step
  | newx < 0 || newx >= length w ||
    newy < 0 || newy >= length w       = Left $ ErrorInfo "Dropped offworld." (newx,newy)
  | (w !! newy) !! newx == Wall        = Left $ ErrorInfo "Hit a wall." (newx,newy)
  | otherwise                          = Right $ Game (newx,newy) w
  where (newx,newy) = step p

left:: Game -> Either ErrorInfo Game
left g = move g (\(x,y)->(x-1,y))
right:: Game -> Either ErrorInfo Game
right g = move g (\(x,y)->(x+1,y))
up:: Game -> Either ErrorInfo Game
up g = move g (\(x,y)->(x,y-1))
down:: Game -> Either ErrorInfo Game
down g = move g (\(x,y)->(x,y+1))

(->>) :: Game->(Game->Game)->Game
g ->> t = t g

dead :: [[Tile]] -> Pos -> Bool
dead w (x, y) = x < 0 || x >= length w ||
                y < 0 || y >= length w || 
                (w !! y) !! x == Wall

  
