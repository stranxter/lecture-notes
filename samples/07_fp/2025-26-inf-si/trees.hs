
data BTree a = Empty | Node a (BTree a) (BTree a)
  deriving Show

data Directrion = L | R
   deriving (Eq, Show)
type Trace = [Directrion]

mytree = Node 7
           (Node 30 
                 (Node 15 Empty Empty)
                 (Node 3 Empty Empty))
           (Node 77
                 Empty
                 (Node 15
                       (Node 70 Empty Empty)
                       Empty))

trace :: Eq a => BTree a -> a -> Maybe Trace
trace Empty _ = Nothing
trace (Node root left right) e
    |root == e = Just []
    |otherwise = case lt of
                 (Just t) -> Just $ L:t
                 Nothing -> case rt of
                            (Just t) -> Just $ R:t
                            Nothing -> Nothing  
    where lt = trace left e
          rt = trace right e

telem :: Eq a => BTree a -> a -> Bool
telem Empty _ = False
telem (Node x left right) e = x == e || telem left e || telem right e

tsum :: Num a => BTree a -> a
tsum Empty = 0
tsum (Node x left right) = x + (tsum left) + (tsum right)

insert :: BTree a -> a -> Trace -> BTree a
insert (Node _ l r) x [] = Node x l r
insert Empty x [] = Node x Empty Empty 
insert (Node root left right) x (R:xs) = Node root left (insert right x xs)
insert (Node root left right) x (L:xs) = Node root (insert left x xs) right

insertBOT :: Ord a => BTree a -> a -> BTree a
insertBOT Empty x = Node x Empty Empty
insertBOT (Node r lt rt) x
   |x < r = Node r (insertBOT lt x) rt
   |otherwise = Node r lt (insertBOT rt x)

testBOT = insertBOT (insertBOT (insertBOT (insertBOT (insertBOT Empty 100) 30) 50) 200) 25

search :: Ord a => BTree a -> a -> Bool
search Empty _ = False
search (Node r lt rt) x = r == x || 
                         (x < r) && search lt x || 
                         (x > r) && search rt x

flatten :: BTree a -> [a]
flatten Empty = []
flatten (Node r lt rt) = (flatten lt) ++ [r] ++ flatten rt


mint :: Ord a => BTree a -> a
mint (Node r Empty _) = r
mint (Node _ lt _) = mint lt

maxt :: Ord a => BTree a -> a
maxt (Node r _ Empty) = r
maxt (Node _ _ rt) = maxt rt


delBOT :: Ord a => BTree a -> a -> BTree a
delBOT Empty _ = Empty
delBOT (Node r Empty rt) x 
   |r == x = rt
   |otherwise = Node r Empty (delBOT rt x)
delBOT (Node r lt Empty) x 
   |r == x = lt
   |otherwise = Node r (delBOT lt x) Empty
delBOT (Node r lt rt) x
   |x < r = Node r (delBOT lt x) rt
   |x > r = Node r lt (delBOT rt x)
   |otherwise = Node newroot lt (delBOT rt newroot)
   where newroot = mint rt

(!<) Nothing _ = True
(!<) (Just min) x = min < x

(<=!) _ Nothing = True
(<=!) x (Just max) = x <= max

inInterval :: Ord  a => a -> Maybe a -> Maybe a -> Bool
inInterval x min max = min !< x && x <=! max

isBOT :: Ord a => BTree a -> Bool
isBOT t = isBOTh t Nothing Nothing

isBOTh :: Ord a => BTree a -> Maybe a -> Maybe a -> Bool
isBOTh Empty _ _ = True
isBOTh (Node r lt rt) intmin intmax = inInterval r intmin intmax &&
                                      (isBOTh lt intmin (Just r)) &&
                                      (isBOTh rt (Just r) intmax)

toScheme :: Show a => BTree a -> String
toScheme Empty = "()"
toScheme (Node r lt rt) = "(" ++ (show r) ++ " " ++ toScheme lt ++ " " ++ toScheme rt ++ " )"

prettyPrint :: Show a => BTree a -> Int -> IO()
prettyPrint Empty _ = do
                     return ()
prettyPrint (Node r lt rt) currentDepth = do
     prettyPrint lt (currentDepth+1)
     putStrLn $ (replicate (2*currentDepth) ' ') ++ (show r)
     prettyPrint rt (currentDepth+1)

-- (71267 (30 (15 () () ) (3 () () ) ) (77 () (15 (70 () () ) () ) ) )
--                                                                  ^
--                                                                  |

testtr = "(71267 (30 (15 () () ) (3 () () ) ) (77 () (15 (70 () () ) () ) ) )"

fromScheme :: String -> (BTree Int, String)
fromScheme ('(':')':rest) = (Empty,rest)
fromScheme ('(':rest) = (Node root lt rt,remaining)
            where rootString = takeWhile (/=' ') rest
                  root = read rootString
                  (lt,rest') = fromScheme $ dropWhile (/='(') rest
                  (rt,rest'') = fromScheme $ tail rest'
                  remaining = drop 2 rest''



