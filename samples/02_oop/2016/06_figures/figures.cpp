#include <iostream>
#include <string.h>

using namespace std;

class Figure
{
public:
	char name[15];
	virtual double surface () = 0; 
};

class Square : public Figure 
{
protected:
	double a;
public:
	Square (double _a):a(_a){}

	double surface ()
	{
		return a*a;
	}

	double perim ()
	{
		return 4*a;
	}

};

//WRONG! IS_A IS VIOLATED
class Rectangle : public Square
{
private:
	double b;
public:
	Rectangle (double _a, double _b):Square(_a),b(_b){}

	double surface ()
	{
		return a*b;
	}

};


class Circle : public Figure
{
private:
	double r;
public:
	Circle (double _r):r(_r){}

	double surface ()
	{
		return 3.14*r*r;
	}

	double perim ()
	{
		return 2*3.14*r;
	}

};


Circle f ()
{
	return Circle (2);
	/*
	Cicrcle c (2);
	return c;
	*/
}

//double sumSurf (Circle *circles, int n)
double sumSurf (Figure *figures[], int n)
{
	double sum = 0;
	for (int i = 0; i < n; i++)
		sum += figures[i]->surface();

	return sum;
}

int main ()
{

	Rectangle r (1,2);

	Circle c1 (1);
	Circle c2 (2); 
	Square s1 (2);
	Square s2 (5);
    Circle c3 (3);


	Figure *f[] = {&c1, &c2, &s1, &s2, &c3};

	cout << sumSurf (f,5) << endl;



/*    Circle circle1 (2);
    strcpy (circle1.name,"Kalin");

    Figure figure1 = circle1;

    cout << figure1.name << figure1.surface();
*/


  /*  Circle circle1 (2);
    strcpy (circle1.name,"Kalin");

    Figure *figure1 = &circle1;

    figure1->name[0] = 'M';
    cout << circle1.name << endl;
    cout << figure1->surface() << endl;
*/


 }