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

    const int maxWordSize = 20;
    const int allWords = 100;
    const int n = 20;

    char uniqueWords[n][maxWordSize];
    int uniqueWordsSoFar = 0;

    for (int i = 0; i < allWords; ++i)
    {
        char word[maxWordSize];
        cin >> word;
        for (int j = 0; j < n; ++j)
        {
            if (strcmp (uniqueWords[j],word) == 0)
            {

            }
        }    
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


    char s[255];
    cin.getline (s,254);
    
    //toLowerCase (s);
    //cout << s << endl;

    showHistogram (s);


}
