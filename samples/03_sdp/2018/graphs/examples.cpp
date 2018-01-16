#include <iostream>
#include <cstring>


char G[3][3] =
              { 'a', 'b', 'c',
                'a', 'e', 'f',
                0,   'g', 'h'
              };


bool hasPathFrom (uint state, const char* path)
{
  if (strlen(path) == 0)
  {
    return true;
  }

  for (int nextState = 0; nextState < 3; nextState++)
  {
    if (G[state][nextState] == path[0])
    {
      if (hasPathFrom(nextState,path+1))
        return true;
    }
  }

  return false;
}


bool hasPath (const char *path)
{
  for (int i = 0; i < 3; i++)
  {
    if (hasPathFrom (i,path))
    {
      return true;
    }
  }
  return false;
}

int main ()
{
  std::cout << "abz=" << hasPath ("abz") << std::endl;
  std::cout << "aaaab=" << hasPath ("aaaaab") << std::endl;
  std::cout << "bfh=" << hasPath ("bfh") << std::endl;
  std::cout << "abfge=" << hasPath ("abfge") << std::endl;
  std::cout << "gfgfgd=" << hasPath ("gfgfgd") << std::endl;
  std::cout << "gfgfg=" << hasPath ("gfgfg") << std::endl;
}
