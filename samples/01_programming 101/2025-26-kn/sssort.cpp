#include <iostream>


unsigned minelindex(int arr[], unsigned size)
{
    if(size == 1)
    {
        return 0;
    }    
    //[] [] [] [] [] [] [] [] [] [] [] []
    //([] [] [] [] [X] [] [] [] [] [] []) []
    int minrest = minelindex(arr,size-1);
    if(arr[size-1] < arr[minrest])
    {
        return size-1;
    } else 
    {
        return minrest;
    } 
}

void ssortrec(int arr[], unsigned size)
{
    if(size <= 1)
    {
        return;
    }
    //([] [] [] [] [] [] [] [] [] [] []) [] -> (arr,size-1)
    //Y ([] [] [] [] [] [] X [] [] [] []) -> (arr+1,size-1)

    std::swap(arr[0],arr[minelindex(arr,size)]);
    //X ([] [] [] [] [] [] Y [] [] [] [])
    ssortrec(arr+1,size-1);

}

void ssortiter(int arr[], unsigned n)
{
    for(int i = 0; i < n; ++i)
    {
        /*Всички елементи вляво от i-тия са подредени и са 
          по-малки или равни от останалите ("готови")
        */
        //1. Намирам най-малкия от оставащите
        int minIndex = i;

        for(int j = i+1; j < n; ++j)
        {
            if(arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        //minInded е индексът на най-малкия елемент от "неготовите"
        //2. Разменяме местата на arr[i] и arr[minIndex]
        int save = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = save;
    }
}

/*Пренарежда елементите на масива a, така че елементие, 
  по-малки или равни на pivot да предхождат елементите,
  по-големи от pivot.
  Връща броя на по-малките елементи 
*/
unsigned split(int a[], unsigned size, int pivot)
{
    unsigned current = 0, //всички наляво от current са по-малки от pivot
             search = current; //следващ кандидат за по-голям от pivot
                               //search търси "елемента, коийто трябва да бъде разменен с current"
                               
                               //ИНВАРИАНТ:
                               //всички наляво от current са по-малки от pivot
                               //search>=current
                               //елементи между current и start са по-големи от pivot
                                

    while(current < size && search < size)
    {
        if(a[current] <= pivot)
        {
            ++current;
            search = std::max(search, current);
        } else //a[current] > pivot; гарантирано е, че current е по-голям от pivot
        {
            if(a[search] <= pivot) //трябва да си сменяат местата
            {
                std::swap(a[current],a[search]);
                ++current;
            } else 
            {
                ++search;          
            }
        }    
    }
    return current;
}


void quicksort(int a[], unsigned size)
{
    if (size <= 1)
    {
        return;
    }

    //P [] [] [] [] [] [] [] [] [] [] 
    unsigned countSmaller = split(a+1,size-1,a[0]);
    //P [<=] [<=] [<=] [<=]  [>] [>] [>] [>] [>] [>] 
    std::swap(a[0],a[countSmaller]);
    //[<=] [<=] [<=] [<=] P  [>] [>] [>] [>] [>] [>] 
    quicksort(a,countSmaller);
    //[<= <= <= <=] P [>] [>] [>] [>] [>] [>] 
    quicksort(a+1+countSmaller,size-1-countSmaller);
    //[<= <= <= <=] P [> > > > > >] 

}

const int n = 10;
int main()
{
    int arr[n] = {14,24,78,52,4686,5,124,47,689,63};

    /*
    for(int i = 0; i < n; ++i)
    {
        std::cout << "Моля, въвдете " << i << "-то число:";
        std::cin >> arr[i];

    }*/

    //ssortiter(arr,n);
    //ssortrec(arr,n);

    //std::cout << "[";
    //std::cout << split(arr,10,100) << std::endl;
    quicksort(arr,10);

    for(int i = 0; i < n; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "]\n";

}

