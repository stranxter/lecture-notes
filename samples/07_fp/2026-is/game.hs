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


move :: Game -> (Pos -> Pos) -> Maybe Game
move (Game p w) mv = if dead w (mv p) then Nothing else Just $ Game (mv p) w

left g = move g (\(x, y) -> (x-1, y))
right g = move g (\(x, y) -> (x+1, y))
up g = move g (\(x, y) -> (x, y-1))
down g = move g (\(x, y) -> (x, y+1))



--(->>) :: Game -> (Game->Game) -> Game
g ->> f = f g
{--
Nothing >= f = Nothing
Just x >= f = f x
--}

--state0 ->> down 

