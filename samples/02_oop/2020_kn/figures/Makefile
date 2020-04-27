#Инструкции как да конфигурираме Visual Studio
#и SDL2 може да видите тук:
#
#http://www.willusher.io/sdl2%20tutorials/2013/08/15/lesson-0-visual-studio
#
#За Linux & Mac ползвайте приложения Makefile.
#
#И в двата случая е необходимо първо да
#инсталирате SDL2.
CXX = clang++
SDL =  -L/usr/local/lib -lSDL2 -lSDL2_image -lSDL2_ttf
# If your compiler is a bit older you may need to change -std=c++11 to -std=c++0x
CXXFLAGS = -Wall -c -std=c++11
LDFLAGS = $(SDL)
DEPS = $(wildcard *.h)
OBJS = $(patsubst %.cpp,$(builddir)%.o,$(wildcard *.cpp)) 
builddir = build/

all: draw

draw: $(OBJS)
	$(CXX) $(LDFLAGS) $(OBJS) -o $(builddir)$@

%.o: %.cpp $(DEPS)
	$(CXX) -c -o $(builddir)$@ $< $(CXXFLAGS)

clean:
	rm -r build
