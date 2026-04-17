-- за всяко непразно дърво
-- (x, L, R) с корен x, ляво поддърво L и дясно поддърво R
-- е изпълнено, че:
-- за всеки възел y на L: y <= x
-- за всеки възел z на R: x < z
data BST = Empty | Node Int BST BST
  deriving (Show, Eq, Ord)

bst :: BST
bst =
  Node
    2
    (Node 1 Empty Empty)
    (Node 3 Empty Empty)

-- дървото от лекцията (на дъската :D)
bst2 :: BST
bst2 =
  Node
    5
    ( Node
        3
        ( Node
            1
            Empty
            (Node 2 Empty Empty)
        )
        (Node 4 Empty Empty)
    )
    ( Node
        10
        (Node 9 Empty Empty)
        Empty
    )

minBST :: BST -> Int
minBST Empty = error "no such element"
minBST (Node root Empty _) = root
minBST (Node root left right) =
  minBST left

-- >>> minBST bst
-- 1

-- >>> minBST bst2
-- 1

search :: Int -> BST -> Bool
search _ Empty = False
search x (Node root left right) =
  x == root || if x < root then search x left else search x right

-- >>> search 4 bst
-- False

-- >>> search 4 bst2
-- True

insert :: Int -> BST -> BST
insert x Empty = Node x Empty Empty
insert x (Node root left right)
  | x <= root = Node root (insert x left) right
  | otherwise = Node root left (insert x right)

-- >>> insert 4 bst
-- Node 2 (Node 1 Empty Empty) (Node 3 Empty (Node 4 Empty Empty))

-- >>> insert 2 bst
-- Node 2 (Node 1 Empty (Node 2 Empty Empty)) (Node 3 Empty Empty)

-- инфиксното обхождане, използвайки стратегията ляво-корен-дясно
-- ни дава списък от елементите на дървото в сортирарен ред (възходящо)
inorder :: BST -> [Int]
inorder Empty = []
inorder (Node root left right) =
  inorder left ++ [root] ++ inorder right

-- >>> inorder bst
-- [1,2,3]

-- >>> inorder bst2
-- [1,2,3,4,5,9,10]

kthLargest :: Int -> BST -> Int
kthLargest k bst = inorder bst !! k

-- >>> kthLargest 0 bst2
-- 1

-- >>> kthLargest 1 bst2
-- 2

-- >>> kthLargest 5 bst2
-- 9

-- >>> kthLargest 6 bst2
-- 10

-- >>> kthLargest 7 bst2
-- Prelude.!!: index too large

mergeBST :: BST -> BST -> BST
mergeBST bst1 bst2 = foldr (\x bst -> insert x bst) bst2 elements
 where
  elements = inorder bst1

-- >>> mergeBST (Node 4 Empty Empty) bst
-- Node 2 (Node 1 Empty Empty) (Node 3 Empty (Node 4 Empty Empty))

-- >>> mergeBST bst (Node 4 Empty Empty)
-- Node 4 (Node 3 (Node 2 (Node 1 Empty Empty) Empty) Empty) Empty

-- >>> mergeBST bst bst
-- Node 2 (Node 1 (Node 1 Empty Empty) (Node 2 Empty Empty)) (Node 3 (Node 3 Empty Empty) Empty)
