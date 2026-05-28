module AST where

import qualified Lex

data Expression = 
        Constant {val::Int} | 
        Var {name::String} |
        Op {left::Expression, op::Char, right::Expression} |
--if 2 then (1+2) else 7
        If {cond::Expression, thn::Expression, els::Expression} |
-- <expression> ::= let <id> = <exprerssion> in <exprerssion>
        Let {var_name::String, var_value::Expression, expr::Expression} |
        Read
        deriving (Show,Eq)


{-( <expression> + <expression>) + -}
{- (42 + (2+1))-}

{- if (3+1) then 4 else (1+2)} -}

--[OpenParen,Number 42,Operator '+',OpenParen,Number 2,Operator '+',Number 1,CloseParen,CloseParen]

parse :: [Lex.Token] -> (Expression,[Lex.Token])
parse ((Lex.Number value):rest) = (Constant value,rest)
parse ((Lex.OpenParen):rest) = (Op leftOperand o rightOperand,rest'')
                where (leftOperand,(Lex.Operator o):rest') = parse rest
                      (rightOperand,(Lex.CloseParen):rest'') = parse rest'
parse ((Lex.If):rest) = (If cond thn els,rest''')
                where (cond,Lex.Then:rest')  = parse rest
                      (thn,Lex.Else:rest'') = parse rest'
                      (els,rest''')         = parse rest''
-- <expression> ::= let <id> = <exprerssion> in <exprerssion>
parse ((Lex.Let):(Lex.VarName name):Lex.Assign:rest) = (Let name val expr,rest'')
                where (val,Lex.In:rest') = parse rest
                      (expr,rest'') = parse rest'
parse ((Lex.VarName name):rest) = (Var name,rest)
parse ((Lex.Read):rest) = (Read,rest)
                      

                      

                      





    