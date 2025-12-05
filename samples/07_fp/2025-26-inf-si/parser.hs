import Data.Char

data Token = OpenPar | 
             ClosePar |
             Operator Char |
             Number Int |
             Variable Char
    deriving(Show,Eq)


data Expression = Constant Int |
                  Op Expression Token Expression |
                  Var Char
    deriving (Show)


whitespace = [' ','\n','\t']
isWs c = elem c whitespace

tokenize :: String -> [Token]
tokenize "" = []
tokenize s = token : (tokenize rest)
           where clean = dropWhile isWs s
                 (token,rest) = nexttoken clean

nexttoken ('(':rest) = (OpenPar,rest)
nexttoken (')':rest) = (ClosePar,rest)
nexttoken s
   | isDigit (head s) = (Number number,rest)
   | isLetter (head s) = (Variable $ head s,tail s)
   | otherwise = (Operator (head s), tail s)
       where number = read $ takeWhile isDigit s
             rest = dropWhile isDigit s


exprTree :: [Token] -> (Expression,[Token])
exprTree ((Number n) : rest) = (Constant n,rest)
exprTree ((Variable x):rest) = (Var x,rest)
exprTree (OpenPar : rest) = (Op lt op rt,remaining)
               where (lt,rest') = exprTree rest
                     op = head rest'
                     (rt, rest'')= exprTree $ tail rest'
                     remaining = tail rest''

parse :: String -> Expression
parse s = fst $ exprTree (tokenize s)

{--
data Expression = Constant Int |
                  Op Expression Token Expression
    deriving (Show)

    --}



type Memory = [(Char,Int)]

varval :: Char -> Memory -> Int
varval n m = snd $ head $ filter (\(name,value)->name==n) m

eval :: Expression -> Memory ->Int
eval (Constant i) _ = i
eval (Var x) m = varval x m
eval (Op lt (Operator op) rt) m = (apply op) (eval lt m) (eval rt m)

apply :: Char -> (Int->Int->Int)
apply '+' = (+)
apply '-' = (-)
apply '*' = (*)
apply '/' = div
