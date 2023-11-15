#include <iostream>

void g (long x) 
{   
    int m = 0;
    std::cout << x;
}

void f (long x) 
{
    int z = 10;
    x = x + z;
    g(x);
    std::cout << "I am F";
}
 
int z = 0;


void printSequence(int N)
//std::cout << N...N-1....N-2...0
{
    if (N<0)
    {
        return;
    }
    
    printSequence(N-1); 
    std::cout << N << "...";
}

int enterInt(int min, int max)
{
    std::cout << "Please enter a number between " << min << "and " << max <<":";
    int n;

    std::cin >> n;
    if(n >= min && n <= max)
    {
        return n;
    }
    
    return enterInt(min,max);; 

/*    do
    {
        std::cin >> n;    
    } while (n < min || n > max);
*/
    
}

void printDigits(unsigned int x)
{
    if(x < 10)
    {
        std::cout << x;
    } else 
    {
        std::cout << x%10 << ",";
        printDigits(x / 10);
        
    }
}

bool has5 (unsigned int x)
{
    if(x % 10 == 5)
    {
        return true;
    }
    if(x < 10)
    {
        return false;
    }

    return has5(x/10);
}

bool member(int a[], int start, int end, int x)
//съдържа ли масива числото x между елементите с поредност start и end
{

    return start <= end &&
           (x == a[start] || member(a,start+1,end,x)); 
           

    /*
    if(start > end)
    {
        return false;
    }

    if(a[start] == x)
    {
        return true;
    }

    return member(a,start+1,end,x);
    */
}

int count (int a[], int start, int end, int x)
{

    if(start > end)
    {
        return 0;
    }

    if(a[start] == x)
    {
        return 1+count(a,start+1,end,x);
    }

    return count(a,start+1,end,x);
}

int inc(int x)
{
    z = x;

    int y;
   // std::cin >> y;

    return x+1;
}

int main()
{

    int arr[] = {1,4,5,6,8,4,3,5,4,6};

    std::cout << "member=" << member(arr,0,8,8) << std::endl;

    int a = inc(0) + inc(1) + z;
    std::cout << "a=" << a << std::endl;

    long x = 0;
    f(x);
    std::cout << x << std::endl;

    printSequence(2);

    std::cout << std::endl;

    int z = enterInt(0,2300000);

    std::cout << "z=" << z;

    std::cout << "Digits of z=";
    printDigits(z);

}

