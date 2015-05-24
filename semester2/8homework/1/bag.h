#pragma once
#include "AVLTree.h"

/// class bag - set of elements with AVL-Tree and pointers
/// T - any comparable type
template<typename T>
class Bag
{
public:
    Bag() : tree(new AVLTree<T>())
    {
    }
    ~Bag()
    {
        delete tree;
    }
    /// add value to the bag
    void addValue(const T &value)
    {
        tree->addValue(value);
    }

    /// remove value from the bag
    void deleteValue(const T &value) throw (ElementNotFoundException)
    {
        tree->deleteValue(value);
    }
    /// returns true if bag contains value
    bool contains(const T &value)
    {
        return tree->contains(value);
    }

    /// prints all elements from min to max
    void ascendingPrint()
    {
         tree->ascendingPrint();
    }
    /// prints all elements from max to min
    void descendingPrint()
    {
        tree->descendingPrint();
    }
    /// prints all elements as a tree
    void printTree()
    {
        tree->printTree();
    }

private:
    AVLTree<T> *tree;
};
