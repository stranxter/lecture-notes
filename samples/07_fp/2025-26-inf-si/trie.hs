
type Assoc k v = [(k,v)]

data Trie v = Empty | Node (Maybe v) (Assoc Char (Trie v))
    deriving(Show)


testrie = Node Nothing [
                         ('t',Node Nothing [
                                             ('o',Node (Just 7) [])
                                           ])
                       ]

trielookup :: String -> Trie v -> Maybe v
trielookup _ Empty = Nothing
trielookup "" (Node mv children) = mv
{-
trielookup (c:cs) (Node mv children) =
  case (lookup c children) of
     Nothing -> Nothing
     (Just child) -> trielookup cs child 
-}      
trielookup (c:cs) (Node mv children) = (lookup c children) >>= (trielookup cs)


trieinsert :: String -> v -> Trie v -> Trie v
trieinsert "" v Empty = Node (Just v) []
trieinsert "" v (Node mv children) = Node (Just v) children
trieinsert (c:cs) v Empty = Node Nothing [(c,trieinsert cs v Empty)]
trieinsert (c:cs) v (Node mv children) = 
    case lookup c children of
        Nothing -> (Node mv ((c,newchild):children))
        (Just subtree) -> Node mv $ assocupdate children c (trieinsert cs v subtree)
    where newchild = trieinsert cs v Empty

assocupdate :: Eq k => Assoc k v -> k -> v -> Assoc k v
assocupdate [] k v = [(k,v)]
assocupdate ((ek,ev):rest) k v
     |ek == k = (ek,v):rest
     |otherwise = (ek,ev):(assocupdate rest k v)