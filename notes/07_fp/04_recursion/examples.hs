
fistdivisor x = divisorhelp x 2

divisorhelp x k 
     | k >= x = x
     | mod x k == 0 = k
     | otherwise = divisorhelp x (k+1)    

divisors 1 = []
divisors x = fistdivisor x : 
             divisors (div x (fistdivisor x))


split [] _ = ([], [])
split (x:xs) pivot 
    | x < pivot = (x:smaller, larger)
    | otherwise = (smaller, x:larger)
    where (smaller, larger) = split xs pivot

qsort [] = []
qsort (x:xs) = qsort smaller ++ [x] ++ qsort larger
    where (smaller, larger) = split xs x




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
findGold :: Maybe Game -> [Pos] -> [Pos]
findGold Nothing _ = []
findGold (Just g@(Game p w)) visited
    | foundGold g = [p]
    | (stuck g) || (elem p visited) = []
    | downpath /= [] = p : downpath
    | rightpath /= [] = p : rightpath
    | uppath /= [] = p : uppath
    | leftpath /= [] = p : leftpath
    where downpath = findGold (down g) (p:visited)
          rightpath = findGold (right g) (p:visited)
          uppath = findGold (up g) (p:visited)
          leftpath = findGold (left g) (p:visited)



suml :: Num a => [a] -> a
suml [] = 0
suml (x:xs) = x + suml xs

sumiter :: Num a => [a] -> a -> a
sumiter [] current = current
sumiter (x:xs) current = sumiter xs (current + x)


splithelp :: Ord a => [a] -> a -> ([a], [a]) -> ([a], [a])
splithelp [] _ current = current
splithelp (x:xs) pivot (smaller, larger) 
                              = splithelp xs pivot (smaller', larger')
    where (smaller', larger') = if x < pivot 
                                then (x:smaller, larger) 
                                else (smaller, x:larger)
