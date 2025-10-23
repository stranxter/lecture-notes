#include <iostream>

const int n = 10;

int main()
{
    int arr[n];

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


    }

}