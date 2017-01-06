#include <iostream>
#include <iomanip>

using namespace std;


const int ls = 8;
int lab[ls][ls] = { 0,1,0,0,0,0,0,0,
					0,1,0,0,0,0,0,0, 
					0,1,0,0,0,0,0,0, 
					0,0,0,0,0,0,0,0, 
					1,0,1,0,0,0,0,0, 
					0,0,1,0,0,0,0,0, 
					0,0,1,0,0,0,1,1, 
					0,0,2,0,0,0,1,0};

void markVisited (int lab[ls][ls], int row, int col,bool visited=true)
{
	if (visited)
  		lab[row][col] = 9;
  	else
  		lab[row][col] = 0;
}

bool canStepOn (int lab[ls][ls], int row, int col)
{
  return row >= 0 &&
         col >= 0 && 
         row < ls &&
         col < ls &&
         lab[row][col] == 0;
}

bool wayExists  (int lab[ls][ls], 
				 int startRow, 
				 int startCol,
				 int endRow,
				 int endCol)
{

  markVisited (lab,startRow,startCol);

  if (startRow == endRow && startCol == endCol)
  { 
  	cout << "[" << startRow << "," << startCol << "]";
  	return true; 
  }

  if (canStepOn (lab,startRow+1,startCol) && 
      wayExists (lab,startRow+1,startCol,endRow,endCol))
	{
        cout << "[" << startRow << "," << startCol << "]";
        return true;
	}
  if (canStepOn (lab,startRow,startCol+1) && 
      wayExists (lab,startRow,startCol+1,endRow,endCol))
  {
        cout << "[" << startRow << "," << startCol << "]";
        return true;
  }
  if (canStepOn (lab,startRow-1,startCol) && 
      wayExists (lab,startRow-1,startCol,endRow,endCol))
  {
        cout << "[" << startRow << "," << startCol << "]";
        return true;
  }
  if (canStepOn (lab,startRow,startCol-1) && 
      wayExists (lab,startRow,startCol-1,endRow,endCol))
  {
   		cout << "[" << startRow << "," << startCol << "]";
        return true;
  }

  markVisited (lab,startRow,startCol,false);  
  return false;
}

void printLab (int lab[ls][ls])
{
	for (int row = 0; row < ls; row++)
	{
		for (int col = 0; col < ls; col++)
		{
			cout << setw (3) << lab[row][col];
		}
		cout << endl;
	}
}

int main ()
{
	
	printLab (lab);
	cout << wayExists (lab,0,0,0,7) << endl;
	printLab (lab);	
	return 0;
}