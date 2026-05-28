module Lex where

import qualified Data.Char

data Token = Number Int | 
             Operator Char | 
             OpenParen | 
             CloseParen |
             If |
             Then |
             Else |
             Let |
             In |
             Assign |
             VarName String |
             Read
        deriving (Show,Eq)

isWhite :: Char -> Bool
isWhite x = Data.Char.ord x <= 32

operators = ['+','-','/','*']
symbols = ['(',')']
isSymbol :: Char -> Bool
isSymbol c = elem c (symbols ++ operators)

clearwhite :: String -> String
clearwhite s = dropWhile isWhite s

lexer :: String -> [String]
lexer s
   | null clean = []
   | isSymbol (head clean) = ((head clean):"") : lexer (tail clean)
   | otherwise = first:(lexer rest)
          
   where clean = clearwhite s
         (first,rest) = break (\c -> isWhite c || isSymbol c) clean


token :: String -> Token
token "(" = OpenParen
token ")" = CloseParen
token "if" = If
token "then" = Then
token "else" = Else
token "let" = Let
token "in" = In
token "=" = Assign
token "read" = Read
token s   
   | elem (head s) operators = Operator (head s)
   | Data.Char.isDigit (head s) = Number (read s)
   | otherwise = VarName s


tokenizer :: [String] -> [Token]
tokenizer [] = []
tokenizer (x:xs) = (token x) : tokenizer xs




