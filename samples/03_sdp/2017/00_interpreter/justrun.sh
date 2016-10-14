bin/interpreter < "sample program" 2> output/test.dot
dot output/test.dot -Tpdf > output/test.pdf
