data IntTree = Empty | Node Int IntTree IntTree
  deriving Show

mytree = Node 7
           (Node 30 
                 (Node 15 Empty Empty)
                 (Node 3 Empty Empty))
           (Node 77
                 Empty
                 (Node 15
                       (Node 70 Empty Empty)
                       Empty))
