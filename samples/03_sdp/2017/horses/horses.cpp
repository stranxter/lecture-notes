#include <iostream>
#include <stack>

using namespace std;

#define MAX_SIZE 8

bool board[MAX_SIZE][MAX_SIZE] = {false};

void printBoard (int size)
{
	cout << "+++++++++++++++++++\n";
	for (int r = 0; r < size; r++)
	{
		for (int c = 0; c < size; c++)
		{
			if (board[r][c])
				cout << "H ";
			else
				cout << "_ ";	

		}
		cout << endl;
	}
	cout << "+++++++++++++++++++\n";
}

bool hasHorse (int r, int c, int size)
{
	return r >= 0 && 
	       c >= 0 && 
	       r < size && 
	       c < size &&
	       board[r][c];
}

bool canPlaceHorse (int r, int c, int size)
{
	return !hasHorse(r-2,c-1,size) &&
	       !hasHorse(r-2,c+1,size) &&
	       !hasHorse(r-1,c-2,size) &&
	       !hasHorse(r-1,c+2,size) &&
	       !hasHorse(r+1,c-2,size) &&
	       !hasHorse(r+1,c+2,size) &&
	       !hasHorse(r+2,c-1,size) &&
	       !hasHorse(r+2,c+1,size) &&
	       !hasHorse (r,c,size);
}

#define OPER_PLACE_HORSE 0
#define OPER_REMOVE_HORSE 1
#define OPER_FIND_SOLUTION 2

struct Operation
{
	int operType;
	int k;
	int size;
	int r;
	int c;
	Operation (int _t, int _k, int _s):operType(_t), k(_k),size(_s){}
	Operation (int _t, int _k, int _s,int _r, int _c)
	    :operType(_t),k(_k),size(_s),r(_r),c(_c){}
	//Operation (){}
};

void configStack (int k, int size)
{
	stack<Operation> operations;

	operations.push(Operation(OPER_FIND_SOLUTION,k,size));

	while (!operations.empty())
	{
		Operation topOperation = operations.top();
		int k = topOperation.k;
		int size = topOperation.size;
		operations.pop();

		if (k==0)
		{
			printBoard (size);
		}else if (topOperation.operType == OPER_PLACE_HORSE)
		{
			board[topOperation.r][topOperation.c]=true;
		}else if (topOperation.operType == OPER_REMOVE_HORSE)
		{
			board[topOperation.r][topOperation.c]=false;
		}else
		{
			for (int r = 0; r < size; r++)
			{
				for (int c = 0; c < size; c++)
				{
					if (canPlaceHorse (r,c,size))
					{
						operations.push (Operation(OPER_REMOVE_HORSE,1,size,r,c));
						operations.push (Operation(OPER_FIND_SOLUTION,k-1,size));
						operations.push (Operation(OPER_PLACE_HORSE,1,size,r,c));
					}
				}
			}			

		}



	}
}

void config (int k, int size)
{
	if (k == 0)
	{
		printBoard(size);
		return;
	}

	for (int r = 0; r < size; r++)
	{
		for (int c = 0; c < size; c++)
		{
			if (canPlaceHorse (r,c,size))
			{
				board[r][c] = true;
				config (k-1,size);
				board[r][c] = false;
			}
		}
	}

}

int main ()
{

	configStack (4,4);

}