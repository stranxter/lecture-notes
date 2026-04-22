#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

struct Student
{
    std::string name;
    int age;
};

int main() 
{

    std::ofstream outFile("output.txt");

    outFile << "Hello, World!" << std::endl;
    outFile << 1241245 << std::endl;

    outFile.put(65);
    outFile.close();
 
    std::ifstream inFile("output.txt");
    //std::string str, str2;
    char str[255];

    inFile.getline(str,254);

    std::cout << str << "\n";



    return 0;
}