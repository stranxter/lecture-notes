import qualified Data.Map as Map

type Assoc k v = [(k,v)]

mylist :: Assoc Int String = [(42860,"Kalin Georgiev"), 
                              (42861,"Ivan Ivanov"), 
                              (42862,"Petar Petrov")]


replace :: Eq k => (k,v) -> Assoc k v -> Assoc k v
replace (k,v) [] = [(k,v)]
replace (k,v) ((k',v'):kvs) 
    |k == k' = (k,v):kvs 
    |otherwise = (k',v'):(replace (k,v) kvs)

emptytrie = Trie Nothing []
data Trie v = Trie (Maybe v) (Assoc Char (Trie v))
    deriving (Show)

addkv :: (String,v) -> Trie v -> Trie v
addkv ("",val) (Trie Nothing children) = Trie (Just val) children
addkv ((c:cs),val) (Trie v children) = 
  case lookup c children of
    Nothing -> Trie v ((c, addkv (cs,val) emptytrie):children)
    Just t -> Trie v $ replace (c, addkv (cs,val) t) children

lookupkv :: String -> Trie v -> Maybe v
lookupkv "" (Trie v _) = v
lookupkv (c:cs) (Trie _ children) = 
  case lookup c children of
    Nothing -> Nothing
    Just t -> lookupkv cs t