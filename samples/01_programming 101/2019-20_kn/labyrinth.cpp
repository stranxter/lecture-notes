#include <iostream>
using namespace std;

const int labsize = 8;
int lab[labsize][labsize] = {0, 1, 0, 0, 0, 0, 0, 0, 
                             0, 1, 0, 0, 0, 0, 0, 0,
                             0, 1, 1, 0, 1, 0, 0, 0,
                             0, 0, 1, 0, 1, 0, 0, 0,
                             0, 0, 1, 1, 1, 0, 0, 0,
                             0, 0, 0, 0, 0, 0, 1, 0,
                             0, 0, 1, 0, 0, 0, 1, 0,
                             0, 0, 2, 0, 0, 0, 1, 0};


bool canStepOn (int row, int col)
{
    return row >= 0 &&
           row < labsize &&
           col >= 0 &&
           col < labsize &&
           lab[row][col] == 0;
}

void visit (int row, int col)
{
    lab[row][col] = 9;
}

int currentWay[100][2] = {0};
int currentPathLength = 0;

bool way (int r, int c, int targetr, int targetc)
{
    if (r == targetr && c == targetc)
    {
        return true;
    }
    if (!canStepOn (r,c))
    {
        return false;
    }

    currentWay[currentPathLength][0] = r;
    currentWay[currentPathLength][1] = c;
    ++currentPathLength;

    visit (r,c);

    bool success =  way (r+1,c,targetr, targetc) ||
                    way (r,c+1,targetr, targetc) ||
                    way (r-1,c,targetr, targetc) ||
                    way (r,c-1,targetr, targetc);

    /*
        ВРЪЩАНЕ НАЗАД
    */
    if (!success)
    {
        --currentPathLength;    
        lab[r][c] = 0;
    }
    
    return success;
    
}

void traceback (int r, int c)
{

    cout << "(" << r << "," << c << ")";
    if (r == 0 && c == 0)
    {
        return;
    }
    lab[r][c] = 0;
    if (r > 0 && lab[r-1][c] == 9)
    {
        traceback (r-1,c);
    } else if (r < labsize-1 && lab[r+1][c] == 9){
        traceback (r+1,c);
    } else if (c > 0 && lab[r][c-1] == 9)
    {
        traceback (r,c-1);
    } else if (c < labsize-1 && lab[r][c+1])
    {
        traceback (r,c+1);
    }
}

void printLab ()
{
    
    cout << "=========================\n";
    for (int r = 0; r < labsize; r++)
    {
        for (int c = 0; c < labsize; c++)
        {
            cout << lab[r][c] << "  ";
        }
        cout << endl;
    }
    cout << "=========================\n";
}

void printWay ()
{
    for (int step = 0; step < currentPathLength; ++step)
    {
        cout << "(" 
             << currentWay[step][0] 
             << ","
             << currentWay[step][1]
             << ")"
             <<  endl; 
    }
}

int main ()
{
    printLab ();
    way (0,0,7,7);
    printLab ();
    printWay ();
    traceback(7,7);
}