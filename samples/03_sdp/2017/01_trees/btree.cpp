#include <iostream>
#include <assert.h>
#include <stack>

using namespace std;


template <class T>
class BTree
{

private:

	//Възел на дървото
	struct Node
	{
		Node *left, *right;
		T data;
		Node (const T& d,Node *l, Node *r);
		Node ();
		int getID() const;
	private:
		//Уникален пореден номер на всеки
		//конструиран възел
		int id;
		void makeID ();
	};

	//при обхождането на дървото със стек,
	//в стека се поставят два вида "чакащи операции":
	//"извеждане" на елемента, сочен от указателя,
	//или обхождане на поддървото, сочено от указателя
	using pendingTraverseStep = pair<int,Node*>;
	//всеки указател, попаднал в стека, е
	//"анотиран" с едната от двете операции
	#define STEP_EXTRACT_ROOT 0
	#define STEP_TRAVERSE_SUBTREE 1

public:

	//итератор, реализиращ
	//обхождане ЛКД на дървото
	class LeftRootRightIterator
	{

	public:
		LeftRootRightIterator (Node *root);
		T& operator * ();
		LeftRootRightIterator& operator ++ ();
		bool operator != (const LeftRootRightIterator &other);
	private:
		/*
		Стек с "изчакващи" операции.
		Празният стек "кодира" край на процеса
		по обхождане.
		*/
		stack<pendingTraverseStep> operations;
		void unwind ();
	};


private:
	Node *root;
	bool add (const T& data, const char *trace, Node*&);
	void deleteAll (Node *subTreeRoot);
	void dottyPrint (Node *subTreeRoot,ostream& out) const;
	static Node* copyTree (const Node *subTreeRoot);
	void insertBOT (Node*&subTreeRoot,const T& x);
	void deleteElement (Node *&subTreeRoot, const T&x);
	T minelement (Node *subTreeRoot) const;
	bool member (const T& x,BTree<T>::Node *subTreeRoot) const;


public:
	BTree();
	BTree (const BTree<T> &other);

	LeftRootRightIterator end ();
	LeftRootRightIterator begin ();

	BTree<T>& operator = (const BTree<T> &other);

	BTree<T>& add (const T& data, const char *trace);

	void deleteElement (const T&x);

	void dottyPrint (ostream&);

	bool member (const T&) const;

	BTree<T>& insertBOT (const T& x);

	T minelement ()const;

	~BTree();

};


template <class T>
BTree<T>::Node::Node (const T& d,BTree<T>::Node *l, BTree<T>::Node *r)
  :left(l),right(r),data(d)
{
	makeID();
}
template <class T>
BTree<T>::Node::Node ():left(nullptr),right(nullptr)
{
	makeID();
}

template <class T>
int BTree<T>::Node::getID() const
{
	return id;
}

template <class T>
void BTree<T>::Node::makeID ()
{
	static int maxID = 0;
	maxID++;
	id = maxID;

}


/*
Обхождането на дървото стартира с поставяне на 
операция за обхождане, започвайки от корена на дървото
*/
template<class T>
BTree<T>::LeftRootRightIterator::LeftRootRightIterator (BTree<T>::Node *root)
{
	if (root != nullptr)
	{
		operations.push (BTree<T>::pendingTraverseStep (STEP_TRAVERSE_SUBTREE,root));
		unwind();
	}
}

template<class T>
T& BTree<T>::LeftRootRightIterator::operator * ()
{

	//всички операции с итератора осигуряват, че на върха му
	//има операция за извличане или стекът е празен. Други
	//състояния на стека не са допустими.
	//Възелът на върха на стека е текущо посетения възел
	//при обхождането


	assert (!operations.empty());
	assert (operations.top().first == STEP_EXTRACT_ROOT);
	assert (operations.top().second != nullptr);

	
	return operations.top().second->data;

}

template<class T>
typename BTree<T>::LeftRootRightIterator& BTree<T>::LeftRootRightIterator::operator++ ()
{
	//всички операции с итератора осигуряват, че на върха му
	//има операция за извличане или стекът е празен. Други
	//състояния на стека не са допустими.
	//Възелът на върха на стека е текущо посетения възел
	//при обхождането

	assert (!operations.empty());
	//премахва се операцията за извличане, която е на върха на стека.
	//това довежда до продължаване на обхождането към следващите "части"
	//да дървото, или "активиране" на ичакващите под върха на стека операции
	operations.pop();
	//стекът се "доразвива" до достигане на следваща
	//операция за извличане
	unwind();
	return *this;
}

template<class T>
bool BTree<T>::LeftRootRightIterator::operator != (const LeftRootRightIterator &other)
{
	
	if (operations.empty())
		return !other.operations.empty();

	if (other.operations.empty())
		return !operations.empty();

	//и двете са непразни

	return operations.top() != other.operations.top();
}  

template<class T>
void BTree<T>::LeftRootRightIterator::unwind ()
{

	//всички операции с итератора осигуряват, че на върха му
	//има операция за извличане или стекът е празен. Други
	//състояния на стека не са допустими.
	//Възелът на върха на стека е текущо посетения възел
	//при обхождането

	//този метод извършва обхождането на чакащите за 
	//обхождане указатели към поддървета до момента, в който
	//се достигне до операция за извличане на елемент. Т.е.
	//обхождането се "развива" до достигане на следващя чакащ
	//за "отпечатване" връх


	if (operations.empty())
		return;

	BTree<T>::pendingTraverseStep topOperation = operations.top();
	BTree<T>::Node* topNode = topOperation.second;

	while (!operations.empty() && topOperation.first != STEP_EXTRACT_ROOT)
	{

		operations.pop();

		if (topNode->right != nullptr)
			operations.push (BTree<T>::pendingTraverseStep(STEP_TRAVERSE_SUBTREE,topNode->right));
		operations.push (BTree<T>::pendingTraverseStep(STEP_EXTRACT_ROOT,topNode));
		if (topNode->left != nullptr)
			operations.push (BTree<T>::pendingTraverseStep(STEP_TRAVERSE_SUBTREE,topNode->left));

		topOperation = operations.top();
		topNode = topOperation.second;

	}

	//стекът е или празен или на върха му има операция за извличане
}

template<class T>
typename BTree<T>::LeftRootRightIterator BTree<T>::end ()
{
	return LeftRootRightIterator (nullptr);
}

template<class T>
typename BTree<T>::LeftRootRightIterator BTree<T>::begin ()
{
	return LeftRootRightIterator (root);
}

template<class T>
void BTree<T>::deleteElement (BTree<T>::Node *&subTreeRoot, const T&x)
{
	//триене от празно дърво
	if (subTreeRoot==nullptr)
		return;

	//триене от листо
	if (subTreeRoot->data == x &&
		subTreeRoot->left == nullptr &&
		subTreeRoot->right == nullptr)

	{
		delete subTreeRoot;
		subTreeRoot = nullptr;	
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
	if (subTreeRoot->right == nullptr)
	{
		BTree<T>::Node *tmp = subTreeRoot;
		subTreeRoot = subTreeRoot->left;
		delete tmp;
		return;
	}

	//триене на корен само с 1 наследник
	//този случй може да не се разглежда
	if (subTreeRoot->left == nullptr)
	{
		BTree<T>::Node *tmp = subTreeRoot;
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
T BTree<T>::minelement (BTree<T>::Node *subTreeRoot) const
{
	assert (subTreeRoot != nullptr);
	BTree<T>::Node *current = subTreeRoot;

	while (current->left != nullptr)
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
void BTree<T>::insertBOT (BTree<T>::Node* &subTreeRoot,const T& x)
{

	if (subTreeRoot == nullptr)
	{
		subTreeRoot = new BTree<T>::Node (x,nullptr,nullptr);
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
typename BTree<T>::Node* BTree<T>::copyTree (const BTree<T>::Node *subTreeRoot)
{
	if (subTreeRoot == nullptr)
		return nullptr;

	return new BTree<T>::Node (subTreeRoot->data,
		                copyTree(subTreeRoot->left),
		                copyTree(subTreeRoot->right));
}

template<class T>
BTree<T>::BTree (const BTree<T> &other)
{
	root = copyTree (other.root);
}

template<class T>
void BTree<T>::dottyPrint (ostream &out)
{
	dottyPrint (root,out);
}

template<class T>
void BTree<T>::dottyPrint (BTree<T>::Node *subTreeRoot,ostream& out) const
{
	if (subTreeRoot == nullptr)
		return;

	out << subTreeRoot->getID() 
	    << "[label=\"" 
	    << subTreeRoot->data 
	    << "\"];" << endl;

	if (subTreeRoot->left != nullptr)
		out << subTreeRoot->getID() 
	        <<"->"
	        << subTreeRoot->left->getID()
	        << endl;

	if (subTreeRoot->right != nullptr)
		out << subTreeRoot->getID() 
	        <<"->"
	        << subTreeRoot->right->getID()
	        << endl;

	dottyPrint (subTreeRoot->left,out);
	dottyPrint (subTreeRoot->right,out);
}

template<class T>
bool BTree<T>::member (const T& x) const
{
	return member (x,root);
}


template<class T>
bool BTree<T>::member (const T& x,BTree<T>::Node *subTreeRoot) const
{
	if (subTreeRoot == nullptr)
		return false;


	return subTreeRoot->data == x ||
	       member (x,subTreeRoot->left) ||
	       member (x,subTreeRoot->right);


}

template<class T>
void BTree<T>::deleteAll (BTree<T>::Node *subTreeRoot)
{
	if (subTreeRoot == nullptr)
		return;

	deleteAll (subTreeRoot->left);
	deleteAll (subTreeRoot->right);
	delete subTreeRoot;
}

template <class T>
BTree<T>::~BTree()
{
	deleteAll (root);
	root = nullptr;

}


template <class T>
BTree<T>& BTree<T>::add(const T& x, const char *trace)
{
   add (x,trace,root);
   return *this;
}


template <class T>
bool BTree<T>::add(const T& x, const char *trace, BTree<T>::Node* &subTreeRoot)
{
	if (subTreeRoot == nullptr)
	{
		assert (strlen(trace) == 0);
		subTreeRoot = new BTree<T>::Node (x,nullptr,nullptr);
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
BTree<T>::BTree ():root(nullptr){}


