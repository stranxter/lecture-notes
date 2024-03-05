#include <iostream>

int main()
{
    char str1[20] = "Hello",
         str2[20] = "Good bye!";


    std::cout << (long)str1 << std::endl;

    //str1[20] = 'A';

    char in[50] = "Hi! Have a nice day!";
    in[3] = 0;

    std::cout << in[4] << std::endl;

    int x = 100;
    char in2[5] = "Hi!";
    int y = 200;

    std::cout << "x=" << x << " y=" << y << std::endl;

    std::cout << "Please enter a string=";
//    std::cin >> in2;

    std::cout << in2 << std::endl;
    std::cout << "x=" << x << " y=" << y << std::endl;

    char in3[255];
    std::cout << "Please enter a string=";
    std::cin >> x >> in3 >> y;
    std::cout << in3 << std::endl;
    std::cout << "x=" << x << " y=" << y << std::endl;

    std::cout << "Please enter a string AGAIN=";
    std::cin.getline(in3,255);
    std::cin.getline(in3,255);
    std::cout << "in3=" << in3 << std::endl;

    in3 == in3;

    
}