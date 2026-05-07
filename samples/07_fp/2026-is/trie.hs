


data Trie a = Empty | TrieNode (Maybe a) [(Char,Trie a)]
    deriving(Eq,Show)


replace :: Eq kt => [(kt,vt)] -> kt -> vt -> [(kt,vt)]
replace [] k v = [(k,v)]
replace ((hk,hv):xs) k v = if hk == k then (k,v):xs else (hk,hv):(replace xs k v)


children :: Trie a -> [(Char,Trie a)]
children (TrieNode _ c) = c

ins :: Trie a -> String -> a -> Trie a

ins Empty "" v = TrieNode (Just v) []
ins (TrieNode _ c) "" v = TrieNode (Just v) c

ins Empty (x:xs) nv = TrieNode Nothing [(x,ins Empty xs nv)] 
ins (TrieNode rv children) (x:xs) nv = 
    case (lookup x children) of
        Nothing -> TrieNode rv ((x,ins Empty xs nv):children)
        Just x_child -> TrieNode rv (replace children x (ins x_child xs nv)) 

trieLookup :: Trie a -> String -> Maybe a
trieLookup Empty _ = Nothing
trieLookup (TrieNode rv children) "" = rv
trieLookup (TrieNode _ children) (x:xs) = 
    case (lookup x children) of
        Nothing -> Nothing
        Just x_child -> trieLookup x_child xs
    
{--
ins (TrieNode rv children) (x:xs) nv = TrieNode rv (replace children x (ins x_child xs nv)) 
    where x_child = case (lookup children x) of
                    Nothing -> Empty
                    Just t -> t
        --}



t = ins (ins (ins (ins (ins Empty "to" 7) "tea" 3) "ted" 4) "ten" 12) "A" 15

--trieLook t "tea" -> 3