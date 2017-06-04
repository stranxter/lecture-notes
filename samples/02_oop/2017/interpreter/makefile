targets := $(wildcard src/*cpp) $(wildcard src/ast/*cpp) $(wildcard src/parser/*cpp)
headers := $(wildcard src/*h) $(wildcard src/ast/*h) $(wildcard src/parser/*h)

knsi: $(targets) $(headers)
	g++ -std=c++11 -o knsi $(targets)
