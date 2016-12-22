#include <string>
#include "../03_hmap/hmap.cpp"

using namespace std;

template <class ValueType>
struct TrieNode
{
		
	TrieNode ();
	TrieNode (const TrieNode<ValueType>&);
	~TrieNode();

	TrieNode& operator = (const TrieNode<ValueType>&);


	ValueType *data;
	HashMap<char,TrieNode> children;

};

size_t charHash (const char& c, size_t size)
{
	return c % size;
}

template <class ValueType>
TrieNode<ValueType>::TrieNode ()
  :children(255,charHash), data(nullptr){}


template <class ValueType>
TrieNode<ValueType>::TrieNode (const TrieNode<ValueType> &other):
      children (other.children)
{
	if (other.data)
		data = new ValueType (*(other.data));
	else
		data = nullptr;
}

template <class ValueType>
TrieNode<ValueType>::~TrieNode()
{
	delete data;
}

template <class ValueType>
TrieNode<ValueType>& TrieNode<ValueType>::operator = 
    (const TrieNode<ValueType> &other)
{
	if (this != &other)
	{
		delete data;
		if (other.data)
			data = new ValueType (*(other.data));
		else
			data = nullptr;
		children = other.children;
	}

	return *this;
}


//TODO: Fix TrieNode

template <class ValueType>
class Trie
{
private:

	TrieNode<ValueType> root;

public:

	void set (const string &key, const ValueType &val);
	ValueType get (const string &key) const;
	bool contains (const string &key) const;

private:

	void setValue (const string& key, 
				      const ValueType& value,
		              TrieNode<ValueType> &node);

	bool contains (const string &key, const TrieNode<ValueType> &node) const;

	ValueType get (const string &key, const TrieNode<ValueType> &node) const;


};

template <class ValueType>
void Trie<ValueType>::setValue (const string& key, 
								   const ValueType& value,
	 							   TrieNode<ValueType> &node)
{

	if (key.empty())
	{
		if(node.data != nullptr)
		{
			delete node.data;
		}
		node.data = new ValueType (value);
	
	} else {

		if (!node.children.containsKey (key[0]))
		{
			node.children[key[0]] = TrieNode<ValueType>();
		}

		setValue (key.substr(1),
			      value,
			      node.children[key[0]]);
		
	}

}

template <class ValueType>
void Trie<ValueType>::set (const string &key, const ValueType &val)
{
	setValue (key,val,root);
}

template <class ValueType>
bool Trie<ValueType>::contains (const string &key, const TrieNode<ValueType> &node) const
{
	if (key.empty())
	{
		return node.data != nullptr;
	}

	if (!node.children.containsKey (key[0]))
	{
		return false;
	}

	return contains (key.substr(1),
		             node.children[key[0]]);
}


template <class ValueType>
bool Trie<ValueType>::contains (const string &key) const
{
	return contains (key,root);	
}

template <class ValueType>
ValueType Trie<ValueType>::get (const string &key, const TrieNode<ValueType>& node) const
{
	if (key.empty())
	{
		assert (node.data != nullptr);
		return *(node.data);
	}

	assert (node.children.containsKey (key[0]));

	return get (key.substr(1),
		        node.children[key[0]]);

}

template <class ValueType>
ValueType Trie<ValueType>::get (const string &key) const
{
	return get (key,root);
}






