#include <iostream>
#include <assert.h>

using namespace std;

template <typename T>
class DynArray
{
private:
	T *array; //addressOfFirstElement
	size_t size;

	DynArray ();
	  //за специални случаи: например, за създаване на масив от масиви
		//Това е възможно само в методи на класа
		//в.ж. задачата за "slice" в домашното
		//въпрос: какъв е проблемът на slice, ако този
		//конструктор не съществува?


public:

	DynArray (const DynArray<T>& other);
	DynArray (size_t _size);
	T&  operator [] (const size_t index) const;
	void print ();
	void remove (const T& x);
	size_t getsize ();
	~DynArray ();
	void operator += (const DynArray<T>& other);
	DynArray<T> operator + (const DynArray<T>& other);
	DynArray<T>& operator = (const DynArray<T>& other);
	bool operator == (const DynArray<T>& other);
};

template <typename T>
T& DynArray<T>::operator [] (const size_t index) const
{
	assert (index >= 0 && index < size);
	return array[index];
}

template <typename T>
DynArray<T>::DynArray ()
{ //за специални случаи: например, за създаване на масив от масиви
	//Това е възможно само в методи на класа
	//в.ж. задачата за "slice" в домашното
	//въпрос: какъв е проблемът на slice, ако този
	//конструктор не съществува?
	array = new T [1];
	size = 1;
}

template <typename T>
DynArray<T>::DynArray (const DynArray<T>& other)
{
	//как да преодолеем това array = other.array?;

	size = other.size;
	array = new T[size];
	for (size_t i = 0; i < size; i++)
	{
		array[i] = other.array[i];
	}
}

template <typename T>
DynArray<T>::DynArray (size_t _size)
{
	array = new T [_size];
	size = _size;
}


template <typename T>
void DynArray<T>::print ()
{
	cout << "[";
	for (int count = 0; count < size-1;count++)
	{
		cout << array[count] << ",";
	}
	cout << array[size-1];
	cout << "]" << endl;
}

template <typename T>
void DynArray<T>::remove (const T& x)
{
	size_t index = 0;
	while (index < size && array[index] != x)
	{
			index++;
	}

	assert (index < size);

	T *newarray = new T [size-1];

	size_t i;
	for (i = 0; i < index; i++)//наляво от елемента за изтриване
	{
		newarray[i] = array[i];
	}

	for (i = index+1; i < size; i++)//надясно от елемента за изтриване
	{
		newarray[i-1] = array[i];
	}

	delete array;
	array = newarray;
	size--;
}

template <typename T>
size_t DynArray<T>::getsize ()
{
	return size;
}

template <typename T>
DynArray<T>::~DynArray ()
{
	delete array;
}

template <typename T>
void DynArray<T>::operator += (const DynArray<T>& other)
{
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

template <typename T>
DynArray<T> DynArray<T>::operator + (const DynArray<T>& other)
{
	/*
	DynArray result (*this);
	//result += other;
	*/

	DynArray result(size+other.size);

	size_t i;
	for (i = 0; i < size; i++)
	{
		result.array[i] = array[i];
	}
	for (i = 0; i < other.size; i++)
	{
		result.array[size+i] = other.array[i];
	}
	return result;
}

template <typename T>
DynArray<T>& DynArray<T>::operator = (const DynArray<T>& other)
{
	if (this != &other)
	{
		delete array;

		size = other.size;
		array = new T[size];
		for (size_t i = 0; i < size; i++)
		{
			array[i] = other.array[i];
		}
	}

	return *this;
}

template <typename T>
bool DynArray<T>::operator == (const DynArray<T>& other)
{
	if (size != other.size)
	{
		return false;
	}

	size_t i = 0;
	while (i < size && array[i] == other.array[i])
	{
		i++;
	}

	return i == size;
}

/*===========
Тестове
=============*/

void testCopy ()
{
	DynArray<int> a1(4);
	a1.operator [](0) = 1;
	a1[1] = 2;
	a1[2] = 3;
	a1[3] = 4;

	DynArray<int> a2 (a1);

	a2[0]= 999;
	assert (a1[0] == 1);

	DynArray<int> a3  = a1+a2; // a3(a1+a2)
}

void testRemove ()
{
	DynArray<int> a1(4);
	a1[0] = 1;
	a1[1] = 2;
	a1[2] = 3;
	a1[3] = 4;


	a1.remove (1);
	a1.remove (3);

	assert (a1[0] == 2 && a1[1] == 4);
	a1.print();
}

void testAssign ()
{
	DynArray<int> a1(4);
	a1[0] = 1;
	a1[1] = 2;
	a1[2] = 3;
	a1[3] = 4;

	DynArray<int> a2(2), a3(2);

	//DynArray<int> a2 = a1;
	a3 = a2 = a1;
	//a3.operator = (a2.operator(a1));

	a2[0] = 9;
	assert (a1[0] == 1);
}

void testConcat ()
{
	DynArray<int> a1(3);
	a1[0] = 1;
	a1[1] = 2;
	a1[2] = 3;

	assert ((a1+a1)[3] == 1);
}

int main ()
{
	testConcat();
	testAssign();
	testRemove();
	testCopy();
}
