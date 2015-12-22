#include <iostream>

using namespace std;

const int ls = 8; 
int lab[ls][ls] = {0,1,0,0,0,0,0,0,
                   0,1,0,0,0,0,0,0,
                   0,1,0,0,0,0,0,0,
                   0,0,0,0,0,0,0,0,
                   1,0,1,0,0,0,0,0,
                   0,0,1,0,0,0,0,0,
                   0,0,1,0,0,0,0,0,
                   0,0,2,0,0,0,0,0};


void markVisited (int lab[ls][ls], int row, int col)
{
  lab[row][col] = 9;
}

bool canStepOn (int lab[ls][ls], int row, int col)
{
  return row >= 0 &&
         col >= 0 && 
         row < ls &&
         col < ls &&
         lab[row][col] == 0;
}

bool wayExists  (int lab[ls][ls], int startRow, int startCol)
{
  if (startRow == ls-1 && startCol == ls-1)
  { return true; }

  
  markVisited (lab,startRow,startCol);

  if (canStepOn (lab,startRow+1,startCol) && 
      wayExists (lab,startRow+1,startCol))
        { 
        	cout << "[" << startRow << "," << startCol << "]";
        	return true;
        }
  if (canStepOn (lab,startRow,startCol+1) && 
      wayExists (lab,startRow,startCol+1))
        { 
        	cout << "[" << startRow << "," << startCol << "]";
        	return true;
        }
  if (canStepOn (lab,startRow-1,startCol) && 
      wayExists (lab,startRow-1,startCol))
        { 
        	cout << "[" << startRow << "," << startCol << "]";
        	return true;
        }
  if (canStepOn (lab,startRow,startCol-1) && 
      wayExists (lab,startRow,startCol-1))
        { 
        	cout << "[" << startRow << "," << startCol << "]";
        	return true;
        }
  return false;
}

int main ()
{
	cout << wayExists (lab,0,0) << endl;
}