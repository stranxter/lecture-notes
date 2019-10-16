#include <iostream>
#include <cmath>
using namespace std;

int f()
{
    int x;
    cin >> x;
    return x;
}

double computeD(double a, double b, double c)
{
    return b * b - 4 * a * c;
}

double firstRoot(double a, double b, double c)
{
    double D = computeD(a,b,c);
    //assumes D >= 0
    
    return (-b - sqrt (D))/(2*a);
}

void printRootBeautiful (double r)
{
    cout << "One of the roots of your equation is [" 
         << r 
         << "]" 
         << endl;
}

int main ()
{
    double a,b,c;
    
    do {
        cout << "Please enter coeffs:" << endl;
        cout << "a=";
        cin >> a;
        cout << "b=";
        cin >> b;
        cout << "c=";
        cin >> c;

    } while (computeD(a, b, c) < 0);

    printRootBeautiful(firstRoot(a, b, c));

    return 0;
}

