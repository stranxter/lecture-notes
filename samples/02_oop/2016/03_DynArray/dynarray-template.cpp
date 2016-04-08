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

	//"уголемява" буфера така, че да може да побере
	//поне minSize на брой елемента
	void resize (int minSize)
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
		if (index >= size)
			resize (index+1);

		return getElem(index);
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

	template <typename RestType>
	RestType reduce (reduceFn<RestType,T> oper, RestType init)
	{
		RestType result = init;
		for (int i = 0; i < size; i++)
			result = oper (result, arr[i]);

		return result;
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

int sum (int curResult, int crrElem)
{
	return curResult + crrElem;
}

int main ()
{


	DynArr<int> a(2),b(2);

	//cin >> a[2];
	//cout << a[2] << endl;

	a[0] = 1;
	a[1] = 7;
	a[2] = 10;
	a[3] = 100;
	b[0] = b[1] = 1;

	cout << "sum=" << a.reduce (sum,0) << "\n";
	cout << "sum=" << a.reduce<int> ([](int x, int y){return x+ y;},0) << "\n";

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