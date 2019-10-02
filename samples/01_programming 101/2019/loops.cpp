#include <iostream>
using namespace std;

int main()
{
    int number, sum = 0;
    for (int counter = 0; counter < 4; counter = counter + 1)
    {
        cout << "Please enter number #" << counter << ":";
        cin >> number;
        sum = sum + number;
        cout << "Current sum = " << sum << endl;
    }
    cout << "The average is " << sum / 4;
}