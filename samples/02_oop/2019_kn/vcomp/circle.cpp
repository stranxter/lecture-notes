#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "circle.h"

Circle::Circle(int _x, int _y, int _r, const char *_s):Shape(_x,_y,_s),r(_r)
{

}

void Circle::draw(SDL_Renderer *rend)
{
    SDL_Texture *texture = IMG_LoadTexture(rend, "images/circle.png");
    SDL_Rect texr;
    texr.x = x;
    texr.y = y;
    texr.w = 2*r;
    texr.h = 2*r;

    SDL_RenderCopy(rend, texture, NULL, &texr);
    SDL_DestroyTexture(texture);
}

void Circle::set_r(int _r)
{
    r=_r;
}

int Circle::get_r()
{
    return r;
}

Shape* Circle::clone ()
{
    return new Circle (*this);
}

void Circle::serialize(std::ostream &out)
{
    out << "Circle "
        << x
        << " "
        << y
        << " "
        << r
        << " "
        << strlen(text)
        << " "
        << text
        << "\n";
}
