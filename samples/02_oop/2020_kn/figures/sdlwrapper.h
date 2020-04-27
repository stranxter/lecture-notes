/*

Помощен код, обвиващ SDL2 за по-лесен достъп до 
функциите на билиотеката.

Инструкции как да конфигурираме Visual Studio
и SDL2 може да видите тук:

http://www.willusher.io/sdl2%20tutorials/2013/08/15/lesson-0-visual-studio/

За Linux & Mac ползвайте приложения Makefile.

И в двата случая е необходимо първо да
инсталирате SDL2, SLD2_Image и SDL2_ttf.

*/

#ifndef __SDL_WRAPPER_
#define __SDL_WRAPPER_

namespace sdlw
{

    void setColor(int r, int g, int b);
    void drawPixel(int x, int y);
    void drawLine(int x1, int y1, int x2, int y2);
    void drawFillRect(int x, int y, int w, int h);
    void drawFile(int x, int y, int w, int h, const char* file);
    void drawText ();

    void updateGraphics();
}
#endif