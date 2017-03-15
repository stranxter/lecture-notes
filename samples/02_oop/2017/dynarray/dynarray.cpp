#include <iostream>
#include <assert.h>

using namespace std;

template <typename T>
class DynArray
{
private:
	T *array; //addressOfFirstElement
	size_t size;
public:

	DynArray (size_t _size)
	{
		array = new T [_size];
		size = _size;
	}

	T& operator [] (size_t index)
	{
		assert (index >= 0 && index < size);
		return array[index];
	}

	void print ()
	{
		cout << "[";
		for (int count = 0; count < size-1;count++)
		{
			cout << array[count] << ",";
		}
		cout << array[size-1];
		cout << "]" << endl;
	}

	void operator += (DynArray<T>& other)
	{
		//this->array == a1.array == [X,X,X,7]
		//other.array == a2.array == [4,4,4]
		//result:
		//this->array == [X,X,X,7,4,4,4]

		T *result = new T [size+other.size];
		size_t count;
		for (count = 0; count < size; count++)
			result[count] = array[count];
		for (count = size; count < size+other.size; count++)
			result[count] = other.array[count-size];


		delete array;
		array = result;
		size = size + other.size;

	}
};

int main ()
{
	
	//int a1[10];
	DynArray<int> a1(4);

	//cout << a1.getIthElement (3) << endl;

	//cout << a1[3] << endl;

	//a1.getIthElement (3) = 7;
	a1[3] = 7;
	a1.print();

	DynArray<int> a2(3);

	a2[0] = a2[1] = a2[2] = 4;

	a1 += a2;

	a1.print();


	/*
	DynArray<int> a2 = a1;

	a2.print();

	if (a1 == a2)
		cout << "YES!\n";

	cout << "size of a2" << s2.size() << endl;

	DynArray<int> a3(2);

	a3 = a1 + a2;
	a3.print();

*/

}