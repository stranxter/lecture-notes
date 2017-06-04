targets := $(wildcard src/*cpp) $(wildcard src/ast/*cpp) $(wildcard src/parser/*cpp) $(wildcard src/interpreter/*cpp)
headers := $(wildcard src/*h) $(wildcard src/ast/*h) $(wildcard src/parser/*h) $(wildcard src/interpreter/*h)

knsi: $(targets) $(headers)
	g++ -std=c++11 -o knsi $(targets)
