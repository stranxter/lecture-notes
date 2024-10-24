#include <iostream>
#include <cmath>

using namespace std;

double surface(double a, double b, double c)
{
    double p = (a+b+c)/2.0;

    double s = sqrt(p*(p-a)*(p-b)*(p-c));

    return s;
}

int main()
{

    cout << surface(3,3,3) << endl;

    char c = 65; //= 'A'

    cout << c << endl;
    
    return 0;
}
