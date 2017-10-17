#include <iostream>
#include <stack>

const int mazeSize = 10;
const int accessble = 0;
const int visited = 8;
const int goal = 9;

int maze[mazeSize][mazeSize] =
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
     0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
     0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
     0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
     0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
     1, 0, 1, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 1, 0, 0, 0, 0, 0, 0, 9};

bool correct (int x, int y)
{
  return x >= 0 &&
         y >= 0 &&
         x < mazeSize &&
         y < mazeSize;
}

bool way (int x, int y)
{
  if (!correct(x,y))
    return false;
  if (maze[x][y] == goal)
  {
    return true;
  }
  if (maze[x][y] != accessble)
    return false;

  maze[x][y] = visited;

  if (way (x,y+1))
    return true;
  if (way (x+1,y))
    return true;
  if (way (x,y-1))
    return true;
  if (way (x-1,y))
    return true;

  return false;

}

bool isgoal (std::pair<int,int> &p)
{
  return correct (p.first,p.second) &&
         maze[p.first][p.second] == goal;
}

std::ostream& operator << (std::ostream &out, std::stack<std::pair<int,int>> s)
{
  out << s.size() << " elements." << std::endl;
  while (!s.empty())
  {
    out << "("
        << s.top().first
        << ","
        << s.top().second
        << ")"
        << std::endl;

    s.pop();
  }

  return out;
}

bool wayIter (int x, int y)
{
  std::stack<std::pair<int,int>> s;

  s.push (std::pair<int,int>(x,y));

  while (!s.empty() && !isgoal (s.top()))
  {
    std::cout << s;
    std::cin.get();

    std::pair<int,int> crrState = s.top();
    s.pop();

    if (correct (crrState.first, crrState.second) &&
        maze[crrState.first][crrState.second] == accessble)
    {
      maze[crrState.first][crrState.second] = visited;
      s.push (std::pair<int,int>(crrState.first-1,crrState.second));
      s.push (std::pair<int,int>(crrState.first,crrState.second-1));
      s.push (std::pair<int,int>(crrState.first+1,crrState.second));
      s.push (std::pair<int,int>(crrState.first,crrState.second+1));
    }
  }

  return !s.empty();
}


class Mario
{
private:
  std::stack<std::pair<int,int>> s;
public:
  Mario (int,int);
  bool canTakeMoreSteps();
  void makeStep();
  std::pair<int,int> getCurrentPos();
  bool goalReached();
};

bool Mario::goalReached()
{
  return !s.empty () &&
         maze[getCurrentPos().first][getCurrentPos().second] == goal;
}


std::pair<int,int> Mario::getCurrentPos()
{
  return s.top();
}


Mario::Mario (int x, int y)
{
  s.push (std::pair<int,int>(x,y));
}

bool Mario::canTakeMoreSteps ()
{
  return !s.empty() && !isgoal (s.top());
}
void Mario::makeStep ()
{

  std::pair<int,int> crrState = s.top();
  s.pop();

  if (correct (crrState.first, crrState.second) &&
      maze[crrState.first][crrState.second] == accessble)
  {
    maze[crrState.first][crrState.second] = visited;
    s.push (std::pair<int,int >(crrState.first-1,crrState.second));
    s.push (std::pair<int,int>(crrState.first,crrState.second-1));
    s.push (std::pair<int,int>(crrState.first+1,crrState.second));
    s.push (std::pair<int,int>(crrState.first,crrState.second+1));
  }
}


int main ()
{

  //std::cout << "way=" << wayIter (0,0) << std::endl;


  Mario m (0,0);

  while (m.canTakeMoreSteps() && !m.goalReached())
  {
    std::cout << "Mario is currently at position ("
              << m.getCurrentPos().first
              << ","
              << m.getCurrentPos().second
              << ")"
              << std::endl;
    m.makeStep();
  }

  std::cout << "Goal reached: " << (m.goalReached()?"Yes":"No") << std::endl;

}
