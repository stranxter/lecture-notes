#ifndef __DYNARRAY_H
#define __DYNARRAY_H

#include <iostream>
#include <assert.h>

using namespace std;

template <typename ResT , typename ElemT > 
using reduceFn = ResT (*) (ResT, ElemT);


template <typename T>
class DynArr
{
private:

	T *arr;
	int size;

public:

	DynArr  (const DynArr<T>& other);
	void operator = (const DynArr<T>& other);

private:

	void copy (const DynArr<T>& other);

	//"уголемява" буфера така, че да може да побере
	//поне minSize на брой елемента
	void resize (int minSize);

public:

	DynArr (int n);
	T& getElem (int index);
	void setElem (int index, T newValue);
	T& operator [] (int index);
	bool compareTo (DynArr<T> other);
	bool operator == (DynArr<T> other);
	DynArr<T>& operator += (DynArr<T> other);
	//добавя нов елемент в край на масива,
	//разширявайки го с един елемент
	DynArr<T>& operator += (const T& elem);
	int length();
	DynArr<T> operator + (const DynArr<T>& other);
	~DynArr ();

	template <typename RestType>
	RestType reduce (reduceFn<RestType,T> oper, RestType init);

	friend ostream& operator << (ostream& out, const DynArr<int>& ia);
	friend ostream& operator << (ostream& out, const DynArr<char>& ca);
	
	template <typename Z>
	friend ostream& operator << (ostream& out, const DynArr<Z>& a);


	DynArr<T>& map (T (*f) (T));

};//DynArray


template <typename T>
DynArr<T>::DynArr  (const DynArr<T>& other)
{
	copy (other);
}

template <typename T>
void DynArr<T>::operator = (const DynArr<T>& other)
{

	delete arr;
	copy (other);

}

template <typename T>
void DynArr<T>::copy (const DynArr<T>& other)
{
	arr = new T [other.size];
	size = other.size;

	for (int i = 0; i < size; i++)
		arr[i] = other.arr[i];
}

//"уголемява" буфера така, че да може да побере
//поне minSize на брой елемента
template <typename T>
void DynArr<T>::resize (int minSize)
{
	//Дадено:
	//arr - масив със size на брой елемента
	//size < minSize
	//искаме: arr - масив с minSize елемента,
	//освен първите size елемрнта на arr се запазват

	T* newArray = new T[minSize];

	for (int i = 0; i < size; i++)
		newArray[i] = arr[i];

	delete []arr;

	arr = newArray;
	size = minSize;
}

template <typename T>
DynArr<T>::DynArr (int n)
{
	arr = new T [n];
	size = n;
}

template <typename T>
T& DynArr<T>::getElem (int index)
{	
	assert (index >=0 && index < size);
	return arr[index];
}

template <typename T>
void DynArr<T>::setElem (int index, T newValue)
{
	assert (index >=0 && index < size);
	arr[index] = newValue;
}



template <typename T>
T& DynArr<T>::operator [] (int index)
{	
	if (index >= size)
		resize (index+1);

	return getElem(index);
}

template <typename T>
bool DynArr<T>::compareTo (DynArr<T> other)
{

	if (other.size != size)
		return false;

	for (int i = 0; i < size; i++)
		if (arr[i] != other.arr[i])
			return false;

	return true;
}

template <typename T>
bool DynArr<T>::operator == (DynArr<T> other)
{
	return compareTo (other);
	
}

template <typename T>
DynArr<T>& DynArr<T>::operator += (DynArr<T> other)
{
	assert (size == other.size);

	for (int i = 0; i < size; i++)
		arr[i] += other.arr[i];

	return *this;

}

template <typename T>
DynArr<T> DynArr<T>::operator + (const DynArr<T>& other)
{

	DynArr<T> result (size+other.size);

	for (int i = 0; i < size; i++)
		result.arr[i] = this->arr[i];

	for (int i = 0; i < other.size; i++)
		result.arr[size+i] = other.arr[i];

	return result;
}

template <typename T>
DynArr<T>::~DynArr ()
{
	delete []arr;	
}

template <typename T> template <typename RestType>
RestType DynArr<T>::reduce (reduceFn<RestType,T> oper, RestType init)
{
	RestType result = init;
	for (int i = 0; i < size; i++)
		result = oper (result, arr[i]);

	return result;
}

template <typename T>
DynArr<T>& DynArr<T>::map (T (*f) (T))
{
	for (int i =0; i < size; i++)
		arr[i] = f(arr[i]);

	return *this;
}

ostream& operator << (ostream& out, const DynArr<int>& ia)
{
	out << "[";

	for (int i = 0; i < ia.size-1; i++)
		out << ia.arr[i] << ",";

	if (ia.size > 0)
		out << ia.arr[ia.size-1];
	
	out << "]";

	return out;
}

ostream& operator << (ostream& out, const DynArr<char>& ca)
{

	for (int i = 0; i < ca.size; i++)
		out << ca.arr[i];

	return out;
}



template <typename M>
ostream& operator << (ostream& out, const DynArr<M>& a)
{
	out << "{\n";

	for (int i = 0; i < a.size; i++)
		out << a.arr[i] << endl;

	out << "}";

	return out;
}

template <typename T>
DynArr<T>& DynArr<T>::operator += (const T& elem)
{
	(*this)[size] = elem;
}

template <typename T>
int DynArr<T>::length()
{
	return size;
}


#endif
