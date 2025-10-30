#include <iostream>


bool fake()
{
    exit(0);
    return false;
}

int main()
{

    std::cout << "Attampting operation...";
    std::cout << ((1 == 1) || fake() || fake() || (5< 3)) << std::endl;
    std::cout << "Hello world!\n";

    int i = 10, arr[3] = {0}, j = 3;

    std::cout << arr[3] << std::endl;

/*    int number, sum = 0;

    int counter = 0;

    while(counter < 10)
    {
        cout << "Please enter number #" << counter << ":";
        cin >> number;
        sum = sum + number;

        counter++;
    }
*/
/*
    for (int counter = 0; counter < 10; counter++)
    {
        cout << "Please enter number #" << counter << ":";
        cin >> number;
        sum = sum + number;
    }
*/



  //  cout << "The average is " << sum / 10;
}