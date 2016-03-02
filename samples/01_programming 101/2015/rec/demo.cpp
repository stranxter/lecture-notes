#include <iostream>
#include <math.h>

using namespace std;


//брой цифри в десетичния запис на x
int countDigits (int x)
{
	if (x < 10)
		return 1;

	return countDigits (x/10) + 1;
}

//брой цифри в десетичния запис на x
//в б.с. с база k
int countDigits (int x, int k)
{
	if (x < k)
		return 1;

	return countDigits (x/k,k) + 1;
}


void move (int src[],int dest[],int n)
{
	for (int i = 0; i < n; i++)
		dest[i] = src[i];
}

//искаме да слеем сортираните
//масиви a и b в масива c
/*


*/
void merge (int a[], int na,
	        int b[], int nb,
	        int c[])
{
	if (na == 0){
		move (b,c,nb);
		return;
	}
	if (nb == 0){
		move (a,c,na);
		return;
	}

	if (a[0] < b[0])
	{
		c[0] = a[0];
		merge (a+1,na-1,b,nb,c+1);
	} else {
		c[0] = b[0];
		merge (a,na,b+1,nb-1,c+1);
	}
}

int findmin (int a[], int n)
{
	if (n==1)
		return a[0];

	return 
	   min (findmin (a+1,n-1),a[0]);
}

int main ()
{
	cout << countDigits (123) << endl;

	int a[] = {2,10,100,112};
	int b[] = {5,8,1012};
	int c[7] = {434,112,56,32,8,343,223};


	cout << findmin (c,7) << endl;

	merge (a,4,b,3,c);

	for (int i = 0; i < 7; i++)
		cout << c[i]<< " ";

	cout << endl;



}