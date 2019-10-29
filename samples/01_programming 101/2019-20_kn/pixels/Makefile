#Инструкции как да конфигурираме Visual Studio
#и SDL2 може да видите тук:
#
#http://www.willusher.io/sdl2%20tutorials/2013/08/15/lesson-0-visual-studio
#
#За Linux & Mac ползвайте приложения Makefile.
#
#И в двата случая е необходимо първо да
#инсталирате SDL2.
CXX = c++

#macOS uncomment below:
#SDL_CFLAGS =
#SDL_LDFLAGS =  -L/usr/local/lib -lSDL2

SDL_CFLAGS := $(shell pkg-config --cflags sdl2)
SDL_LDFLAGS := $(shell pkg-config --libs sdl2)

# If your compiler is a bit older you may need to change -std=c++11 to -std=c++0x
CXXFLAGS = $(SDL_CFLAGS) -Wall -c -std=c++11

EXE = SampleProgram

all: $(EXE)

$(EXE): main.cpp
	$(CXX) $< -o $@ $(SDL_LDFLAGS)

clean:
	rm *.o && rm $(EXE)
