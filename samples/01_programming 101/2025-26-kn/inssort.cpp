#include <iostream>

const int n = 10;

int main()
{
    int arr[n]={0};
    //int nelemens = 0;

    for(int i = 0; i < n; ++i)
    {
        //i: БРОЙ ВЪВЕДЕНИ ДО МЕМЕНТА ЧИСЛА

        std::cout << "Моля, въвдете " << i << "-то число:";
        int x;
        std::cin >> x;

        /*трябва да разглдаме първите i елемента, за да намерим
        подходящата позиция за x*/
        
        int newpos = 0;

        while(x>=arr[newpos] && newpos < i)
        {
            ++newpos;
        }

        for(int tomove = i-1; tomove >= newpos; --tomove)
        {
            arr[tomove+1]=arr[tomove];
        }

        arr[newpos] = x;        
    }

    std::cout << "[";

    for(int i = 0; i < n; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "]\n";
}