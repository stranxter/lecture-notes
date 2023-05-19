#include "sdlwrapper.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <assert.h>

namespace sdlw
{

        //global variables for SLD window and renderer
        SDL_Window *SDLWin = 0;
        SDL_Renderer *SDLRen = 0;
        /*memorize colors set by SetColor*/
        Uint8 _r = 0, _g = 0, _b = 0;

        void setColor (color c)
        {
            SDL_SetRenderDrawColor(SDLRen, c.r, c.g, c.b, SDL_ALPHA_OPAQUE);
            _r = c.r;
            _g = c.g;
            _b = c.b;
        } 

        class SdlInit
        {
        public:
            SdlInit() 
            {
                assert(SDL_Init(SDL_INIT_VIDEO) == 0);
                TTF_Init();

                SDLWin = SDL_CreateWindow("Hello World!", 100, 100, 800, 500, SDL_WINDOW_SHOWN);
                assert(SDLWin != nullptr);

                SDLRen = SDL_CreateRenderer(SDLWin, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
                assert(SDLRen != nullptr);

                SDL_Event e;
        		SDL_PollEvent(&e);

                setColor({0, 0, 0});
                SDL_RenderClear(SDLRen);
            }
            ~SdlInit() 
            {
                SDL_DestroyRenderer(SDLRen);
                SDL_DestroyWindow(SDLWin);
                TTF_Quit();
                SDL_Quit();
            }
        };

        //global variable: constructor/destructor
        //will handle SLD init/destroy
        SdlInit sdlInit;

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

        void drawPixel(int x, int y)
        {
            SDL_RenderDrawPoint(SDLRen, x, y);
        }

        void drawLine(int x1, int y1, int x2, int y2)
        {
            SDL_RenderDrawLine(SDLRen, x1, y1, x2, y2);
        } 

        void drawFillRect(int x, int y, int w, int h)            
        {                                   
            SDL_Rect r = {x, y, w, h};      
            SDL_RenderFillRect(SDLRen, &r); 
        }

        void drawFile (int x, int y, int w, int h, const char* file)
        {
            drawTexture(SDLRen, x, y, w, h, file);
        } 

        void updateGraphics()
        {
            SDL_RenderPresent(SDLRen);
        } 

        void drawText (int x, int y, int size, const char* text)
        {
            TTF_Font *font = TTF_OpenFont("draw/images/roboto.ttf", size);
            SDL_Color color = {_r, _g, _b};
            SDL_Surface *surface = TTF_RenderText_Solid(font,text,color);
            SDL_Texture *texture = SDL_CreateTextureFromSurface(SDLRen, surface);

            int texW = 0;
            int texH = 0;
            SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
            SDL_Rect dstrect = {x, y, texW, texH};

            SDL_RenderCopy(SDLRen, texture, NULL, &dstrect);
            SDL_RenderPresent(SDLRen);
            
            SDL_DestroyTexture(texture);
            SDL_FreeSurface(surface);
            TTF_CloseFont(font);
        }

        void drawFillCircle(int x, int y, int radius)
        {
            int offsetx, offsety, d;
            int status;

            offsetx = 0;
            offsety = radius;
            d = radius -1;
            status = 0;

            while (offsety >= offsetx) {

                status += SDL_RenderDrawLine(SDLRen, x - offsety, y + offsetx,
                                            x + offsety, y + offsetx);
                status += SDL_RenderDrawLine(SDLRen, x - offsetx, y + offsety,
                                            x + offsetx, y + offsety);
                status += SDL_RenderDrawLine(SDLRen, x - offsetx, y - offsety,
                                            x + offsetx, y - offsety);
                status += SDL_RenderDrawLine(SDLRen, x - offsety, y - offsetx,
                                            x + offsety, y - offsetx);

                if (status < 0) {
                    status = -1;
                    break;
                }

                if (d >= 2*offsetx) {
                    d -= 2*offsetx + 1;
                    offsetx +=1;
                }
                else if (d < 2 * (radius - offsety)) {
                    d += 2 * offsety - 1;
                    offsety -= 1;
                }
                else {
                    d += 2 * (offsety - offsetx - 1);
                    offsety -= 1;
                    offsetx += 1;
                }
            }            
        }
}