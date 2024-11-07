#include <iostream>

using namespace std;


int sumarray(int a[10])
{
    int sum = 0;

    for(int n = 0; n < 10; ++n)
    {
        sum += a[n];
    }

    return sum;
}

int arraymax(int a[10])
{ //1 2 3 4 5 4 3 2 1 

    int biggestNumberSoFar = a[0];

    for(int n = 1; n < 10; ++n)
    {
        if(a[n]>biggestNumberSoFar)
        {
            biggestNumberSoFar=a[n];
        }
    }
    return biggestNumberSoFar;

}

bool member(int arr[10],int x)
{
    int n = 0;
    while(n < 10 && arr[n] != x)
    {++n;}

    return n < 10;

    /*
    for(int n = 0; n < 10; ++n)
    {
        if(arr[n]==x)
        {
            return true;
        }
    }
    return false;
    */
}

bool positive(int arr[10])
{
    int n = 0;
    while(n<10 && arr[n]>0)
    {
        ++n;
    }
    return n == 10;
    /*
    for(int n = 0; n < 10; ++n)
    {
        if(arr[n]<0)
        {
            return false;
        }
    }
    return true;
    */
}

bool moreevens(int arr[10])
{
    int countEvens = 0;
    for(int i=0;i<10;++i)
    {
        if(arr[i]%2==0)
        {
            ++countEvens;
        }
    }
    return countEvens>5;
}

//0 1 2 3 1 2 3 4 5 6
//0 5 1 2 3 4 5 6 7 8
//0 1 2 3 4 5 6 7 8 9
int longestAscendingPrefix(int arr[10])
{
    int n = 0;
    while(n<10-1 && arr[n]<arr[n+1])
    {
        ++n;
    }
    return n;
}

bool ascending(int arr[10])
{
    return longestAscendingPrefix(arr) == 10;
}

bool isSubset(int arr1[10], int arr2[10])
{
    int n = 0;
    while(n<10 && member(arr2,arr1[n]))
    {
        ++n;
    }
    return n == 10;
}

//колко от елементите в началото на масива са <= x
/*

   10 20 30 40 50 60 70 X X X | x = 45
                ^
                |
    0  1  2  3  4  5  6 7 8 9
*/

int smallerPrefixLength(int x, int arr[10], int length)
{
    int current = 0;
    while(arr[current] <= x && current < length)
    {
        ++current;
    }

    return current;
}

//премества надясно елементите на масива ОТ елемента 
//firtToMove нататък
/*
                |-------->
   10 20 30 40 50 60 70 X X X 
                ^
                |
    0  1  2  3  4  5  6 7 8 9
*/

void shiftRight(int arr[10],int firstToMtove, int arrLength)
{
/*
   10 20 30 40 50 60 70 X X X 
                ^
                |
    0  1  2  3  4  5  6 7 8 9
*/

    for(int i = arrLength; i > firstToMtove; --i)
    {
        arr[i] = arr[i-1];
    }
}

void insertSorted(int arr[10],int length,int x)
{
    int placeToInsert = smallerPrefixLength(x,arr,length);
    shiftRight(arr,placeToInsert,length);
    arr[placeToInsert]=x;
}

/*
    търсим минималния елемент в подмасива на arr, 
    започващ с елемента с индекс from
*/
//X X X X X X Y Y Y Y Y Y Y Y Y Y Y Y
//            ^
//            |
//          from
int findMinIndexInSubarray(int arr[10], int from)
{
    int minCandidate = from;
    for(int i = from; i < 10; ++i)
    {
        if(arr[i]<arr[minCandidate])
        {
            minCandidate = i;
        }
    }
    return minCandidate;
}

void swap(int arr[10], int i, int j)
{
    int save = arr[j];
    arr[j] = arr[i];
    arr[i] = save;
}

void ssort(int arr[10])
{
    for(int sortedPrefixLength = 0; sortedPrefixLength < 10; ++sortedPrefixLength)
    {
        //X X X X X X Y Y Y Y Y Y Y Y Y Y Y Y 
        //            ^
        //            |
        //      sortedPrefixLength
        int minIndex = findMinIndexInSubarray(arr,sortedPrefixLength);

        //X X X X X X Y Y Y Y Y Y Y Y Y Y Y Y 
        //            ^               ^
        //            |               |
        //      sortedPrefixLength    |
        //                          minIndex
        swap(arr,sortedPrefixLength,minIndex);
    }
}

/*
void insertSorted(int arr[10],int count,int x)
{
    //пореден номер на елемент в масива, където би следвало да запишем x
    int insertPosition  = 0;

    while(insertPosition < count &&
          arr[insertPosition] <= x)

    {
        ++insertPosition;    
    }
    //{10,20,....} +15, insertPosition = 1
    for(int i = count-1; i >= insertPosition; --i)
    {
        arr[i+1]=arr[i];
    }

    arr[insertPosition] = x;

}
*/

void merge(int arr1[5], int arr2[5], int result[10])
{

/*
    0 0 0 0 0 X X X X X 
    1 1 1 1 1 Z Z Z Z Z
*/

    int i1 = 0, i2 = 0;
    while(i1+i2 < 10)
    {
        if(i1 < 5 && arr1[i1]<arr2[i2])
        {
            //случай, в който вземеме елемент от arr1
            result[i1+i2]=arr1[i1];
            ++i1;

        } else if (i2 < 5)
        {
            //случай, в който вземеме елемент от arr2
            result[i1+i2]=arr2[i2];
            ++i2;
        }
    }  

}

int main()
{
    int arr[10];
/*
    for(int n = 0; n < 10; ++n)
    {
        cout << "Моля, въдедете число номер " << n << ":";
        cin >> arr[n];
    }

    int arr2[10] = {10,20,30,40,50,60,70,80,90,100};   

    cout << "sum=" << sumarray(arr) << endl;
    cout << "max=" << arraymax(arr) << endl;
    cout << "member 5=" << member(arr,5) << endl;
    cout << "positive=" << positive(arr) << endl;
    cout << "moreevens=" << moreevens(arr) << endl;
    cout << "ascendingprefix=" << longestAscendingPrefix(arr) << endl;
    cout << "isSubset=" << isSubset(arr,arr2) << endl;

*/

/*
    int arr3[10] = {0};

    insertSorted(arr3,0,10);
    insertSorted(arr3,1,15);
    insertSorted(arr3,2,20);
    insertSorted(arr3,3,0);
    insertSorted(arr3,4,50);

*/

/*
    int arr4[10] = {7,2,1,10,3,76,3,-12,0,99};

    ssort(arr4);

    for(int i = 0; i < 10; ++i)
    {
        std::cout << arr4[i] << " ";
    }
*/


    int arr5[5] = {10,20,30,40,50};
    int arr6[5] = {11,12,13,20,1000};
    int arr7[10] = {0};

    merge(arr5,arr6,arr7);

    for(int i = 0; i < 10; ++i)
    {
        std::cout << arr7[i] << " ";
    }

    return 0;
}