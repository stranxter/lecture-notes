#include <iostream>

using namespace std;

template <typename T>
void inputArray (T arr[], size_t size)
{
	for (size_t count = 0; count < size; count++)
	{
		cout << "Please input a[" << count << "]=";
		cin >> arr[count];
	}
}

template <typename T>
int countCommonElements (T a[], T b[], size_t sizea, size_t sizeb)
{
	int count = 0;
	for (size_t ca = 0; ca < sizea; ca++)
	{
		for (size_t cb = 0; cb < sizeb; cb++)
		{
			count += (a[ca] == b[cb]);
		}
	}

	return count;
}

struct Student
{
	int fn;
	char name[1000];
};

template <typename T>
T sumarr (T arr[], size_t size)
{
	T sum = 0;

	for (size_t c = 0; c < size; c++)
	{
		sum += arr[c];
	}

	return sum;
}

template <typename T>
void _swap (T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp; 
}

int myplus (int a, int b)
{
	return a+b;
}

int mymult (int a, int b)
{
	return a*b;
}

int mycountevens (int accumulator, int current_element)
{
	//return accumulator += (current_element % 2 == 0);
	if (current_element % 2 == 0)
		return accumulator + 1;

	return accumulator;
}


int reduce (int arr[], 
	        size_t size, 
	        int null_val, 
	        int (*do_something) (int,int))
{
	int s = null_val;
	for (size_t c = 0; c < size; c++)
	{
		s = do_something (s,arr[c]);
	}

	return s;
}

int replaceEvenNumbersWithZero (int x)
{
	if (x % 2 == 0)	
		return 0;

	return x;
}

void map (int arr[], size_t size, int (*f)(int))
{
	for (size_t c = 0; c < size; c++)
	{
		arr[c] = f(arr[c]);
	}
}

int main ()
{

	int a[] = {1,2,3,4,5};

	map (a,5,replaceEvenNumbersWithZero);

//	map (a,5,[](int x){return x+1;});
//	map (a,5,[](int x){return x*2;});

	cout << reduce (a,5,0,[](int a, int b) {return a+b;}) << endl;
	cout << reduce (a,5,1,mymult) << endl;
	cout << reduce (a,5,0,mycountevens) << endl;



/*	int myArrayI[4] = {0};
	double myArrayD[3] = {0};

	inputArray (myArrayI,4);
	inputArray (myArrayD,3);

	_swap (myArrayI[0],myArrayI[3]);

	char c1 = 'z', c2 = 'a';

	_swap (c1,c2);
*/
}