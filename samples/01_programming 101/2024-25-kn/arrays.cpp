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


int main()
{
    int arr[10];

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


    int arr3[10] = {0};

    insertSorted(arr3,0,10);
    insertSorted(arr3,1,15);
    insertSorted(arr3,2,20);
    insertSorted(arr3,3,0);
    insertSorted(arr3,4,50);

    for(int i = 0; i < 5; ++i)
    {
        std::cout << arr3[i] << " ";
    }

    return 0;
}