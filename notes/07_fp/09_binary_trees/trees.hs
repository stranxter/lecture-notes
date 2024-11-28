import Data.List

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


{---Lexical Analysis---}

separators = [' ','\n','\t']
separator = (flip (elem)) separators

symbols = ['(',')']
symbol = (flip (elem)) symbols

stopper :: Char -> Bool
stopper x  = any (\f->f x) [separator,symbol]

next :: String -> Maybe (String, String)
next [] = Nothing
next s@(c:cs) | separator c = next cs
              | symbol c = Just ([c], cs)
              | otherwise = Just $ break stopper s

lexer = (unfoldr next) . (dropWhile separator)

{-----------------------}

parse :: [String] -> (IntTree, [String])
parse ("(":")":rest) = (Empty, rest)
parse ("(":rest) = (Node (read n) l r, rest'')
  where n = head rest
        (l, rest') = parse $ tail rest
        (r, ")":rest'') = parse rest'

tostr :: IntTree -> String
tostr Empty = "()"
tostr (Node n l r) = "(" ++ show n ++ " " ++ tostr l ++ " " ++ tostr r ++ ")"