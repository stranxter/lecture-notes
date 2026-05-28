module Interpreter where

import qualified Lex
import qualified AST
import qualified Eval

tokens :: String -> [Lex.Token]
tokens = Lex.tokenizer . Lex.lexer

tree :: String -> AST.Expression
tree expr = let (t,_) = AST.parse $ tokens expr in t

run :: String -> Int
run string = Eval.eval (tree string) []