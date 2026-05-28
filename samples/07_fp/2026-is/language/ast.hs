module AST where

import qualified Lex

data Expression = 
        Constant Int | 
        Op Expression Char Expression 

        deriving (Show,Eq)


{-( <expression> + <expression>) + -}
{- (42 + 21)-}


parse :: [Lex.Token] -> (Expression,[Lex.Token])
parse ((Lex.Number value):rest) = (Constant value,rest)
parse ((Lex.OpenParen):rest) = (Op leftOperand o rightOperand,rest'')

                where (leftOperand,(Lex.Operator o):rest') = parse rest
                      (rightOperand,(Lex.CloseParen):rest'') = parse rest'
                      





    