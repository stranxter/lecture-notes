#include <iostream>

using namespace std;

int main()
{
    int number, sum = 0;

    int counter = 0;

    while(counter < 10)
    {
        cout << "Please enter number #" << counter << ":";
        cin >> number;
        sum = sum + number;

        counter++;
    }

/*
    for (int counter = 0; counter < 10; counter++)
    {
        cout << "Please enter number #" << counter << ":";
        cin >> number;
        sum = sum + number;
    }
*/



    cout << "The average is " << sum / 10;
}