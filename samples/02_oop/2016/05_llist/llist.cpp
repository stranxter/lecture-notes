#include <iostream>
#include <assert.h>

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
	box<T> *last;
public:
	List ()
	{
		first = NULL;
		last = NULL;
	}

	List (const List<T>& other)
	{
		box<T> *crr = other.first;

		if (other.first == NULL)
		{
			last = first = NULL;
			return;

		}

		first = new box<T> (crr->data,NULL);
		last = first;
		crr = crr->next;

		while (crr != NULL)
		{

			last->next = new box<T> (crr->data,NULL);
			last = last->next;

			crr = crr->next;
			
		}

	}

	List<T>& push (const T &newElemValue)
	{
		first = new box<T> (newElemValue,first);
		if (last == NULL)
			last = first;
		assert (first != NULL);
		return *this;
	}

	List<T>& push_back (const T &newElemValue)
	{

		box<T> *crr = first;

		if (crr == NULL)
			return push (newElemValue);


		last->next = new box<T>(newElemValue,NULL);
		last = last->next;

		return *this;
	}

	T operator [] (int i) const
	{
		assert (i >= 0);

		box<T> *crr = first;

		while (crr != NULL && i > 0)
		{			
			crr = crr->next;			
			i--;
		}	

		assert (crr != NULL);
		return crr->data;

	}

	T& operator [] (int i)
	{

		assert (i >= 0);

		box<T> *crr = first;

		while (crr != NULL && i > 0)
		{			
			crr = crr->next;			
			i--;
		}	

		assert (crr != NULL);
		return crr->data;
		
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


int main ()
{



	List<char> l;

	l.push ('!').push('i').push('h');

	cout << l << endl;

	l[0] = 'b';
	l[2] = '?'; 

	l.push_back ('!');
	l.push_back ('?');

	cout << l << endl;


	return 0;
}