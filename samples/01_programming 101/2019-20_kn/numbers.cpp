#include <iostream>
using namespace std;

void analyzeNumber (int z)
{
    int count = 1,
        sum = 0;
    bool has5 = false,
         all5 = true;

    while (z > 9)
    {
        //sum, has5, all5, z%10
        //sum:  на стъпка i това с сумата на първите
        //      i цифри на z (от дясно на ляво)
        //has5: на стъпка i е истина, т.с.т.к. в първите i
        //      цифри има цифрата 5
        //all5: на стъпка i е истина, т.с.т.к. всики първи i
        //      цифро са петици

        sum += z % 10;
        if (z % 10 == 5)
        {
            has5 = true;
        }
        else
        {
            all5 = false;
        }

        z = z / 10;
        count++;
    }
    sum += z;
    if (z % 10 == 5)
    {
        has5 = true;
    }
    else
    {
        all5 = false;
    }
    //sum, has5, all5, z%10
    //sum:  на стъпка i това с сумата на първите
    //      i цифри на z (от дясно на ляво)
    //has5: на стъпка i е истина, т.с.т.к. в първите i
    //      цифри има цифрата 5
    //all5: на стъпка i е истина, т.с.т.к. всики първи i
    //      цифро са петици

    cout << "Number of base 10 digits = "
         << count
         << endl
         << "Sum of digits = "
         << sum
         << endl
         << "Does it have a 5?:";
    if (has5)
        cout << "Yes!" << endl;
    else
        cout << "No!" << endl;
}


int main ()
{


    int z;
    cout << "Please enter a number=";
    cin >> z;

    analyzeNumber (z);

    return 0;
}