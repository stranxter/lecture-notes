/*

Инструкции как да конфигурираме Visual Studio 
и SDL2 може да видите тук:

http://www.willusher.io/sdl2%20tutorials/2013/08/15/lesson-0-visual-studio/

За Linux & Mac ползвайте приложения Makefile. 

И в двата случая е необходимо първо да 
инсталирате SDL2. 

*/

#ifndef __SDL_WRAPPER_
#define __SDL_WRAPPER_

#include <iostream>
#include <SDL2/SDL.h>
#include <assert.h>

//global variables for SLD window and renderer
SDL_Window *SDLWin = 0;
SDL_Renderer *SDLRen = 0;

void SDLStart (){
	std::cout << "Starting SDL...\n";

	assert (SDL_Init(SDL_INIT_VIDEO) == 0);

	SDLWin = SDL_CreateWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
	assert (SDLWin != nullptr);

	SDLRen = SDL_CreateRenderer(SDLWin, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	assert (SDLRen != nullptr);

	SDL_RenderClear(SDLRen);
};

#define setColor(r,g,b) SDL_SetRenderDrawColor(SDLRen,r,g,b,SDL_ALPHA_OPAQUE);
#define drawPixel(x,y) SDL_RenderDrawPoint(SDLRen,x,y);
#define drawLine(x1,y1,x2,y2) SDL_RenderDrawLine(SDLRen,x1,y1,x2,y2);

#define updateGraphics() SDL_RenderPresent(SDLRen);

void SDLEnd()
{

	SDL_DestroyRenderer(SDLRen);
	SDL_DestroyWindow(SDLWin);
	SDL_Quit();
}

class init
{
	public:
		init(){SDLStart();}
		~init(){SDLEnd();}
};

//global variable: constructor/destructor
//will handle SLD init/destroy
init sdlInit;

#endif