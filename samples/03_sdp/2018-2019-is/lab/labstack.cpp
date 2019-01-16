#include <iostream>
#include <stack>
#include <vector>

const size_t labsize = 8;

int lab[labsize][labsize] = {0, 1, 0, 0, 0, 0, 0, 0,
                             0, 1, 0, 1, 0, 0, 0, 0,
                             0, 1, 0, 1, 0, 0, 0, 0,
                             0, 0, 0, 1, 0, 0, 0, 0,
                             0, 1, 1, 1, 0, 0, 0, 0,
                             0, 1, 0, 0, 0, 0, 0, 0,
                             0, 1, 0, 0, 0, 0, 0, 0,
                             0, 1, 0, 0, 0, 0, 0, 0};

bool canStepOn (int cx, int cy)
{
  return cx >= 0 &&
         cx < labsize &&
        cy >= 0 &&
        cy < labsize &&
        lab[cx][cy] == 0;
}

bool hasway (int cx, int cy, std::vector<std::pair<int,int>>& currentPath)
{
  if (cx == labsize-1 && cy == labsize-1)
  {
    for (std::pair<int,int> &p : currentPath)
    {
      std::cout << "(" << p.first << "," << p.second << ")->";
    }
    std::cout << std::endl;
    return true;
  }
  if (!canStepOn(cx,cy))
  {
    return false;
  }
  lab[cx][cy] = 2;
  currentPath.push_back (std::pair<int,int>(cx,cy));
  bool foundWay = hasway (cx,cy-1,currentPath) ||
                  hasway (cx+1,cy,currentPath) ||
                  hasway (cx,cy+1,currentPath) ||
                  hasway (cx-1,cy,currentPath);
  currentPath.pop_back();
  lab[cx][cy] = 0;
  return foundWay;
}

struct StackNode
{
  int cx, cy;
  StackNode (int _cx, int _cy):cx (_cx), cy(_cy){}
};

bool haswayiter (int cx, int cy)
{
  std::stack<StackNode> s;

  s.push (StackNode(0,0));

  //s.empty () || (s.top().cx == labsize-1 && s.top().cy == labsize-1)
  while (!s.empty() &&
         (s.top().cx != labsize-1 || s.top().cy != labsize-1))
  {
    StackNode top = s.top(); s.pop();
    if (canStepOn (top.cx, top.cy))
    {
      s.push (StackNode(top.cx,top.cy-1));
      s.push (StackNode(top.cx+1,top.cy));
      s.push (StackNode(top.cx,top.cy+1));
      s.push (StackNode(top.cx-1,top.cy));
      lab[top.cx][top.cy] = 2;
    }
  }
  return !s.empty();
}

int main ()
{
  std::vector<std::pair<int,int>> p;
  std::cout << "way=" << hasway (0,0,p) << std::endl;
  //std::cout << "way=" << haswayiter (0,0) << std::endl;
}
