data InfTree type_tag a = Node a (InfTree type_tag a) (InfTree type_tag a) deriving (Show)
  -- GHC will infer `type_tag :: *` here.

-- Type class to associate a tag with its type_tag function
class Generator type_tag a where
  generate :: type_tag -> (a -> (a, a))

-- Create an infinite tree given a type_tag
genTree :: Generator type_tag a => type_tag -> a -> InfTree type_tag a
genTree gen root = Node root (genTree gen left) (genTree gen right)
  where (left, right) = generate gen root

-- Example: Define a specific type_tag tag
data DoubleGen = DoubleGen

-- Example: Associate DoubleGen with a concrete function
instance Generator DoubleGen Int where
  generate _ x = (x * 2, x * 2 + 1)

-- Example usage:
tree1 = genTree DoubleGen 1 :: InfTree DoubleGen Int
-- tree2 = genTree DoubleGen 5 :: InfTree DoubleGen Int
-- Both have the same type: InfTree DoubleGen Int

getroot :: InfTree type_tag a -> a
getroot (Node x _ _) = x

getleft :: InfTree type_tag a -> InfTree type_tag a
getleft (Node _ l _) = l

