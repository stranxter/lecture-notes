#include <iostream>

using namespace std;

class Rat
{
private:
	int nom, denom;
public:
	void init (int nom, int denom)
	{
		this->nom = nom;

		if (denom != 0)
			this->denom = denom;
		else
			denom = 1;
	}

	void read ()
	{
		int n,d;
		cout << "Enter nominator:";
		cin >> n;
		cout << "Enter denominator:";
		cin >> d;

		init (n,d);
	}

	void print ()
	{
		cout << "Nominator = " << nom << " Denominator = " << denom << endl;
	}

	Rat plus (Rat other)
	{
		Rat result;
		result.init (nom*other.denom + denom*other.nom, 
			         denom * other.denom);
		return result;
	}

	Rat operator + (Rat other)
	{
		Rat result;
		result.init (nom*other.denom + denom*other.nom, 
			         denom * other.denom);
		return result;
	}

	Rat mult (Rat other)
	{
		Rat result;
		result.init (nom*other.nom, 
			         denom * other.denom);
		return result;
	}

	Rat operator * (Rat other)
	{
		Rat result;
		result.init (nom*other.nom, 
			         denom * other.denom);
		return result;
	}



};

int main ()
{

	Rat r1,r2,r3;

	r1.read(); r2.read();

	r1.mult (r1.plus(r2.mult(r1))).print();

	r3 = r1 * (r1 + r2 * r1);
	r3.print();

}


