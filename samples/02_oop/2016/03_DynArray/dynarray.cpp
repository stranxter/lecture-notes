#include <iostream>
#include <assert.h>

using namespace std;

class IntArr
{
private:

	int *arr;
	//a.arr = NULL;
	int size;

public:


	//!
	IntArr  (const IntArr& other)
	{
		//this: IntArr*, other: const IntArr&
		//this->arr = v.kjbvkjbvjkdfbvdjzbv
		//this->size = sdcjknsdkcnkcjnsckjsncjkasncka
		//other.arr = {x,y,z,...}
		//other.size = N

		//искаме this->arr = {x,y,z,...}'

		copy (other);
	}

	void operator = (const IntArr& other)
	{


		//this: IntArr*, other: const IntArr&
		//this->arr = v.kjbvkjbvjkdfbvdjzbv - НЕ!
		//this->arr = {a,b,c,d,...}
		//this->size = sdcjknsdkcnkcjnsckjsncjkasncka - НЕ!!
		//this->size = M
		//other.arr = {x,y,z,...}
		//other.size = N

		//искаме this->arr = {x,y,z,...}'

		delete arr;
		copy (other);

	}


private:
	void copy (const IntArr& other)
	{
		arr = new int [other.size];
		size = other.size;

		for (int i = 0; i < size; i++)
			arr[i] = other.arr[i];

	}
public:

	IntArr (int n)
	{
		arr = new int [n];
		size = n;
	}

	//a.getElem (5) = 3;
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

	//a[4] = 3;
	//cout << a[4] + 1;
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

	//a += b; <=> a.operator += (b); 
	//x = a += b;
	//(a+=b).print();
	//(u+=v)[1] = 7;

	IntArr& operator += (IntArr other)
	{
		assert (size == other.size);
		//assert (this->size == other.size);
		//this->arr | указател към масив със size елемтнта
		//other.arr | указател към масив със size елемтнта

		for (int i = 0; i < size; i++)
			arr[i] += other.arr[i];
		//arr[i] = arr[i] + other.arr[i];

		return *this;

	}

	//IntArr c(....);
	//c=a+b; (a+b).print();
	//(u+v)[1] = 7;
	IntArr operator + (IntArr other)
	{
		assert (size == other.size);

		IntArr result (size);

		for (int i = 0; i < size; i++)
			result.arr[i] = this->arr[i] + other.arr[i];

		return result;
	}

	void print ()
	{

		cout << "{";
		for (int i = 0; i < size; i++)
			cout << arr[i] << ",";
		cout << "}\n";

	}

	void read ()
	{
		for (int i = 0; i < size; i++)
		{
			cout << "[" << i << "]=";
			cin >> arr[i];
		}

	}

	~IntArr ()
	{
		delete []arr;	
	}



	//a - cout; //a.operator-(cout);
/*	void operator >> (ostream& out)
	{

		out << "{";
		for (int i = 0; i < size; i++)
			out << arr[i] << ",";
		out << "}\n";	
	} НЕ!!!*/

	friend ostream& operator << (ostream& out, const IntArr& ia);

};//IntArray

ostream& operator << (ostream& out, const IntArr& ia)
{
	out << "{";
	for (int i = 0; i < ia.size; i++)
		out << ia.arr[i] << ",";
	out << "}...";

	return out;
}


void f ()
{
	//....
	IntArr x(20);
	//...
	//x.arr

}

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


	IntArr u(3), v(3);

	//u.read(); v.read();

	cout << "u+=v:\n";
	(u += v)[1] = 100;
	u.print();

	cout << "u+v:\n";
	u.print();
	(u+v).print();
	cout << "u\n";
	u.print();

	(u+=v)[1] = 7;

	(u+v)[1]=120;

	int x = 0, y (x); //y=x

	cout << y;
	y = 12;
	cout << x;

	IntArr z(3);
	z[0] = z[1] = z[2] = 7;

	z.print ();

	IntArr r = z; // COPY

	r.print ();
	r[0] = 20;

	cout << z[0] << endl; //expcted 0

	r = z; // ASSIGNMENT

	r.print ();
	r[0] = 20;

	cout << z[0] << endl; //expcted 0

	cout << "=============\n";

	//printArray (cout,z);
	cout << z << "Yeah!";
	//operator << (operator << (z,cout), "Yeah");


/*

	cout << a; ostream cout;

	cin >> a; istream cin;

	*/
}