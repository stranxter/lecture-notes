#Инструкции как да конфигурираме Visual Studio
#и SDL2 може да видите тук:
#
#http://www.willusher.io/sdl2%20tutorials/2013/08/15/lesson-0-visual-studio
#
#За Linux & Mac OS ползвайте приложения Makefile.
#
#И в двата случая е необходимо първо да
#инсталирате SDL2, SDL2_image и SDL2_ttf
CXX = clang++
#Изпползваййте sdl2-config --cflags, за да намерите къде е инсталиран
#SDL2 и коригирайте тези два реда съответно
SDL =  -L/opt/homebrew/lib -lSDL2 -lSDL2_image -lSDL2_ttf
CXXFLAGS = -Wall -c -std=c++11 -I/opt/homebrew/include -D_THREAD_SAFE
# If your compiler is a bit older you may need to change -std=c++11 to -std=c++0x
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
