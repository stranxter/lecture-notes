#include <iostream>

using namespace std;

class Airplane
{

private:

	double crrAirSpeed, maxAirSpeed;
	char model[100];

public:

	void fly ()
	{
		crrAirSpeed = maxAirSpeed;
	}

	void land ()
	{
		crrAirSpeed = 0;
	}

	bool isFlying ()
	{
		return crrAirSpeed == maxAirSpeed;
	}

	bool areYOUFasterThan (Airplane otherPlane)
	{
		return this->crrAirSpeed > otherPlane.crrAirSpeed;
	}

	void initYourself (double ms)
	{
		this->crrAirSpeed = 0;
		this->maxAirSpeed = ms;
	}
};

int main ()
{
	Airplane a1, a2;
	
	a1.initYourself (100);
	a2.initYourself (300);

	a1.fly();

	cout << "is it true that a1 is faster than a2=" 
	     << a1.areYOUFasterThan (a2);



}