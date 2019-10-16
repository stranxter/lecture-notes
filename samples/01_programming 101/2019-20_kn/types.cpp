#include <iostream>
using namespace std;

int main()
{

    int int_a = 1, int_b = 2;
    double dbl_a = 1, dbl_b = 2;
    char chr_a = 'a', chr_b = 'b';

    cout << int_a / int_b << endl;
    cout << dbl_a / dbl_b << endl;
    cout << chr_a << endl;

    int_a = 'a'; //int_a = chr_a;
    cout << int_a << endl;

    chr_a = 'Z'-'A';
    cout << chr_a << endl;
    int_a = '1' - '1';
    cout << int_a << endl;
    return 0;
}