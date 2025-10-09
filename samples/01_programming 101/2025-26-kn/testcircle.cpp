#include <iostream>

using namespace std;

double distance(double x1, double y1,
                double x2, double y2)
{
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int main()
{
    double a,b;

    cin >> a >> b;

    if(distance(0,1,a,b) < 5)
    {
        cout << "Ами да, там е!";
    } else
    {
        cout << "Ами не...";
    }

}