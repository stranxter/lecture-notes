#include <iostream>
using namespace std;


//n! = 1 * 2 * 3 * 4 * 5 ... * n
//1! = 1
//3! = 1 * 2 * 3 = 6
//0! = 1

int main()
{

    /* Програма за намиране на най-голямото от n числа, въведени от
       стандартния вход*/

    int current, n;

    int biggestNumberSoFar = 0;

    cout << "Колко числа да проверим днес?=";
    cin >> n;

    if (n > 0)
    {
        cout << "Въведете число #0" << "=";
        cin >> biggestNumberSoFar;
    }

    for(current = 1; current < n; current++)
    {
        cout << "Въведете число #" << current << "=";
        int input;
        cin >> input; 

        if(input > biggestNumberSoFar)
        {
            biggestNumberSoFar = input;
        } 
    }

    cout << "Най-голямо число = " << biggestNumberSoFar << endl;

    return 0;
}