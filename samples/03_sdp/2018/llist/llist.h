#ifndef __LIST_H
#define __LIST_H

template <class ElemType>
class LList
{
public:
  LList();
  LList (const LList<ElemType>&);

  void push (const ElemType&);
  const ElemType& peek() const;
  bool pop ();
  bool remove (unsigned int);
  bool addAt (unsigned int, const ElemType&);
  bool empty () const;
  void pushBack (const ElemType&);

  const ElemType& operator [] (unsigned int) const;
  LList<ElemType>& operator = (const LList<ElemType>&);

  ~LList();

private:
  struct Node
  {
    Node *next;
    ElemType data;
    Node (const ElemType&, Node*);
  };


  void copy (const LList <ElemType>&);
  void clear();
  Node *locate (unsigned int) const;

  Node *first;
};


#endif
