data InfTree generator a = Node a (InfTree generator a) (InfTree generator a) deriving (Show)
  -- GHC will infer `generattor :: *` here.

-- Type class to associate a tag with its generator function
class Generator generator a where
  generate :: generator -> (a -> (a, a))

-- Create an infinite tree given a generator
genTree :: Generator generator a => generator -> a -> InfTree generator a
genTree gen root = Node root (genTree gen left) (genTree gen right)
  where (left, right) = generate gen root

-- Example: Define a specific generator tag
data DoubleGen = DoubleGen

-- Example: Associate DoubleGen with a concrete function
instance Generator DoubleGen Int where
  generate _ x = (x * 2, x * 2 + 1)

-- Example usage:
tree1 = genTree DoubleGen 1 :: InfTree DoubleGen Int
-- tree2 = genTree DoubleGen 5 :: InfTree DoubleGen Int
-- Both have the same type: InfTree DoubleGen Int

getroot :: InfTree generator a -> a
getroot (Node x _ _) = x

getleft :: InfTree generator a -> InfTree generator a
getleft (Node _ l _) = l

