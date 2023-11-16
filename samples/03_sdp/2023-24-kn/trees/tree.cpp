#include "tree.h"
#include <iostream>
#include <iomanip>
#include <cassert>

Tree::Tree():root(nullptr)
{

}

/*Tree::Tree(const Tree&)
{

}*/
/*Tree::Tree(Tree&&)
{

}*/

/*Tree& Tree::operator = (const Tree&)
{

    return *this;
}*/

void Tree::insert(int x, const char *trace)
{
    return insertHelp(x,trace,root);
}

void Tree::insertHelp(int x, const char *trace, Tree::box *&current)
{
    if(trace[0] == 0)
    {
        if(current == nullptr)
        {
            current = new Tree::box{nullptr,nullptr,x};
        } else
        {
            current->data = x;
        }
        return;
    }

    if(current == nullptr)
    {
        throw "Out of Tree bounds!";
    }

    if(trace[0] == 'L')
    {
        insertHelp(x,trace+1,current->left);
    } else if (trace[0] == 'R')
    {
        insertHelp(x,trace+1,current->right);
    } else 
    {
        throw "Invalid trace!";
    }
}
void Tree::print()
{
    print(root,0);
}

void Tree::print(box *&current, int depth)
{
    if(current == nullptr)
    {
        return;
    }

    print(current->right,depth+1);
    std::cout << std::setw(depth*5) <<current->data << std::endl;
    print(current->left,depth+1);
}

void Tree::printDot()
{
    std::cout << "digraph G{" << std::endl;

    printDot(root);

    std::cout << "}" << std::endl;
}


void Tree::printDot(box *&current)
{

    if(current == nullptr)
    {
        return;
    }

    std::cout << (long)current << "[label=\"" << current->data << "\"];" << std::endl;

    if(current->left != nullptr)
    {
        std::cout << (long)current << "->" << (long)(current->left) << "[color=\"red\"];" << std::endl;
    }
    if(current->right != nullptr)
    {
        std::cout << (long)current << "->" << (long)(current->right) << "[color=\"blue\"];" << std::endl;
    }

    printDot(current->left);
    printDot(current->right);
}

Tree::~Tree()
{

}

Tree::Tree(int x,Tree&& left,Tree&& right)
{
    root = new typename Tree::box {left.root, right.root, x};
    left.root = nullptr;
    right.root = nullptr;
}

bool Tree::member(int x, box *current)
{

    return current != nullptr &&
           (x == current->data ||
            member(x,current->left) ||
            member(x,current->right));

}

bool Tree::member(int x)
{
    return member(x,root);
}

int Tree::sum()
{
    return sum(root);
}

int Tree::sum(box *current)
{
    if(current == nullptr)
    {
        return 0;
    }

    return sum(current->left) + current->data + sum(current->right);
}

typename Tree::Iterator Tree::begin() const
{
    return Iterator(root);
}

typename Tree::Iterator Tree::end() const
{
    return Iterator(nullptr);
}

void Tree::Iterator::windstack()
{
    typename Tree::box* crr = s.top();
    while(crr->left != nullptr)
    {
        s.push(crr->left);
        crr = crr->left;
    }  
}

typename Tree::Iterator& Tree::Iterator::operator++()
{
    typename Tree::box* crr = s.top(); s.pop();
    if (crr->right != nullptr)
    {
        s.push(crr->right);
        windstack();
    }
    return *this;
}

int Tree::Iterator::operator*()
{
    return s.top()->data;
}

bool Tree::Iterator::operator != (const typename Tree::Iterator &other)
{
    return s.empty() && !other.s.empty() ||
           !s.empty() && other.s.empty() ||
            (!s.empty() && !other.s.empty() && s.top() != other.s.top());
}

Tree::Iterator::Iterator(typename Tree::box *root)
{
    
    if(root == nullptr)
    {
        return;
    }
    
    s.push(root);
    windstack();

}


void toScheme(const Tree::TreeVisitor& v, std::ostream &out)
{
    if(v.empty())
    {
        out << "()";
        return;
    }

    out << "("
        << v.root()
        << " ";
    toScheme(v.left(),out);

    out << " ";

    toScheme(v.right(), out);

    out << ")";
    
}

std::ostream& operator << (std::ostream& out, Tree& t)
{
    toScheme(t.visit(),out);
    return out;
}


Tree fromScheme(std::istream &in)
{

    while(std::isspace(in.peek()))
    {
        in.get();
    }

    assert(in.get() == '(');
    if(in.peek() == ')')
    {
        in.get();
        return Tree();
    }

    //<root> <left> <right>)

    int root;
    in >> root;

    // <left> <right>)

    Tree left = fromScheme(in);

    //<right>)

    Tree right = fromScheme(in);

    //)

    while(std::isspace(in.peek()))
    {
        in.get();
    }
    assert(in.get()==')');

    return Tree(root,std::move(left),std::move(right));


}

std::istream& operator >> (std::istream& in, Tree& t)
{
    t = fromScheme(in);
    return in;
}

Tree::TreeVisitor::TreeVisitor(box *root):current(root)
{

}
bool Tree::TreeVisitor::empty() const
{
    return current == nullptr;
}

int Tree::TreeVisitor::root() const
{
    return current->data;
}
typename Tree::TreeVisitor Tree::TreeVisitor::left() const
{
    return typename Tree::TreeVisitor(current->left);
}
typename Tree::TreeVisitor Tree::TreeVisitor::right() const
{
    return typename Tree::TreeVisitor(current->right);
}

typename Tree::TreeVisitor Tree::visit()
{
    return TreeVisitor(root);
}
