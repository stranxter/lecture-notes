import Prelude hiding (lookup)
import Data.List hiding (insert,lookup)
import Data.Map hiding (drop, map, take)

data Token = Number Int | 
             Operator Char | 
             OpenParen | 
             CloseParen |
             If | Then | Else |
             Var String |
             Define |
             Call |
             Collon
             

    deriving (Show)

type Operator = Int -> Int -> Int

data Expression = 
    Constant Int | 
    Variable String |
    Op Expression Char Expression |
    Condition Expression Expression Expression |
    FnDef String String Expression |
    FnCall String Expression

    deriving (Show)

{-Language Tokens-}

isDigit :: Char -> Bool
isDigit c = c `elem` ['0'..'9']

token :: String -> Token
token "+" = Operator '+'
token "-" = Operator '-'
token "*" = Operator '*'
token "/" = Operator '/'
token "(" = OpenParen
token ")" = CloseParen
token ":" = Collon
token "if" = If
token "then" = Then
token "else" = Else
token "define" = Define
token "call" = Call
token lex
    | all isDigit lex = Number (read lex)
    | otherwise = Var lex

{-Lexical Analysis-}

separators = [' ','\n','\t']
separator = (flip (elem)) separators

symbols = ['+','-','*','(',')']
symbol = (flip (elem)) symbols

stopper :: Char -> Bool
stopper x  = any (\f->f x) [separator,symbol]

next :: String -> Maybe (String, String)
next [] = Nothing
next s@(c:cs) | separator c = next cs
              | symbol c = Just ([c], cs)
              | otherwise = Just $ break stopper s

lexer = (unfoldr next) . (dropWhile separator)

tokens :: String -> [Token]
tokens = map token . lexer

{-Syntax Analysis-}

operator :: Char -> Operator
operator '+' = (+)
operator '-' = (-)
operator '*' = (*)
operator '/' = div

parse :: [Token] -> Maybe (Expression,[Token])
parse [] = Nothing
parse (Number n:ts) = Just (Constant n,ts)
parse (Var name:ts) = Just (Variable name,ts)
parse (OpenParen:ts) = Just (Op left op right, ts'')
    where Just (left, ts') = parse ts
          Operator op = head ts'
          Just (right, CloseParen:ts'') = parse (tail ts')
parse (If:ts) = Just (Condition cond then' else', ts''')
    where Just (cond, Then:ts') = parse ts
          Just (then', Else:ts'') = parse ts'
          Just (else', ts''') = parse ts''
parse (Define:ts) = Just (FnDef name arg body, ts')
    where [Var name, Var arg, Collon] = take 3 ts
          Just (body, ts') = parse $ drop 3 ts
parse (Call:ts) = Just (FnCall name value, ts')
    where Var name = head ts
          Just (value, ts') = parse $ tail ts
            

{-Evaluation-}

data State = State {variables :: Map String Int, 
                    functions :: Map String (String, Expression)}
                    deriving (Show)

eval :: State -> Expression -> (Int,State)
eval s (Constant n) = (n,s)
eval s (Variable name) = (val,s)
    where Just val = lookup name (variables s)
eval s (Op left op right) = ((operator op) (fst $ eval s left) (fst $ eval s right),s)
eval s (Condition cond then' else') = eval s $ if fst (eval s cond) /= 0 then then' else else'
eval s (FnDef name arg body) = (0, State (variables s) (insert name (arg,body) (functions s)))
eval s (FnCall name value) = eval s' body
    where (arg,body) = functions s ! name
          (val,_) = eval s value
          s' = State (insert arg val (variables s)) (functions s)

evalall :: State -> [Expression] -> (Int,State)
evalall s [e] = (eval s e)
evalall s (e:es) = evalall s' es
    where (_,s') = eval s e


parsestr = (unfoldr parse) . tokens
evalstr = evalall (State (fromList []) (fromList [])) . 
                  parsestr
--evalstr "define fact x : if x then (x * call fact (x-1)) else 1 call fact 4"

{-Output in Dot Format-}

toDot :: Expression -> Int -> (String,Int)
toDot (Constant n) i = (show i ++ " [label=\"" ++ show n ++ "\"];\n",i+1)
toDot (Variable name) i = (show i ++ " [label=\"" ++ name ++ "\"];\n",i+1)
toDot (Op left op right) i = (show i ++ " [label=\"" ++ [op] ++ "\"];\n" ++ 
                             show i ++ " -> " ++ show (i+1) ++ ";\n" ++
                             show i ++ " -> " ++ show i' ++ ";\n" ++
                             s' ++ s'',i'')
    where (s',i') = toDot left (i+1)
          (s'',i'') = toDot right i'
toDot (Condition cond then' else') i = (show i ++ " [label=\"if\"];\n" ++
                                        show i ++ " -> " ++ show (i+1) ++ ";\n" ++
                                        show i ++ " -> " ++ show i' ++ ";\n" ++
                                        show i ++ " -> " ++ show i'' ++ ";\n" ++
                                        s' ++ s'' ++ s''',i''')
      where (s',i') = toDot cond (i+1)
            (s'',i'') = toDot then' i'
            (s''',i''') = toDot else' i''
toDot (FnDef name arg body) i = (show i ++ " [label=\"define\"];\n" ++
                                 show (i+1) ++ " [label=\"" ++ name ++ "\"];\n" ++
                                 show (i+2) ++ " [label=\"" ++ arg ++ "\"];\n" ++
                                 show i ++ " -> " ++ show (i+1) ++ ";\n" ++
                                 show i ++ " -> " ++ show (i+2) ++ ";\n" ++
                                 show i ++ " -> " ++ show (i+3) ++ ";\n" ++
                                 s' ,i')
    where (s',i') = toDot body (i+3)
toDot (FnCall name value) i = (show i ++ " [label=\"call\"];\n" ++
                              show i ++ " -> " ++ show (i+1) ++ ";\n" ++
                              show i ++ " -> " ++ show i' ++ ";\n" ++
                              s' ++ s'',i'')
    where (s',i') = toDot (Variable name) (i+1)
          (s'',i'') = toDot value i'


toDotAll :: [Expression] -> Int -> (String,Int)
toDotAll [] _ = ("",0)
toDotAll (e:es) i = (s ++ s',i'')
    where (s,i') = toDot e i
          (s',i'') = toDotAll es i'

toDotty :: [Expression] -> String
toDotty es = "digraph G {\n" ++ s ++ "}"
    where (s,_) = toDotAll es 0