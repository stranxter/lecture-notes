#include <iostream>

void inc(int arr[])
{
    ++arr[0];
}

long division (long x, long y, long *remainder) 
{
    *remainder = x - (x/y)*y;
    return x/y; 
}

long division2 (long x, long y, long& remainder) 
{
    remainder = x - (x/y)*y;
    return x/y; 
}



int sumRow(int *m, int cols, int row)
{
    int sum = 0;
    for (int i = 0; i <  cols; ++i)
    {
        sum += *(m + row*cols + i); //m[rows][i]
    }
    return sum;
}

int main()
{
    int a[10] = {0};

    int m[5][5] = {0, 0, 0, 0, 0,
                   0, 0, 0, 0, 0,
                   1, 1, 1, 1, 1,
                   0, 0, 0, 0, 0,
                   0, 0, 0, 0, 0};

    inc(a);
    std::cout << "sum=" << sumRow((int*)m,5,2) << std::endl;

    std::cout << a[0] << std::endl;

    long r;

    division(10,2,&r);
    division2(10,2,r);
    //std::cout << (long)&r << std::endl;

    int **ppi;
    int x = 0, y = 1, z = 2;
    int *px = &x, *py = &y, *pz = &z;

    ppi = &px;

    **ppi = 100;

    ppi = &pz;

    **ppi = 100;



}