#include <assert.h>
#include <iostream>

using namespace std;

class Rational
{

private:

	int nom;
	unsigned int denom;

public:

	//конструктор
	/*...*/ Rational (int i)
	{
		nom = i;
		denom = 1;
	}

	//конструктор
	/*...*/ Rational (int nom, int denom)
	{
		init (nom,denom);
	}

	void init (int i)
	{
		nom = i;
		denom = 1;
	}

	void init (int nom, unsigned denom)
	{
		assert (denom != 0);
		this->nom = nom;
		this->denom = denom;
	}

	Rational operator + (Rational other)
	{
	//r4 = r1 + r2;

		Rational result;
		result.init (this->denom*other.nom +this->nom*other.denom,
			         this->denom*other.denom);
		return result;
	}

	Rational operator * (int x)
	{
		Rational result;
		result.init (nom*x,denom);

		return result;
	}

	Rational operator * (Rational other)
	{
		Rational result;

		result.nom = nom*other.nom;
		result.denom = denom*other.denom;

		return result;
	}

	bool operator > (Rational other)
	{
		return nom*other.denom>other.nom*denom;
	}

	bool operator == (Rational other)
	{
		return nom*other.denom == other.nom*denom;
	}

	void print ()
	{
		cout << nom 
			 << "/" 
			 << denom
			 << endl;
	}

	Rational ()
	{
		denom = 1;
	}

};

Rational operator * (int x, Rational rat)
{

	return rat * x;
	
}

int main ()
{

	//int x = 0; <=> int x (0);


	Rational r (3,4); //r(0);

	r.print ();

	Rational r1(),r2(),r3(),r4();

	//r1.nom = 10;
	//r1.denom = 5;
	r1.init (10,5);

	r2.init (7,3);
	r3.init (8,3);



	r4 = r1 + r2;

	r4 = r4 * r3;

	r4 = r4 + r3*(r4+r1);

	r4.print();

	r4 = r4 * 8;
	r4 = r4.operator*(8);

	r4 = 8 * r4;

	if (r4 == r3)

		cout << "YES!\n";

	//r4 = (r1+r2)*r3;
}