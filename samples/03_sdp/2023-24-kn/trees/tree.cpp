#include "tree.h"
#include <iostream>
#include <iomanip>

Tree::Tree():root(nullptr)
{

}

Tree::Tree(const Tree&)
{

}
Tree::Tree(const Tree&&)
{

}

Tree& Tree::operator = (const Tree&)
{

    return *this;
}

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

