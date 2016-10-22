#Инструкции как да конфигурираме Visual Studio 
#и SDL2 може да видите тук:
#
#http://www.willusher.io/sdl2%20tutorials/2013/08/15/lesson-0-visual-studio/
#
#За Linux & Mac ползвайте приложения Makefile. 
#
#И в двата случая е необходимо първо да 
#инсталирате SDL2. 
CXX = clang++
SDL = -framework SDL2
# If your compiler is a bit older you may need to change -std=c++11 to -std=c++0x
CXXFLAGS = -Wall -c -std=c++11
LDFLAGS = $(SDL)
EXE = SampleProgram

all: $(EXE)

$(EXE): main.o
	$(CXX) $(LDFLAGS) $< -o $@

main.o: main.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm *.o && rm $(EXE)