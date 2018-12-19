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
  //такъв път няма в дървото! Без тази проверка,
  //изразът в следващия return създава key-value
  //с произволна стойност за указателя!
  if (root->children.count(key[0]) == 0)
  {
    return nullptr;
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
  //осигуряваме, че още в началото стекът е подготвен за
  //getCurrent()
  if (!yieldCondition())
  {
    moveToNext();
  }
}

template <class ValType>
std::string TrieMap<ValType>::getCurrent ()
{
  assert (!end());
  return itStack.top().partialKey;
}

template <class ValType>
bool TrieMap<ValType>::yieldCondition ()
{
  /* Обхождането на дървото достига до момент,
     в който може да "пропусне" изпънението на
     програмата, когато:
     - (a)Дървото е изчерпано (обходени са всички възли)
     - Достигнат е значещ елемент. Това е вярно, ако
        - (b)На върха на стека има възел със стойност != nullptr
          И
        - (c)Обхождането на децата на този възел все още не е
          започнало (т.е. той "току що" е попаднал в стека)
  */
  return itStack.empty () || /* (a) */
         (itStack.top().currentSubtree->value != nullptr && /* (b) */
          itStack.top().currentChild ==
             (itStack.top().currentSubtree->children.cbegin())); /* (c) */

}

template <class ValType>
void TrieMap<ValType>::moveToNext ()
{
  assert (!itStack.empty());

  do
  {
      StackNode<ValType> &topNode = itStack.top();
      if (topNode.currentChild
            != topNode.currentSubtree->children.cend())
      {
          itStack.push (StackNode<ValType>(topNode.partialKey+topNode.currentChild->first,
                                           topNode.currentChild->second,
                                           topNode.currentChild->second->children.cbegin()));
          ++topNode.currentChild;
      } else {
        itStack.pop();
      }
  } while (!yieldCondition());
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
