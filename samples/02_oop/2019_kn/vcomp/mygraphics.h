/*

Инструкции как да конфигурираме Visual Studio
и SDL2 може да видите тук:

http://www.willusher.io/sdl2%20tutorials/2013/08/15/lesson-0-visual-studio/

За Linux & Mac ползвайте приложения Makefile.

И в двата случая е необходимо първо да
инсталирате SDL2 и SLD2_Images.

*/

#ifndef __SDL_WRAPPER_
#define __SDL_WRAPPER_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
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

void drawTexture(SDL_Renderer *SDLRen, int x, int y, int w, int h, const char *file)
{
	SDL_Texture *texture = IMG_LoadTexture(SDLRen, file);
/*	int w, h;
	SDL_QueryTexture(texture, NULL, NULL, &w, &h);*/
	SDL_Rect texr;
	texr.x = x;
	texr.y = y;
	texr.w = w;
	texr.h = h;

	SDL_RenderCopy(SDLRen, texture, NULL, &texr);
	SDL_DestroyTexture(texture);
}

#define setColor(r,g,b) SDL_SetRenderDrawColor(SDLRen,r,g,b,SDL_ALPHA_OPAQUE);
#define drawPixel(x,y) SDL_RenderDrawPoint(SDLRen,x,y);
#define drawLine(x1,y1,x2,y2) SDL_RenderDrawLine(SDLRen,x1,y1,x2,y2);
#define drawRect(x,y,w,h) {SDL_Rect r={x,y,w,h}; SDL_RenderFillRect(SDLRen, &r);}
#define drawFile(x, y, w, h, file) drawTexture(SDLRen,x,y,w,h,file)

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
