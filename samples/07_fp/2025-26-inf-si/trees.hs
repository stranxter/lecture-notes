
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


insert :: BTree a -> a -> Trace -> BTree a
insert (Node _ l r) x [] = Node x l r
insert Empty x [] = Node x Empty Empty 
insert (Node root left right) x (R:xs) = Node root left (insert right x xs)
insert (Node root left right) x (L:xs) = Node root (insert left x xs) right


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
