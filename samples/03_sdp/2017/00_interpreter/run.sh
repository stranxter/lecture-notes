g++ src/interpreter.cpp src/lex/*cpp src/ast/*cpp src/parser/*cpp src/runtime/*cpp -o bin/interpreter -std=c++11
bin/interpreter < "sample program" 2> output/test.dot
dot output/test.dot -Tpdf > output/test.pdf
