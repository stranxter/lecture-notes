#include <iostream>
#include <future>
#include <thread>

int getNumberFromInput() {

    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;
    return num;
}



int main() {

    std::future<int> future = std::async(std::launch::async, getNumberFromInput);

    while (future.wait_for(std::chrono::seconds(1)) != std::future_status::ready) {
        std::cout << "Still waiting for input..." << std::endl;
    }

    std::cout << future.get() + 1 << std::endl;

    return 0;
    
}