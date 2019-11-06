#include <iostream>
#include <cstring>
using namespace std;

//намира най-голямото измежду 
//няколко въведени от клавиатурата числа
void findMaxGrade ()
{
    double mark;
    cin >> mark;

    double maxuntilnow = 0;

    for (int count = 1; count < 3; ++count)
    {
        cin >> mark;
        if (mark > maxuntilnow)
        {
            maxuntilnow = mark;
        }
    }

    cout << "Max grade=" << maxuntilnow << endl;
}

void printAllMatches (int arr[], int size)
{
    for (int crr = 0; crr < size-1; ++crr)
    {
        for (int i = crr + 1; i < size; ++i)
        {
            if (arr[i] == arr[crr])
            {
                cout << "Match found at ("
                     << crr
                     << ","
                     << i
                     << ")"
                     << endl;
            }
        }
    }
}

void mergeSortedArrays (int left[], 
                        int right[],
                        int size,
                        int result[])
{
    int leftindex = 0,
        rightindex = 0;

    while (leftindex < size && rightindex < size)
    {
        if (left[leftindex] < right[rightindex])
        {
            result[leftindex+rightindex] = left[leftindex];
            ++leftindex;
        } else 
        {
            result[leftindex + rightindex] = right[rightindex];
            ++rightindex;
        }
    }
    while (leftindex < size)
    {
        result[leftindex+rightindex] = left[leftindex];
        ++leftindex;
    }
    while (rightindex < size)
    {
        result[leftindex + rightindex] = right[rightindex];
        ++rightindex;
    }
}

void inputArray (int arr[], int size)
/*
    Внимание, масивът се променя и в main! Защо???
*/
{
    for (int i = 0; i < size; ++i)
    {
        cout << "arr[" << i << "]=";
        cin >> arr[i];
    }

}

void printArray (int arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << "arr[" << i << "]=" << arr[i] << endl;
        
    }
}

//приемаме, че работим само с латински букви
void toLowerCase (char s[])
{
    int size = strlen(s);

    for (int i = 0; i < size; ++i)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] += 'a' - 'A';
        }
    }
}

void showHistogram (char s[])
{
    int size = strlen(s);

    int counters[26] = {0};

    toLowerCase(s);

    for (int i = 0; i < size; ++i)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            counters[s[i] - 'a']++;
        }
    }

    for (int i = 0; i < 26; i++)
    {
        cout << (char)('a'+i) << ":" << counters[i] << endl;
    }
}

//Задача: При въведени 200 думи от клавиатурата,
//        да се изведат първите 20 от тях, които
//        са различни поимежду си
void findFirstNUniqueWords ()
{

    const int maxWordSize = 25;
    const int allWords = 500;
    const int n = 50;

    char uniqueWords[n][maxWordSize+1];
    int counters[n] = {0};
    int uniqueWordsSoFar = 0;

    for (int i = 0; i < allWords && uniqueWordsSoFar < n; ++i)
    {
        char word[maxWordSize+1];
        cin >> word;
        toLowerCase (word);

        int current = 0;
        while (current < uniqueWordsSoFar &&
               strcmp (uniqueWords[current],word) != 0)
        {   //word е различен от първите current на брой
            //думи в uniqueWords
            ++current;
        }
        if (current == uniqueWordsSoFar)
        {
            strcpy (uniqueWords[uniqueWordsSoFar],word);
            ++uniqueWordsSoFar;
            counters[current] = 1;
        } else {
            ++counters[current];
        }
    }

    cout << "Unique words count = " << uniqueWordsSoFar << endl;

    for (int i = 0; i < uniqueWordsSoFar; i++)
    {
        cout << "word[" 
             << i 
             << "]="
             << uniqueWords[i]
             << "("
             << counters[i]
             << ")"
             << endl;
    }
}

void insertionSortExample ()
{
    const int maxElements = 15;
    int elements[maxElements];

    for (int i = 0; i < maxElements; i++)
    {
        /*
            i: брой въведени и сортирани до 
               този момент числа
            elements: първите i елемента на този
                      масив са сортирани
        */
        int newElement;
        cin >> newElement;

        /*
            Търсим първото от вече сортираните числа,
            което е по-голямо от newElement
        */
        int desiredIndex = 0;
        while (desiredIndex < i &&
               elements[desiredIndex] < newElement)
        {
            ++desiredIndex;
        }
        //случаят на вмъкване най-вдясно е частен случай,
        //при който цикъла по-долу ще направи 0 стъпки
        for (int toMove = i-1; toMove >= desiredIndex; --toMove)
        {
            elements[toMove + 1] = elements[toMove];
        }
        elements[desiredIndex] = newElement;
    }

    cout << "====SORTED ARRAY=====\n";
    printArray (elements,maxElements);
}

//избутва вдясно елементите на масива 
//с индекси между from  и to
//допускаме, че масивът има поне to+1 елемента
void shiftArray (int a[], int from, int to)
{
    for (int toMove = to; toMove >= from; --toMove)
    {
        a[toMove+1] = a[toMove];
    }
}

int countSmallerThanX (int a[], int size, int x)
{
    int count = 0;
    while (count < size && a[count] < x)
    {
        ++count;
    }

    return count;
}

void insertionSortExample2()
{
    const int maxElements = 5;
    int elements[maxElements];
    int newElement;

    for (int i = 0; i < maxElements; i++)
    {
        cin >> newElement;

        int desiredIndex = countSmallerThanX (elements,i,newElement);
        shiftArray (elements,desiredIndex,i-1);
        elements[desiredIndex] = newElement;
    }

    cout << "====SORTED ARRAY=====\n";
    printArray(elements, maxElements);
}

int findIndexOfMinElement (int a[], int from, int to)
{
    int index = from;
    for (int i = from+1; i <= to; ++i)
    {
        if (a[i] < a[index])
        {
            index = i;
        }
    }
    return index;
}

void swap (int a[], int i1, int i2)
{
    int save = a[i1];
    a[i1] = a[i2];
    a[i2] = save;
}

void sssort (int a[], int size)
{
    for (int i = 0; i < size-1; i++)
    {
        /*
            Всички елементи на масива с индекси по-малки
            от i са вече подредени по местата си
        */

       //1. Намираме най-малкия елемент измежду елементите
       //   с индекси >= i
       int minel = findIndexOfMinElement (a,i,size-1);
       swap (a,i,minel);

    }
}


int main ()
{

//проерка дали в множество от числа,
//въведени от клавиатурата, има
//поне две еднакви

    //int arr[5];
    //inputArray (arr,5);
    //printAllMatches (arr,10);

//сливане на два сортирани масива
//[1,4,7,10,12] ++ [2,2,8,20,20] 
//   -> [1,2,2,4,7,8,10,12,20,20]

    //int arr2[5];
    //inputArray (arr2,5);

    //int result[10];
    //mergeSortedArrays (arr,arr2,5,result);
    //printArray (result,10);


    //char s[255];
    //cin.getline (s,254);
    
    //toLowerCase (s);
    //cout << s << endl;

    //showHistogram (s);

    //findFirstNUniqueWords ();

    //insertionSortExample2();

   int arr[10];
   inputArray (arr,10);

   sssort(arr,10);

   cout << "====SORTED ARRAY======\n";
   printArray (arr,10);

}
