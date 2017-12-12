#ifndef __TRIEMAP__
#define __TRIEMAP__

#include <vector>
#include <string>

//фиксираме мн. ключовете да са малките латински букви
template <class ValueType>
class TrieMap
{
public:
  TrieMap ();

  ValueType& operator [] (const std::string &);
  const ValueType& operator [] (const std::string&) const;

  bool hasKey (const std::string&) const;

private:
  struct Node
  {
    std::vector<Node*> children;
    ValueType *value;
    Node (ValueType*);
  };
  Node *root;

  Node *seek (const std::string&,
              unsigned int,
              Node*);

};

template <class ValueType>
TrieMap<ValueType>::TrieMap ():root(nullptr){}

template <class ValueType>TrieMap<ValueType>::Node::Node (ValueType* v)
{
  value = v;
  children.assign (26,nullptr);
}

template <class ValueType>
const ValueType& TrieMap<ValueType>::operator [] (const std::string &key) const
{
  Node *node = seek (key,0,root);
  assert (node != nullptr);

  return *(node->value);
}

template <class ValueType>
ValueType& TrieMap<ValueType>::operator [] (const std::string &key)
{

  if (root == nullptr)
  {
    root = new Node (nullptr);
  }

  Node *crr = root;
  unsigned int index = 0;

  //P: crr винаги сочи текещо достигнатия
  //   възел на дървото, и той никога не NULL
  while (index < key.length())
  {
    Node *&child = crr->children[key[index]-'a'];

    if (child == nullptr)
    {
        child = new Node (nullptr);
    }

    crr = child;

    index++;
  }
  if (crr->value == nullptr)
  {
    crr->value = new ValueType();
  }
  return *(crr->value);

}


template <class ValueType>
typename TrieMap<ValueType>::Node *TrieMap<ValueType>
                        ::seek (const std::string &key,
                                unsigned int height,
                                Node *current)
{
  if (key == "" || height == key.length())
  {
    return current;
  }
  if (current == nullptr)
  {
    return nullptr;
  }

  assert (key[height] >= 'a' && key[height] <= 'z');
  unsigned int childIx = key[height]-'a';

  return seek (key,height+1,current->children[childIx]);
}



#endif
