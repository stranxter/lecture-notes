#include <iostream>
#include <iomanip>

using namespace std;

//3x3

void printMatrix (double toPrint[3][3])
{
	for (int row = 0; row < 3; row++)
	{
		//Това печата един ред:----------
		for (int col = 0; col < 3; col++)
		{
			cout << setw(8) << toPrint[row][col];
		}
		//-------------------------------
		cout << endl;
	}
}

bool member (double x, double A[3][3])
{

//	for (int row = 0; row < 3; row++)
//	{
//		//-------------------------------
//		for (int col = 0; col < 3; col++)
//		{
//			//(row,col) "пробягва" (0,0) (0,1) (0,2) (1,0) (1,1).. (2,2)
//			if (x == A[row][col])
//			{
//				return true;
//			}
//
//		}
//		//-------------------------------
//	}

	//---- ако стигнем до тук, значи
	//---- х не е елемент на матрицата


    for (int counter = 0; counter < 9; counter++)
    	if (x == A[counter / 3][counter % 3]) //A[0][counter]
    		return true;

	return false;
}

int main ()
{
	double doubleA[3][3]={1,0,0,
					      0,1,0,
					      0,0,1};

	double doubleB[3][3]={3431,0,0,
					      2220,1,3430,
					      6760,0,1};


	double doubleC[3][3]={0};

	for (int row = 0; row < 3; row++)
	{
		//-------------------------------
		for (int col = 0; col < 3; col++)
		{
			//(row,col) "пробягва" (0,0) (0,1) (0,2) (1,0) (1,1).. (2,2)

			doubleC[row][col] = doubleA[row][col] + doubleB[row][col];

		}
		//-------------------------------
		cout << endl;
	}

	printMatrix (doubleC);

	cout << member (1,doubleA) << endl; //true 
	cout << member (2,doubleA) << endl; //false


	for (int row = 0; row < 3; row++)
	{
		//-------------------------------
		for (int col = 0; col < 3; col++)
		{
			//(row,col) "пробягва" (0,0) (0,1) (0,2) (1,0) (1,1).. (2,2)

			//doubleC[row][col] = ROW-тия ред на A умножено по COL-тата колона на B
			//doubleC[row][col] = doubleA[row][0]*doubleB[0][col] + 
								//doubleA[row][1]*doubleB[1][col] + 
								//doubleA[row][2]*doubleB[2][col];

			//НАМИРАНЕ НА ЕЛЕМЕНТА (ROW,COL)
			doubleC[row][col] = 0;
			for (int k = 0; k < 3; k++)
				doubleC[row][col] += doubleA[row][k]*doubleB[k][col];

		}
		//-------------------------------
		cout << endl;
	}

	printMatrix (doubleC);

	int arr[] = {1,2,3,4,2,6,7,8,2,10};


	for (int i = 0; i < 10; i ++)
	{
		for (int j = 0; j < 10; j ++)
			if (i != j && arr[j] == arr[i])
			{
				cout << "FOUND!!!" << arr[j]<< endl;
			}
	}

	int a[3][3]

	f((int*)a)

}

void f (int a[9])


