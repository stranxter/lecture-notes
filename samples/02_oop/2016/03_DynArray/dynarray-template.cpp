#include <iostream>
#include <assert.h>

using namespace std;


template <typename T>
class DynArr
{
private:

	T *arr;
	int size;

public:

	DynArr  (const DynArr<T>& other)
	{
		copy (other);
	}

	void operator = (const DynArr<T>& other)
	{

		delete arr;
		copy (other);

	}

private:

	void copy (const DynArr<T>& other)
	{
		arr = new T [other.size];
		size = other.size;

		for (int i = 0; i < size; i++)
			arr[i] = other.arr[i];
	}

public:

	DynArr (int n)
	{
		arr = new T [n];
		size = n;
	}

	T& getElem (int index)
	{	
		assert (index >=0 && index < size);
		return arr[index];
	}

	void setElem (int index, T newValue)
	{
		assert (index >=0 && index < size);
		arr[index] = newValue;
	}

	T& operator [] (int index)
	{	
		return getElem (index);
	}

	bool compareTo (DynArr<T> other)
	{

		if (other.size != size)
			return false;

		for (int i = 0; i < size; i++)
			if (arr[i] != other.arr[i])
				return false;

		return true;
	}

	bool operator == (DynArr<T> other)
	{
		return compareTo (other);
		
	}

	DynArr<T>& operator += (DynArr<T> other)
	{
		assert (size == other.size);

		for (int i = 0; i < size; i++)
			arr[i] += other.arr[i];

		return *this;

	}

	DynArr<T> operator + (const DynArr<T>& other)
	{

		DynArr<T> result (size+other.size);

		for (int i = 0; i < size; i++)
			result.arr[i] = this->arr[i];

		for (int i = 0; i < other.size; i++)
			result.arr[size+i] = other.arr[i];

		return result;
	}

	~DynArr ()
	{
		delete []arr;	
	}

	friend ostream& operator << (ostream& out, const DynArr<int>& ia);
	friend ostream& operator << (ostream& out, const DynArr<char>& ca);
	
	template <typename Z>
	friend ostream& operator << (ostream& out, const DynArr<Z>& ca);


	DynArr<T>& map (T (*f) (T))
	{
		for (int i =0; i < size; i++)
			arr[i] = f(arr[i]);

		return *this;
	}

};//DynArray


ostream& operator << (ostream& out, const DynArr<int>& ia)
{
	out << "{";

	for (int i = 0; i < ia.size; i++)
		out << ia.arr[i] << ",";
	out << "}...";

	return out;
}

ostream& operator << (ostream& out, const DynArr<char>& ca)
{

	for (int i = 0; i < ca.size; i++)
		out << ca.arr[i];

	return out;
}

template <typename T>
T plusOne (T x)
{
	return x+1;
}

template <typename M>
ostream& operator << (ostream& out, const DynArr<M>& a)
{
	out << "GENERIC ARRAY: [";

	for (int i = 0; i < a.size; i++)
		out << a.arr[i] << ",";
	out << "]";

	return out;
}

int main ()
{


	DynArr<int> a(2),b(2);

	//cin >> a[2];
	//cout << a[2] << endl;

	a[0] = a[1] = 0;
	b[0] = b[1] = 1;

	cout << a;

	cout << a+b << endl;

	DynArr<char> s(3);

	s[0]= 'h'; s[1] = 'i'; s[2] = '!';

	cout << s << endl;


	b.map (plusOne);

	cout << b; //{2,2}


	//hi -> ij

	s.map(plusOne);
	cout << s << endl;

	DynArr<bool> ba(2);

	ba[0] = ba[1] = 7;

	cout << ba;


/*	b[2] = 17;

	b = a+b; //a.operator+(b.operaot+(c.operao...))

	cout << b[7] << endl;
*/
}