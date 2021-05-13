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
OBJS = $(patsubst %.cpp,$(builddir)%.o,$(wildcard *.cpp))  $(patsubst draw/%.cpp,$(builddir)%.o,$(wildcard draw/*.cpp)) 
builddir = build/

all: draw

draw: $(OBJS)
	$(CXX) $(LDFLAGS) $(OBJS) -o $(builddir)$@

$(builddir)%.o: %.cpp $(DEPS)
	@mkdir -p $(@D)
	@$(CXX) -c -o $@ $< $(CXXFLAGS)

$(builddir)%.o: draw/%.cpp $(DEPS)
	@mkdir -p $(@D)
	@$(CXX) -c -o $@ $< $(CXXFLAGS)

clean:
	rm -r build
