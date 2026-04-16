data IntTree = Empty | Node Int IntTree IntTree
    deriving (Show, Eq)

tree1 = Empty

tree2 = Node 10 Empty Empty

tree3 = Node 100
         (Node 20 Empty Empty)
         (Node 120 Empty Empty)

tree4 = Node 100
             (Node 20 Empty Empty)
             (Node 120 Empty 
                             (Node 150 Empty Empty))

leaf1 :: IntTree
leaf1 = Node 4 Empty Empty

mkLeaf :: Int -> IntTree
mkLeaf x = Node x Empty Empty

tree5 :: IntTree
tree5 =
  Node
    1
    ( Node
        2
        (mkLeaf 3)
        (mkLeaf 4)
    )
    ( Node
        5
        Empty
        (mkLeaf 6)
    )

-- дървото от дъската
tree6 :: IntTree
tree6 =
  Node
    1
    Empty
    ( Node
        2
        (mkLeaf 3)
        ( Node
            4
            (mkLeaf 5)
            Empty
        )
    )

sumlist [] = 0
sumlist (x:xs) = x + sumlist xs

sumtree :: IntTree -> Int
sumtree Empty = 0
sumtree (Node x leftt rightt) = x + (sumtree leftt) + (sumtree rightt)

counttree :: IntTree -> Int
counttree Empty = 0
counttree (Node r left right) = 1 + (counttree left) + (counttree right)

elemtree ::  Int -> IntTree -> Bool
elemtree _ Empty = False
elemtree x (Node rt leftt rightt) = x == rt || (elemtree x leftt) || (elemtree x rightt)

countleaves :: IntTree -> Int
countleaves Empty = 0
countleaves (Node r Empty Empty) = 1
countleaves (Node r left right) = 0 + (counttree left) + (counttree right)

heighttree :: IntTree -> Int
heighttree Empty = 0
heighttree (Node _ left right) = 1 + max (heighttree left) (heighttree right) 

--elemtree 200 tree4 -> False
--elemtree 120 tree4 -> True

productTree :: IntTree -> Int
productTree Empty = 1
productTree (Node root left right) =
  root * productTree left * productTree right

-- >>> productTree tree5
-- 720

diameter :: IntTree -> Int
diameter Empty = 0
diameter (Node root left right) =
  maximum [currDiam, leftDiam, rightDiam]
 where
  currDiam = 1 + heighttree left + heighttree right
  leftDiam = diameter left
  rightDiam = diameter right

-- >>> diameter tree5
-- 5

-- >>> diameter tree6
-- 4

preorder :: IntTree -> [Int]
preorder Empty = []
preorder (Node root left right) =
  [root] ++ preorder left ++ preorder right

-- >>> preorder tree5
-- [1,2,3,4,5,6]

postorder :: IntTree -> [Int]
postorder Empty = []
postorder (Node root left right) =
  postorder right ++ postorder left ++ [root]

-- >>> postorder tree5
-- [6,5,4,3,2,1]

data Direction = L | R

-- case-of синтаксисът се използва за pattern matching
fib :: Int -> Int
fib n = case n of
  0 -> 0
  1 -> 1
  m -> fib (m - 1) + fib (m - 2)

insert :: [Direction] -> Int -> IntTree -> IntTree
insert _ x Empty = mkLeaf x
insert [] x (Node _ left right) = Node x left right
insert (dir : dirs) x (Node root left right) =
  case dir of
    L -> Node root (insert dirs x left) right
    R -> Node root left (insert dirs x right)

-- >>> insert [] 10 tree5
-- Node 10 (Node 2 (Node 3 Empty Empty) (Node 4 Empty Empty)) (Node 5 Empty (Node 6 Empty Empty))

-- >>> insert [L,R,L] 15 tree5
-- Node 1 (Node 2 (Node 3 Empty Empty) (Node 4 (Node 15 Empty Empty) Empty)) (Node 5 Empty (Node 6 Empty Empty))

search :: [Direction] -> IntTree -> Int
search _ Empty = error "no element in this position"
search [] (Node root _ _) = root
search (dir : dirs) (Node root left right) =
  case dir of
    L -> search dirs left
    R -> search dirs right

-- >>> search [] tree5
-- 1

-- >>> search [R,R] tree5
-- 6

-- >>> search [R,L] tree5
-- *** Exception: no element in this position
