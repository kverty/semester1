#pragma once
#include <exception>

class ElementNotFoundException
{

};

/// element of the tree
class TreeElement
{
public:
    TreeElement(int value) : value(value), left(nullptr), right(nullptr) {}
    ~TreeElement() {}
    int value;
    TreeElement *left;
    TreeElement *right;
    int type();
};


/// binary tree
class Tree
{
public:
    Tree() : root(nullptr) {}
    ~Tree()
    {
        deleteTree(root);
    }

    void addValue(int value);
    void deleteValue(int value) throw (ElementNotFoundException)
    {
        if (contains(value))
            deleteElementInSubtree(root, value);
        else
            throw ElementNotFoundException();
    }

    /// checks if this value is in the tree
    bool contains(int value);

    TreeElement *returnRoot()
    {
        return root;
    }

    /// delete element
    void deleteElement(TreeElement *&element);

private:
    TreeElement *root;

    /// recursive addition
    void addElement(TreeElement* &current, int value);

    /// recursive deletion
    void deleteElementInSubtree(TreeElement* &current, int value);
    /// recursive clearing
    void deleteTree(TreeElement* &element);
    /// returns the biggest value smaller than this node
    int leftmostChild(TreeElement* &element);
};
