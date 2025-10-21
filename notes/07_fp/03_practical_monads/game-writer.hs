import Control.Monad.Writer

type Pos = (Int, Int)
data Tile = Road | Wall | Gold
            deriving (Show, Eq)
data Game = Game { pos :: Pos, world :: [[Tile]] }
            deriving (Show)

state0 :: Game = Game { pos = (0, 0), world = [[Road, Wall, Gold], 
                                               [Road, Wall, Road], 
                                               [Road, Road, Road]] }

dead :: [[Tile]] -> Pos -> Bool
dead w (x, y) = x < 0 || x >= length w ||
                y < 0 || y >= length w || 
                (w !! y) !! x == Wall

move :: Game -> (Pos -> Pos) -> Game
move (Game (x,y) w) mv = Game (newx,newy) w where (newx,newy) = mv (x,y)

left :: Game -> Writer [String] Game
left g = tell ["Moved left"] >> return (move g (\(x, y) -> (x-1, y)))

right :: Game -> Writer [String] Game
right g = tell ["Moved right"] >> return (move g (\(x, y) -> (x+1, y)))

up :: Game -> Writer [String] Game
up g = tell ["Moved up"] >> return (move g (\(x, y) -> (x, y-1)))

down :: Game -> Writer [String] Game
down g = tell ["Moved down"] >> return (move g (\(x, y) -> (x, y+1)))
  
