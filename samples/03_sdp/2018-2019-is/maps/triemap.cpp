#include "triemap.h"

template <class ValType>
TrieMap<ValType>::TrieMap ():root(nullptr)
{

}

template <class ValType>
void TrieMap<ValType>::update (const std::string &key, const ValType &value)
{
  root = traceOrCreatePath (key.c_str(),root,value);
}


template <class ValType>
bool  TrieMap<ValType>::hasKey (const std::string &key) const
{
    return locate(key.c_str(),root) != nullptr;

}

template <class ValType>
ValType TrieMap<ValType>::get (const std::string &key) const
{
  TrieNode<ValType> *node = locate(key.c_str(),root);
  assert (node != nullptr);
  return *(node->value);
}

template <class ValType>
void TrieMap<ValType>::remove (const std::string&)
{

}

template <class ValType>
TrieNode<ValType>*
    TrieMap<ValType>::traceOrCreatePath (const char* key,
                                         TrieNode<ValType> *current,
                                         const ValType &val)
{
    if (current == nullptr && key[0] == 0)
    {
      return new TrieNode<ValType>(new ValType (val));
    }
    if (key[0] == 0) //current != nullptr
    {
      if (current->value != nullptr)
      {
        delete current->value;
      }
      current->value = new ValType (val);
      return current;
    }
    if (current == nullptr) //key != ""
    {
      current = new TrieNode<ValType> (nullptr);
    }
    //current != nullptr && key != ""
    current->children[key[0]] = traceOrCreatePath (key+1,current->children[key[0]],val);
    return current;
}


template <class ValType>
void TrieMap<ValType>::printDotty (std::ostream &out)
{
    out << "digraph G{\n";

    printDottyHelper (out,root);

    out << "}";
}


template <class ValType>
void TrieMap<ValType>::printDottyHelper (std::ostream &out,TrieNode<ValType> *root)
{
    if (root == nullptr)
    {
      return;
    }
    out << (long)root << "[label=\"";
    if (root->value == nullptr)
    {
      out << "_";
    } else {
      out << *(root->value);
    }
    out << "\"];\n";
    typename std::map<char,TrieNode<ValType>*>::iterator
                                      it = root->children.begin();
    while (it != root->children.end())
    {
      //ROOT -> [label] CHILD
      out << (long)root
          << "->"
          << (long)it->second
          << "[label=\""
          << it->first
          << "\"];\n";
      printDottyHelper (out,it->second);
      ++it;
    }

}

template <class ValType>
TrieNode<ValType>* TrieMap<ValType>::
           locate (const char *key, TrieNode<ValType> *root) const
{
  if (root == nullptr || key[0] == 0)
  {
    return root;
  }
  return locate (key+1,root->children[key[0]]);
}

template <class ValType>
void TrieMap<ValType>::
   printAllKeys ()
{
 printAllKeysHelper (root,"");
}

template <class ValType>
void TrieMap<ValType>::start()
{
  if (root == nullptr)
  {
    return;
  }
  itStack.push (StackNode<ValType>("",root,root->children.cbegin()));
}


template <class ValType>
std::string TrieMap<ValType>::getCurrent ()
{
  assert (itStack.size() != 0);

  TrieNode<ValType> *currentSubTree = itStack.top().currentSubtree;

  if (currentSubTree->value != nullptr)
  {
    return *(currentSubTree->value);
  }

  moveToNext ();
  assert (!end());
  return *(itStack.top().currentSubtree->value);


}
template <class ValType>
void TrieMap<ValType>::moveToNext ()
{
  assert (itStack.size() != 0);

  do
  {
      StackNode<ValType> &topNode = itStack.top();

      if (topNode.currentChild
            != topNode.currentSubtree->children.end())
      {
          itStack.push (StackNode<ValType>(topNode.partialKey+topNode.currentChild->first,
                                           topNode.currentChild->second,
                                           topNode.currentChild->second->children.cbegin()));
          ++topNode.currentChild;
      } else {
        itStack.pop();
      }
  } while (!itStack.empty() &&
         itStack.top().currentSubtree->value == nullptr);

}
template <class ValType>
bool TrieMap<ValType>::end()
{
  return itStack.empty();
}


template <class ValType>
void TrieMap<ValType>::
   printAllKeysHelper (TrieNode<ValType> *root, std::string crrKey)
{
  if (root == nullptr)
  {
    return;
  }

  if (root->value != nullptr)
  {
    std::cout << crrKey << "\n";
  }

  typename std::map<char,TrieNode<ValType>*>::iterator
                                    it = root->children.begin();
  while (it != root->children.end())
  {
    printAllKeysHelper (it->second,crrKey+(it->first));
    ++it;
  }

}
