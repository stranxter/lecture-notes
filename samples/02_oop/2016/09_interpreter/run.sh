g++ src/interpreter.cpp src/lex/*cpp src/ast/*cpp src/parser/*cpp  -o bin/interpreter
bin/interpreter 2> output/test.dot
dot output/test.dot -Tpdf > output/test.pdf
