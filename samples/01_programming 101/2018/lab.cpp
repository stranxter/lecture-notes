#include <iostream>

const size_t labsize = 8;
int lab[][labsize] = {0, 1, 0, 0, 0, 0, 0, 0,
                      0, 1, 0, 0, 0, 0, 0, 0,
                      0, 1, 0, 0, 0, 0, 0, 0,
                      0, 1, 1, 1, 0, 0, 0, 0,
                      0, 0, 0, 0, 0, 0, 0, 0,
                      0, 1, 1, 1, 0, 0, 0, 0,
                      0, 1, 0, 0, 0, 0, 0, 0,
                      0, 1, 0, 0, 0, 0, 0, 0};
//lab
/*
int currentPath[labsize*labsize][2] = {0};
size_t currentPathElement = 0;
*/

void makeStep (int x, int y)
{
  lab[y][x] = 9;
/*  currentPath[currentPathElement][0] = x;
  currentPath[currentPathElement][1] = y;
  currentPathElement++;
*/
}

void unMakeStep (int x, int y)
{
//  currentPathElement--;
  lab[y][x] = 8;
}

bool hasWay (int startx, int starty, int endx, int endy)
{
  if (startx == endx && starty == endy)
  {
    makeStep (endx,endy);
    return true;
  }
  if (startx < 0 || startx >= labsize ||
      starty < 0 || starty >= labsize ||
      lab[starty][startx] != 0)
  {
      return false;
  }

  makeStep (startx,starty);

  bool success = hasWay(startx,starty+1,endx,endy) ||
                 hasWay(startx+1,starty,endx,endy) ||
                 hasWay(startx,starty-1,endx,endy) ||
                 hasWay(startx-1,starty,endx,endy);

  if (!success)
  {
    unMakeStep(startx,starty);
  } else {
    std::cout << "[" << startx << "," << starty << "]";
  }

  return success;
}


/*
  -1: няма път
  >=0 : дължина на намерения път
*/
int lengthWay (int startx, int starty, int endx, int endy)
{
  if (startx == endx && starty == endy)
  {
    makeStep (endx,endy);
    return 0;
  }
  if (startx < 0 || startx >= labsize ||
      starty < 0 || starty >= labsize ||
      lab[starty][startx] != 0)
  {
      return -1;
  }

  makeStep (startx,starty);

  int foundMinWay = -1, subWayLength = -1;

  foundMinWay = lengthWay(startx,starty+1,endx,endy);
  subWayLength = lengthWay(startx+1,starty,endx,endy);
  if (subWayLength >= 0 && subWayLength < foundMinWay || foundMinWay == -1)
  {
    foundMinWay = subWayLength;
  }
  subWayLength = lengthWay(startx,starty-1,endx,endy);
  if (subWayLength >= 0 && subWayLength < foundMinWay || foundMinWay == -1)
  {
    foundMinWay = subWayLength;
  }
  subWayLength = lengthWay(startx-1,starty,endx,endy);
  if (subWayLength >= 0 && subWayLength < foundMinWay || foundMinWay == -1)
  {
    foundMinWay = subWayLength;
  }

  unMakeStep(startx,starty);
  lab[starty][startx] = 0;

  if (foundMinWay >= 0)
    return foundMinWay+1;
  return -1;
}


void printLab ()
{
  for (size_t y = 0; y < labsize; y++)
  {
    for (size_t x = 0; x < labsize; x++)
    {
      std::cout << " ";
      switch (lab[y][x])
      {
        case 0: std::cout << " "; break;
        case 1: std::cout << "*"; break;
        case 8: std::cout << "_"; break;
        case 9: std::cout << "."; break;
      }
      std::cout << " ";
    }
    std::cout << std::endl;
  }
}

/*
void printPath ()
{
  for (size_t n = 0; n < currentPathElement; n++)
  {
    std::cout << "("
              << currentPath[n][0]
              << ","
              << currentPath[n][1]
              << ") ";
    }
  std::cout << std::endl;
}
*/
int main ()
{
  //std::cout << hasWay (0,0,2,0) << std::endl;
  std::cout << lengthWay (0,0,2,0) << std::endl;
  printLab ();
//  printPath ();
}
