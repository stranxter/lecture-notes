#include <iostream>
#include <optional>
#include <string>

/*-std=c++17*/
std::optional<int> safe_input(std::string prompt)
{
    int value;
    std::cout << prompt;
    if (std::cin >> value) {
        return value; 
    } else {
        return std::nullopt;
    }
}

int main()
{
    std::cout << safe_input("Number to increment: ").value_or(0) + 1 
              << std::endl;
    if(std::optional<int> i = safe_input("Number to increment: ")) {
        std::cout << "Valid input received. Result = " << *i + 1 << std::endl;
    } else {
        std::cout << "Sorry, can not increment." << std::endl;
    }
}