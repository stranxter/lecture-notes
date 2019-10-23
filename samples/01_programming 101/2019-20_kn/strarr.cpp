#include <iostream>
#include <cstring>
using namespace std;

int main ()
{
    char x = 'a';
    char str[100] = "Hello world!";
    char y = 'b';
    str[13] = '@';
    str[14] = '$';
    str[15] = '!';
    str[16] = '&';

    cout << str << endl;

    str[0] = 'Y';

    cout << str << endl;

    cout << (int)str[12] << endl;

    str[12] = 65;

    cout << str << endl;

    cout << "Please enter a string:";
    cin >> str;
    //cin.getline (str,99);
    cout << "You entered:";
    cout << str << endl;

    int counta = 0;
    for (int count = 0; count < strlen(str); ++count)
    {
        if (str[count] == 'a')
        {
            ++counta;
        }
    }

    cout << "Number of a's = " << counta << endl;

    //cout << "x=" << x << ", y = " << y << endl;


    //char str[20] = "Hello world!";
    //str[2457] = 17;
}