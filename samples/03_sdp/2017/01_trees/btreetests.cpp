#include <iostream>
#include <assert.h>
#include <stack>
#include <iomanip>

#include "btree.cpp"

template <class T>
using mapFn = T (*)(const T&);

template <class T>
void simplePrint (BTree<T> &t)
{
	cout << "{";
	for (T& x : t)
		cout << x << " ";
	cout << "}\n";
}

void testMember ()
{
	BTree<int> t;

	t.add(10,"").add(12,"L").add(14,"R").add(15,"LR");	

	assert (t.member(12) == true);
	assert (t.member(18) == false);
	assert (t.member(15) == true);
}


void testAssignment()
{
	BTree<int> t;

	t.add(10,"").add(12,"L").add(14,"R").add(15,"LR");
	simplePrint(t);

	BTree<int> t1;

	t1 = t;

	assert (t1.member(10) && 
		    t1.member (12) && 
		    t1.member (14) && 
		    t1.member (15));


}
void testMinEl ()
{
	BTree<int> t;

	t.insertBOT(59)
	 .insertBOT(23)
	 .insertBOT(68)
	 .insertBOT(190)
	 .insertBOT(41)
	 .insertBOT(67);

	 assert (t.minelement() == 23);
}


void testIterator ()
{
	BTree<int> t;

	t.insertBOT(59)
	 .insertBOT(23)
	 .insertBOT(68)
	 .insertBOT(190)
	 .insertBOT(41)
	 .insertBOT(67);

	 	
	 BTree<int>::LeftRootRightIterator it = t.begin();

	 assert (*it == 23);

	 ++it; 
	 ++it;
	 assert (*it == 59);;

	 int count = 0;
	 for (it = t.begin(); it != t.end(); ++it)
	 {
	 	count++;
	 }


	 assert (count == 6);

}


template <class T>
void prettyPrint (typename BTree<T>::HierarchicalIterator it,int depth=0)
{
	if (it.empty())
		return;

	prettyPrint<T> (it.goLeft(), depth + 1);

	cout << setw (depth*4) << " " << *it << endl;

	prettyPrint<T> (it.goRight(), depth + 1);
}

void testMakeTree ()
{
	BTree<int> t;
	typename BTree<int>::HierarchicalIterator it = t.rootIter();

	*it = 10;
	*it.goLeft() = 12;
	*it.goRight() = 14;

	prettyPrint<int> (it);

}



int main ()
{
	
	testMember ();
	testAssignment();
	testMinEl();
	testIterator();

	BTree<int> t;

	t.insertBOT(56)
	 .insertBOT(23)
	 .insertBOT(68)
	 .insertBOT(190)
	 .insertBOT(41)
	 .insertBOT(60)
	 .insertBOT(65)
	 .insertBOT(59);


	cerr << "digraph G{" << endl;
	t.dottyPrint (cerr);
	cerr << "}\n";

	prettyPrint<int> (t.rootIter());

	testMakeTree();


	return 0;
}