import Data.List

data Token = Number Int | 
             Operator Char | 
             OpenParen | 
             CloseParen
    deriving (Show)

type Operator = Int -> Int -> Int

data Expression = 
    Constant Int | 
    Op Expression Char Expression
    deriving (Show)

token :: String -> Token
token "+" = Operator '+'
token "-" = Operator '-'
token "*" = Operator '*'
token "/" = Operator '/'
token "(" = OpenParen
token ")" = CloseParen
token n = Number (read n)

separators = [' ','\n','\t']
separator = (flip (elem)) separators

symbols = ['+','-','*','(',')']
symbol = (flip (elem)) symbols

stopper :: Char -> Bool
stopper x  = or $ map (\f->f x) [separator,symbol]

next :: String -> Maybe (String, String)
next [] = Nothing
next s@(c:cs) | separator c = next cs
              | symbol c = Just ([c], cs)
              | otherwise = Just $ break stopper s

lexer = (unfoldr next) . (dropWhile separator)

tokens :: String -> [Token]
tokens = map token . lexer

operator :: Char -> Operator
operator '+' = (+)
operator '-' = (-)
operator '*' = (*)
operator '/' = div

parse :: [Token] -> (Expression,[Token])
parse (Number n:ts) = (Constant n,ts)
parse (OpenParen:ts) = (Op left op right, ts'')
    where (left, ts') = parse ts
          Operator op = head ts'
          (right, CloseParen:ts'') = parse (tail ts')

eval :: Expression -> Int
eval (Constant n) = n
eval (Op left op right) = (operator op) (eval left) (eval right)
