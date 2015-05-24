#pragma once

#pragma once
#include <iostream>
#include <exception>

using std::cout;
using std::endl;

class ElementNotFoundException
{

};

/// class AVLTree - set of elements with AVL-Tree and pointers
/// T - any comparable type
template<typename T>
class AVLTree
{
public:
    AVLTree() : root(nullptr)
    {
    }
    ~AVLTree()
    {
        deleteTree(root);
    }
    /// add value to the tree
    void addValue(const T &value);
    /// remove value from the tree
    void deleteValue(const T &value) throw (ElementNotFoundException)
    {
        if (contains(value))
            deleteElementInSubtree(root, value);
        else
            throw ElementNotFoundException();
    }
    /// returns true if tree contains value
    bool contains(const T &value);
    /// prints all elements from min to max
    void ascendingPrint()
    {
         root->ascendingPrint();
    }
    /// prints all elements from max to min
    void descendingPrint()
    {
        root->descendingPrint();
    }
    /// prints all elements as a tree
    void printTree()
    {
        root->printElement();
    }

private:
    /// one node of the AVL tree
    class TreeElement
    {
    public:
        T value;
        /// height of this node, as a tree-node
        int height;
        TreeElement *left;
        TreeElement *right;

        TreeElement(const T &value, int height) : value(value), height(height), left(nullptr), right(nullptr)
        {
        }
        /// returns balnce factor
        int balanceFactor();
        /// recounts height with heights of children
        void updateHeight();
        /// returns type of this node, how many children it has
        int type();
        /// recursive print
        void printElement();
        void descendingPrint();
        void ascendingPrint();
    };
    TreeElement *root;

    /// restructoring tree if one child is bigger
    TreeElement *turnRight(TreeElement* &element)
    {
       TreeElement* leftChild = element->left;
       element->left = leftChild->right;
       leftChild->right = element;
       element->updateHeight();
       leftChild->updateHeight();
       return leftChild;
    }
    TreeElement *turnLeft(TreeElement* &element)
    {
       TreeElement* rightChild = element->right;
       element->right = rightChild->left;
       rightChild->left = element;
       element->updateHeight();
       rightChild->updateHeight();
       return rightChild;
    }
    TreeElement *balance(TreeElement *element)
    {
        element->updateHeight();

        if (element->balanceFactor() == 2)
        {
            if (element->right->balanceFactor() < 0)
                element->right = turnRight(element->right);

            return turnLeft(element);
        }

        if (element->balanceFactor() == -2)
        {
            if (element->left->balanceFactor() > 0)
                element->left = turnLeft(element->left);

            return turnRight(element);
        }

        return element;
    }
    /// recursive addition
    void addElement(TreeElement* &current, const T &value);
    /// delete element
    void deleteElement(TreeElement *&element);
    /// recursive deletion
    void deleteElementInSubtree(TreeElement* &current, const T &value);
    /// recursive clearing
    void deleteTree(TreeElement* &element);
    /// returns the biggest value smaller than this node
    T &leftmostChild(TreeElement* &element);
};

enum ElementType
{
    noChildren,
    leftChild,
    rightChild,
    twoChildren
};

template<typename T>
void AVLTree<T>::addValue(const T &value)
{
    if (root == nullptr)
    {
        TreeElement *newElement = new TreeElement(value, 0);
        root = newElement;
        return;
    }
    addElement(root, value);
}

template<typename T>
bool AVLTree<T>::contains(const T &value)
{
    TreeElement *current = root;

    while(current != nullptr)
    {
        if (current->value > value)
            current = current->left;
        else if (current->value < value)
            current = current->right;
        else
            return true;
    }
    return false;
}

template<typename T>
int AVLTree<T>::TreeElement::balanceFactor()
{
    if (left == nullptr && right == nullptr)
        return 0;
    if (left == nullptr)
        return right->height;
    if (right == nullptr)
        return left->height;
    return right->height - left->height;
}

template<typename T>
void AVLTree<T>::TreeElement::updateHeight()
{
    int heightLeft = -1;
    if (left != nullptr)
        heightLeft = left->height;

    int heightRight = -1;
    if (right != nullptr)
        heightRight = right->height;

    if (heightLeft > heightRight)
        height = heightLeft + 1;
    else
        height = heightRight + 1;
}

template<typename T>
int AVLTree<T>::TreeElement::type()
{
    if ((left == nullptr) && (right == nullptr))
        return noChildren;
    if (right == nullptr)
        return leftChild;
    if (left == nullptr)
        return rightChild;
    return twoChildren;
}

template<typename T>
void AVLTree<T>::TreeElement::printElement()
{
    cout << "(" << value << " ";
    if (left == nullptr)
        cout << "null";
    else
        printElement(left);
    cout << " ";
    if (right == nullptr)
        cout << "null";
    else
        printElement(right);
    cout << ")";
}

template<typename T>
void AVLTree<T>::TreeElement::descendingPrint()
{
    if (right != nullptr)
        right->descendingPrint();
    cout << value << " ";
    if (left != nullptr)
        left->descendingPrint();
}

template<typename T>
void AVLTree<T>::TreeElement::ascendingPrint()
{
    if (left != nullptr)
        left->ascendingPrint();
    cout << value << " ";// << element->height << " " << elementType(element) << endl;
    if (right != nullptr)
        right->ascendingPrint();
}



template<typename T>
void AVLTree<T>::addElement(TreeElement* &current, const T &value)
{
    if (value > current->value)
    {
        if (current->right == nullptr)
        {
            TreeElement *newElement = new TreeElement(value, 1);
            current->right = newElement;
            current = balance(current);
            return;
        }
        addElement(current->right, value);
        current = balance(current);
    }

    if (value <= current->value)
    {
        if (current->left == nullptr)
        {
            TreeElement *newElement = new TreeElement(value, 1);
            current->left = newElement;
            current = balance(current);
            return;
        }
        addElement(current->left, value);
        current = balance(current);
    }
}

template<typename T>
void AVLTree<T>::deleteElement(TreeElement* &element)
{
    if (element->type() == noChildren)
    {
        delete element;
        element = nullptr;
        //cout << "noChildren\n";
    }
    else if (element->type() == leftChild)
    {
        element->value = element->left->value;
        element->right = element->left->right;
        TreeElement *removedElement = element->left->left;
        delete element->left;
        element->left = removedElement;
        //cout << "leftChild\n";
    }
    else if (element->type() == rightChild)
    {
        element->value = element->right->value;
        element->left = element->right->left;
        TreeElement *removedElement = element->right->right;
        delete element->right;
        element->right = removedElement;
        //cout << "rightChild\n";
    }
    else
    {
        //cout << "both\n";
        element->value = leftmostChild(element->right);
    }
    //element = balance(element);
}

template<typename T>
void AVLTree<T>::deleteElementInSubtree(TreeElement* &current, const T &value)
{
    if (current->value > value)
    {
        deleteElementInSubtree(current->left, value);
        current = balance(current);
    }
    else if (current->value < value)
    {
        deleteElementInSubtree(current->right, value);
        current = balance(current);
    }
    else
        deleteElement(current);
}

template<typename T>
void AVLTree<T>::deleteTree(TreeElement* &element)
{
    if (element != nullptr)
    {
        deleteTree(element->left);
        deleteTree(element->right);
        delete element;
    }
}

template<typename T>
T &AVLTree<T>::leftmostChild(TreeElement* &element)
{
    if (element->left == nullptr)
    {
        T result = element->value;
        deleteElement(element);
        return result;
    }
    else
        return leftmostChild(element->left);
}
