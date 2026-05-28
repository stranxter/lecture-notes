module Eval where

import qualified AST

operators = [('+',(+)),('-',(-)),('*',(*)),('/',div)]

eval :: AST.Expression -> Int
eval (AST.Constant c) = c
eval (AST.Op left op right) = opfn (eval left) (eval right)
         where opfn = case lookup op operators of
                            (Just fn) -> fn
                            Nothing -> (+)