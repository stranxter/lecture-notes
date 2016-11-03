#include <iostream>
#include <assert.h>
#include <string.h>
#include <fstream>


using namespace std;

template <class T>
using mapFn = T (*)(const T&);

template <class T>
struct Node
{
	Node<T> *left, *right;
	T data;

	Node (const T& d,Node<T> *l, Node<T> *r):
	    left(l),right(r),data(d)
    {
    	makeID();
    }
	Node ():left(NULL),right(NULL)
	{
		makeID();
	}

	int getID() const
	{
		return id;
	}

private:
	int id;

	void makeID ()
	{
		static int maxID = 0;
		maxID++;
    	id = maxID;

	}

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

	void dottyPrint (Node<T> *subTreeRoot,ostream& out) const;

	void serialize (Node<T>*, ostream&) const;
	Node<T>* parseTree (istream &in);


	static Node<T>* copyTree (const Node<T> *subTreeRoot);

	void insertBOT (Node<T>*&subTreeRoot,const T& x);

	Node<T>* insertedBOT (Node<T>*subTreeRoot, const T& x);

	void deleteElement (Node<T> *&subTreeRoot, const T&x);

	T minelement (Node<T> *subTreeRoot) const;

public:
	BTree();
	BTree (const BTree<T> &other);

	BTree<T>& operator = (const BTree<T> &other);

	BTree<T>& add (const T& data, const char *trace);

	void deleteElement (const T&x);

	void deserialize (istream&);

	void simplePrint () const;
	void dottyPrint (ostream&);
	//bool isEmpty();
	bool member (const T&) const;

	void map (mapFn<T>);

	void serialize (ostream&)const;

	BTree<T>& insertBOT (const T& x);

	BTree<T> insertedBOT (const T& x);

	T minelement ()const;

	~BTree();

};

template<class T>
void BTree<T>::deleteElement (Node<T> *&subTreeRoot, const T&x)
{
	//триене от празно дърво
	if (subTreeRoot==NULL)
		return;

	//триене от листо
	if (subTreeRoot->data == x &&
		subTreeRoot->left == NULL &&
		subTreeRoot->right == NULL)

	{
		delete subTreeRoot;
		subTreeRoot = NULL;	
		return;
	}

	//триене от лявото поддърво
	if (x < subTreeRoot->data)
	{
		deleteElement (subTreeRoot->left,x);
		return;
	}

	//триене от дясното поддърво
	if (x > subTreeRoot->data)
	{
		deleteElement (subTreeRoot->right,x);
		return;
	}

	//вече сме сигурни, че трием корена!
	//освен това сме сигурни, че корена има ПОНЕ ЕДИН
	//наследник

	//триене на корен само с 1 наследник
	if (subTreeRoot->right == NULL)
	{
		Node<T> *tmp = subTreeRoot;
		subTreeRoot = subTreeRoot->left;
		delete tmp;
		return;
	}

	//триене на корен само с 1 наследник
	//този случй може да не се разглежда
	if (subTreeRoot->left == NULL)
	{
		Node<T> *tmp = subTreeRoot;
		subTreeRoot = subTreeRoot->right;
		delete tmp;
		return;
	}


	//триене на корена
	//вече сме сигурни, че корена има точно два наследника
	T minel = minelement(subTreeRoot->right);
	subTreeRoot->data = minel;
	deleteElement (subTreeRoot->right, minel);


}

template<class T>
void BTree<T>::deleteElement (const T&x)
{
	deleteElement (root,x);
}

template<class T>
T BTree<T>::minelement (Node<T> *subTreeRoot) const
{
	assert (subTreeRoot != NULL);
	Node<T> *current = subTreeRoot;

	while (current->left != NULL)
	{
		current = current->left;
	}

	return current->data;

}


template<class T>
T BTree<T>::minelement () const
{
	return minelement (root);

}

template<class T>
BTree<T> BTree<T>::insertedBOT (const T& x)
{
	BTree<T> result;
	result.root = insertedBOT (root,x);

	return result;
}


template<class T>
Node<T>* BTree<T>::insertedBOT (Node<T>*subTreeRoot, const T& x)
{
	if (subTreeRoot == NULL)
	{
		return new Node<T> (x,NULL,NULL);
	}

	if (x > subTreeRoot->data)
	{
		return new Node<T> (subTreeRoot->data,
							copyTree(subTreeRoot->left),
							insertedBOT(subTreeRoot->right,x));
			                
	}

	return new Node<T> (subTreeRoot->data,
						insertedBOT(subTreeRoot->left,x),
						copyTree(subTreeRoot->right));

}


template<class T>
void BTree<T>::insertBOT (Node<T>* &subTreeRoot,const T& x)
{

	if (subTreeRoot == NULL)
	{
		subTreeRoot = new Node<T> (x,NULL,NULL);
		return;
	}

	if (x <= subTreeRoot->data)
	{
		insertBOT (subTreeRoot->left,x);
	} else {
		insertBOT (subTreeRoot->right,x);
	}

}


template<class T>
BTree<T>& BTree<T>::insertBOT (const T& x)
{
	insertBOT (root,x);	
	return *this;
}

template<class T>
BTree<T>& BTree<T>::operator = (const BTree<T> &other)
{
	if (this == &other)
		return *this;

	deleteAll (root);
	root = copyTree (other.root);

	return *this;
}


template<class T>
Node<T>* BTree<T>::copyTree (const Node<T> *subTreeRoot)
{
	if (subTreeRoot == NULL)
		return NULL;

	return new Node<T> (subTreeRoot->data,
		                copyTree(subTreeRoot->left),
		                copyTree(subTreeRoot->right));
}

template<class T>
BTree<T>::BTree (const BTree<T> &other)
{
	root = copyTree (other.root);
}


template<class T>
void BTree<T>::serialize (Node<T> *subTreeRoot, ostream &out) const
{
	if (subTreeRoot == NULL)
	{
		out << "null ";
		return;
	}

	out << subTreeRoot->data << " ";

	serialize (subTreeRoot->left,out);
	serialize (subTreeRoot->right,out);

}

template<class T>
void BTree<T>::serialize (ostream &out) const
{
	serialize (root,out);
	cout << endl;
}



template<class T>
void BTree<T>::dottyPrint (ostream &out)
{
	dottyPrint (root,out);
}



template<class T>
void BTree<T>::dottyPrint (Node<T> *subTreeRoot,ostream& out) const
{
	if (subTreeRoot == NULL)
		return;

	out << subTreeRoot->getID() 
	    << "[label=\"" 
	    << subTreeRoot->data 
	    << "\"];" << endl;

	if (subTreeRoot->left != NULL)
		out << subTreeRoot->getID() 
	        <<"->"
	        << subTreeRoot->left->getID()
	        << endl;

	if (subTreeRoot->right != NULL)
		out << subTreeRoot->getID() 
	        <<"->"
	        << subTreeRoot->right->getID()
	        << endl;

	dottyPrint (subTreeRoot->left,out);
	dottyPrint (subTreeRoot->right,out);
}



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
	root = NULL;

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

	simplePrint (subTreeRoot->left);
	cout << subTreeRoot->data << " ";
	simplePrint (subTreeRoot->right);
}

void removeWhite (istream &in)
{
	while (in.peek() <= 32)
		in.get();
}

template <class T>
Node<T>* BTree<T>::parseTree (istream &in)
{
	
	removeWhite (in);

	if (in.peek() == 'n')
	{
		string dummy;
		in >> dummy;
		assert (dummy == "null");
		return NULL;
	}

	T data;
	in >> data;

	return new Node<T> (data,
		 				parseTree(in),
		 				parseTree(in));


}


template <class T>
void BTree<T>::deserialize (istream &in)
{
	deleteAll(root);

	root = parseTree (in);


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

void testAssignment()
{
	BTree<int> t;

	t.add(10,"").add(12,"L").add(14,"R").add(15,"LR");
	t.simplePrint();

	BTree<int> t1 = t;

	t1.map (plusOne);

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

int main ()
{
	
	testMember ();
	testAssignment();
	testMinEl();

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

	BTree<int> t1 = t;
	t1.deleteElement (56);

	t1.dottyPrint(cerr);

	cerr << "}";

	t1.simplePrint ();

	return 0;
}
