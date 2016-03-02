#include <iostream>
#include <string.h>

using namespace std;

struct A
{
	int x; 
	int y;
	double z;
};

struct Car
{
	char color[20];
	char model[100];

	int yearMade;

	int hp;

	char regn[20];


};

int main ()
{

	int x[99];
	
	A arrA[99];


	A* p = &arrA[95];
	p = arrA + 95;

	cout << arrA[95].y;
	//АНАЛОГИЧНО НА
	cout << p->y;
	//АНАЛОГИЧНО НА
	cout << (arrA+95)->y;	 
	//АНАЛОГИЧНО НА
	cout << (*(arrA+95)).y;	 
	//АНАЛОГИЧНО НА
	cout << (*p).y;	 

	char color1[] = "Red", color2[] = "blue";

	Car car1, car2;

	strcpy (car1.color,"Red");
	strcpy (car2.color, "Blue");

	car1 = car2;



}