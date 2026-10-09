module Eval where

import qualified AST

operators = [('+',(+)),('-',(-)),('*',(*)),('/',div)]

eval :: AST.Expression -> [(String,Int)] -> Int
eval (AST.Constant c) memory = c
eval (AST.Op left op right) memory = opfn (eval left memory) (eval right memory)
         where opfn = case lookup op operators of
                            (Just fn) -> fn
                            Nothing -> (+)
eval (AST.If cond thn els) memory = if (eval cond memory) /= 0 
                                    then eval thn memory 
                                    else eval els memory
eval (AST.Var name) memory = let (Just val) = lookup name memory in val
eval (AST.Let name val_tree exp_tree) memory = let var_val = eval val_tree memory in
                                                   eval exp_tree ((name,var_val):memory)


