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