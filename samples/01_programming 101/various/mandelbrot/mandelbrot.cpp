/*
Стартов файл за използване на SDL обвиваката paint.
Кпирайте и модифицирайте този файл, за да създадете своята програма.
*/


#include "cpppainter/sdlwrapper.h"

void mandelbrot(double x0, double y0, double x1, double y1, int maxIter)
{
    const int width = 300;
    const int height = 300;

    for(int px = 0; px < width; px++)
    {
        for(int py = 0; py < height; py++)
        {
            double x = x0 + (x1 - x0) * px / width;
            double y = y0 + (y1 - y0) * py / height;

            double zx = 0.0;
            double zy = 0.0;
            int iteration = 0;

            while(zx * zx + zy * zy < 4.0 && iteration < maxIter)
            {
                double xtemp = zx * zx - zy * zy + x;
                zy = 2.0 * zx * zy + y;
                zx = xtemp;
                iteration++;
            }

            int color = (iteration == maxIter) ? 0 : (iteration * 255 / maxIter);
            int r = (color * 7) % 256;
            int g = (color * 13) % 256;
            int b = (color * 17) % 256;
            paint::setColor(r, g, b);
            paint::drawPixel(px, py);
        }
    }
}

int main()
{

    double x0 = -2.0,
           y0 = -1.5,
           x1 =  1.0,
           y1 =  1.5;    

    mandelbrot(x0, y0, x1, y1, 1000);

    paint::updateGraphics();
    paint::waitKeypress();

    return 0;
}

int SDL_main(int argc, char* argv[]) {
    // Това е необходимо за SDL под Windows: 
    // библиотекат сменя входната точка на програмата
    return main(); 
}

