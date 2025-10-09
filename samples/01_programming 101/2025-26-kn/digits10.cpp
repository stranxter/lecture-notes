#include <iostream>

using namespace std;

int main()
{
    int n;

    cout << "Моля, въведете n=";
    cin >> n;

    //брой на цифрите в десетичния записа на n

    int count = 1;
    int sum = 0;
    
    while(n > 9)
    /* n    count sum
       123   1     0
       12    2     3
       1     3     5
       1     3     6

    */
    {
        sum += n%10;
        n /= 10; // n = n / 10;
        count++;
    }
    sum += n;

    cout << "брой цифри на n = " << count << endl;
    cout << "сума цифри на n = " << sum << endl;

    /*  / %. 1234%10 = 4  1234/10 = 123 */

}