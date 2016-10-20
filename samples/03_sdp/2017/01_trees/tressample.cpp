#include <iostream>
#include <assert.h>
#include <string.h>


using namespace std;

template <class T>
using mapFn = T (*)(const T&);

template <class T>
struct Node
{
	Node<T> *left, *right;
	T data;

	Node (const T& d,Node<T> *l, Node<T> *r):left(l),right(r),data(d){}
	Node ():left(NULL),right(NULL){}
};

template <class T>
class BTree
{
private:
	Node<T> *root;
	void simplePrint (Node<T> *subTreeRoot) const;
	bool add (const T& data, const char *trace, Node<T>*&);
	void deleteAll (Node<T> *subTreeRoot);
	bool member (const T&,Node<T> *subTreeRoot) const;
	void map (mapFn<T>,Node<T> *subTreeRoot);

public:
	BTree();
	BTree<T>& add (const T& data, const char *trace);
	void simplePrint () const;
	//void dottyPrint (ostream&);
	//bool isEmpty();
	bool member (const T&) const;

	void map (mapFn<T>);

	~BTree();

};


template<class T>
void BTree<T>::map (mapFn<T> f,Node<T> *subTreeRoot)
{
	if (subTreeRoot == NULL)
		return;

	subTreeRoot->data = f (subTreeRoot->data);
	map (f,subTreeRoot->left);
	map (f,subTreeRoot->right);
}

template<class T>
void BTree<T>::map (mapFn<T>f)
{
	map (f,root);
}


template<class T>
bool BTree<T>::member (const T& x) const
{
	return member (x,root);
}


template<class T>
bool BTree<T>::member (const T& x,Node<T> *subTreeRoot) const
{
	if (subTreeRoot == NULL)
		return false;


	return subTreeRoot->data == x ||
	       member (x,subTreeRoot->left) ||
	       member (x,subTreeRoot->right);


}


template<class T>
void BTree<T>::deleteAll (Node<T> *subTreeRoot)
{
	if (subTreeRoot == NULL)
		return;

	deleteAll (subTreeRoot->left);
	deleteAll (subTreeRoot->right);
	delete subTreeRoot;
}

template <class T>
BTree<T>::~BTree()
{
	deleteAll (root);

}


template <class T>
BTree<T>& BTree<T>::add(const T& x, const char *trace)
{
   add (x,trace,root);
   return *this;
}


template <class T>
bool BTree<T>::add(const T& x, const char *trace, Node<T>* &subTreeRoot)
{
	if (subTreeRoot == NULL)
	{
		assert (strlen(trace) == 0);
		subTreeRoot = new Node<T> (x,NULL,NULL);
		return true;
	}

	assert (strlen(trace)>0);

	if (trace[0]=='L')
		return add (x,trace+1,subTreeRoot->left);

	assert (trace[0]=='R');
	return add (x,trace+1,subTreeRoot->right);

	return true;

}

template <class T>
BTree<T>::BTree ():root(NULL){}

template <class T>
void BTree<T>::simplePrint() const
{
	simplePrint (root);
	cout << endl;
}

template <class T>
void BTree<T>::simplePrint(Node<T> *subTreeRoot) const
{
	if (subTreeRoot == NULL)
		return;

	cout << subTreeRoot->data << " ";
	simplePrint (subTreeRoot->left);
	simplePrint (subTreeRoot->right);
}

void testMember ()
{
	BTree<int> t;

	t.add(10,"").add(12,"L").add(14,"R").add(15,"LR");	

	assert (t.member(12) == true);
	assert (t.member(18) == false);
	assert (t.member(15) == true);
}


int plusOne (const int& i)
{
	return i + 1;
}

int main ()
{
	
	testMember ();

	BTree<int> t;

	t.add(10,"").add(12,"L").add(14,"R").add(15,"LR");
	t.simplePrint();

	t.map (plusOne);

	t.simplePrint ();


	return 0;
}