#include <iostream>

using namespace std;

template <typename T>
struct box
{
	T data;
	box<T> *next;
	box (const T& d, box<T> *n):data(d),next(n){}
};


template <typename T>
class List
{
private:
	box<T> *first;
public:
	List ()
	{
		first = NULL;
	}

	List (const List<T>& other)
	{
		box<T> *crr = other.first, *previous;

		if (other.first == NULL)
		{
			first = NULL;
			return;

		}

		first = new box<T> (crr->data,NULL);
		previous = first;
		crr = crr->next;

		while (crr != NULL)
		{

			previous->next = new box<T> (crr->data,NULL);
			previous = previous->next;

			crr = crr->next;
			
		}	
	}

	List<T>& push (const T &newElemValue)
	{
		first = new box<T> (newElemValue,first);
		return *this;
	}

	~List()
	{
		box<T> *crr = first, *save;

		while (crr != NULL)
		{
			
			save = crr;
			//cout << "deleting el: "<< save->data << " ";
			crr = crr->next;
			
			delete save;
		}		
	}

	template <class U>
	friend ostream& operator << (ostream& out, const List<U> &l);
};


template <class U>
ostream& operator << (ostream& out, const List<U> &l)
{
	box<U> *crr = l.first;

	while (crr != NULL)
	{
		out << crr->data << " ";
		crr = crr->next;
	}

	return out;

}


void f (List<char> li)
{
	cout << li << endl;
}

int main ()
{

	List<char> l;

	l.push ('!').push('i').push('h');

	f(l);

	cout << l << endl;

	return 0;
}