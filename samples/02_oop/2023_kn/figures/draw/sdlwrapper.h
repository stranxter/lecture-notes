#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <assert.h>

namespace sdlw
{

        struct color
        {
            Uint8 r;
            Uint8 g;
            Uint8 b;
        };

        void setColor(color c);
        void drawPixel(int x, int y);
        void drawLine(int x1, int y1, int x2, int y2);
        void drawFillRect(int x, int y, int w, int h);
        void drawFillCircle(int x, int y, int radius);
        void drawFile(int x, int y, int w, int h, const char* file);
        void updateGraphics();
        void drawText(int x, int y, int size, const char* text);

}