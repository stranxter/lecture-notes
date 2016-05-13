#include <iostream>
#include <string>

using namespace std;

#define MAZE_SIZE 5
#define MAZE_ROAD 0
#define MAZE_WALL 1
#define MAZE_JAM 2

//0 - road
//1 - wall
//2 - jam

int maze[MAZE_SIZE][MAZE_SIZE] = {0, 0, 0, 0, 0,
								  1, 1, 2, 1, 1,
								  2, 0, 0, 0, 2,
								  0, 0, 0, 0, 0,
								  0, 0, 0, 0, 0};

class Vehicle{
protected:
	int x;
	int y;

public:


	Vehicle (int _x, int _y):x(_x),y(_y){}

	virtual double speed () = 0;
	virtual bool canMoveTo (int newx, int newy) = 0;
	virtual bool isAlive () = 0;

};

class Scooter : public Vehicle
{
public:

	Scooter (int _x, int _y):Vehicle (_x,_y){}

	double speed () {return 15;}
	bool canMoveTo (int newx, int newy)
	{
		//Scooters can move trough 
		//traffic

		return (maze[newx][newy] == MAZE_ROAD ||
		       maze[newx][newy] == MAZE_JAM) &&
		       abs (x - newx) <= 1 &&
		       abs (y - newy) <= 1;
 	}

 	bool isAlive () {return true;}

 	void moveTo (int newx, int newy)
 	{
 		if (canMoveTo (newx,newy))
 		{
 			x = newx;
 			y = newy;
 		}
 	}

};

class Batmobile : public Vehicle
{
private:
	int lives;

public:

	Batmobile (int _x, int _y):Vehicle (_x,_y)
	{
		lives = 3;
	}


	double speed () {return 99;}
	bool canMoveTo (int newx, int newy)
	{
		//Scooters can move trough 
		//traffic

		return (maze[newx][newy] == MAZE_ROAD ||
		       maze[newx][newy] == MAZE_WALL) &&
		       abs (x - newx) <= 2 &&
		       abs (y - newy) <= 2;
 	}

 	void moveTo (int newx, int newy)
 	{
 		if (!canMoveTo (newx, newy))
 		{
 			lives = 0;
 		}else{
 			if (maze[newx][newy] == MAZE_WALL)
 				lives--;
 		}
		x = newx;
		y = newy;
 	} 	

 	bool isAlive ()
 	{
 		return lives > 0;
 	}


};

int main ()
{
	Vehicle* players[2] = {new Scooter (0,0), new Batmobile(0,2)};


	cout << players[0]->canMoveTo(2,2) << endl 
	     << players[1]->canMoveTo(2,2) << endl;

}
