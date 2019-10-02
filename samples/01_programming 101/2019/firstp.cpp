#include <iostream>
using namespace std;


int main ()
{

    //=======================================

    
    int ivanAge = 0;

    cout << "На колко години е Иван?=";

    cin >> ivanAge;

    int x = (ivanAge=1);

    int a,b,c,d,e;

    a = (b = (c = (d = (e = 1))));

//    if (ivanAge = 18)
    if (ivanAge == 18)
    {
        cout << "Иван е точно на 18!" << endl;
    } else {
        cout << "Иван не е точно на 18!" << endl;
    }
    
    //=======================================

    int a = 701;

    //CASE 1: a <- [21...199]
    //CASE 2: a <- [200...699]
    //CASE 3: a <= 20

    if (a > 20)
    {
        if (a < 200)
        {
            cout << "CASE␣1";


        }
        else if (a < 700)
        {
            cout << "CASE␣2";
        }
    }
    else
    {
        cout << "CASE␣3";
    }

    return 0;
}