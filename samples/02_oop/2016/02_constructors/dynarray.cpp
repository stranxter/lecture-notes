#include <iostream>
#include <assert.h>

using namespace std;

class IntArr
{
public:

	int *arr;
	int size;

	IntArr (int n)
	{
		arr = new int [n];
		size = n;
	}

	int& getElem (int index)
	{	
		assert (index >=0 && index < size);
		return arr[index];
	}

	void setElem (int index, int newValue)
	{
		assert (index >=0 && index < size);
		arr[index] = newValue;
	}

	int& operator [] (int index)
	{	
		return getElem (index);
	}

	bool compareTo (IntArr other)
	{

		if (other.size != size)
			return false;

		for (int i = 0; i < size; i++)
			if (arr[i] != other.arr[i])
				return false;

		return true;
	}

	bool operator == (IntArr other)
	{
		return compareTo (other);
		//return this->compareTo (other);
		
	}


};

int main ()
{

	IntArr a(5),b(5),m(12); //масиви с р-р 5

	
	a.setElem(4,1);
	cout << a.getElem(4) << endl;
	cout << a[4] << endl;

	a.getElem(4) = 12;
	cout << a[4] << endl;

	a[4] = 99;
	cout << a[4] << endl;//[]
	
	//cin >> a[4];
	cout << a[4] << endl;


	cout << "a==b:" << a.compareTo(b) << endl;
	cout << "a==b:" << (a == b) << endl;

/*
	if (a == b)
	{
		cout << "Yes, they are equal!";
	}

	IntArr c = a + b;

	c *= 2;

	if (c.length() > b.length())
	{
		cout << "c is longer than b";
	}

	a.print();


	cout << a;

	cin >> a;

	*/
}