#include <iostream>
#include "dynarray.hpp"

using namespace std;

template <typename T>
T plusOne (T x)
{
	return x+1;
}

int sum (int curResult, int crrElem)
{
	return curResult + crrElem;
}

int main ()
{




	DynArr<int> a(2),b(2);

	//cin >> a[2];
	//cout << a[2] << endl;

	a[0] = 1;
	a[1] = 7;
	a[2] = 10;
	a[3] = 100;
	b[0] = b[1] = 1;


	cout << "sum=" << a.reduce (sum,0) << "\n";
	cout << "sum=" << a.reduce<int> ([](int x, int y){return x+ y;},0) << "\n";

	cout << a;

	cout << a+b << endl;

	DynArr<char> s(3);

	s[0]= 'h'; s[1] = 'i'; s[2] = '!';

	cout << s << endl;


	b.map (plusOne);

	cout << b; //{2,2}


	//hi -> ij

	s.map(plusOne);
	cout << s << endl;
	
	DynArr<bool> ba(2);

	ba[0] = ba[1] = 7;

	cout << ba << endl;


    DynArr<int> result(0); char c; int x;
    cin >> c; assert (c == '[');

    while (c != ']' && cin.peek() != ']')
    {
    	cin >> x;
    	result += x;
    	cin >> c;
    	assert(c == ',' || c == ']');
    }

    cout << "result = " << result << endl;


/*	b[2] = 17;

	b = a+b; //a.operator+(b.operaot+(c.operao...))

	cout << b[7] << endl;
*/
}