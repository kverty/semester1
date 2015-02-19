#include "tree.h"
#include <iostream>

using std::cout;
using std::endl;

enum ElementType
{
    noChildren,
    leftChild,
    rightChild,
    twoChildren
};

struct AVLTree
{
    TreeElement *root;
};

struct TreeElement
{
    int value;
    int height;
    TreeElement *left;
    TreeElement *right;
};

int height(TreeElement *element)
{
    if (element == nullptr)
        return 0;
    else
        return element->height;
}

int balanceFactor(TreeElement *element)
{
    return height(element->right) - height(element->left);
}

void updateHeight(TreeElement* &element)
{
    int heightLeft = height(element->left);
    int heightRight = height(element->right);

    if (heightLeft > heightRight)
        element->height = heightLeft + 1;
    else
        element->height = heightRight + 1;
}

TreeElement *turnRight(TreeElement* &element)
{
   TreeElement* leftChild = element->left;
   element->left = leftChild->right;
   leftChild->right = element;
   updateHeight(element);
   updateHeight(leftChild);
   return leftChild;
}

TreeElement *turnLeft(TreeElement* &element)
{
   TreeElement* rightChild = element->right;
   element->right = rightChild->left;
   rightChild->left = element;
   updateHeight(element);
   updateHeight(rightChild);
   return rightChild;
}

TreeElement *balance(TreeElement *element)
{
    updateHeight(element);

    if (balanceFactor(element) == 2)
    {
        if (balanceFactor(element->right) < 0)
            element->right = turnRight(element->right);

        return turnLeft(element);
    }

    if (balanceFactor(element) == -2)
    {
        if (balanceFactor(element->left) > 0)
            element->left = turnLeft(element->left);

        return turnRight(element);
    }

    return element;
}


AVLTree *createTree()
{
    AVLTree *tree = new AVLTree;
    tree->root = nullptr;
    return tree;
}

void deleteTree(TreeElement* element)
{
    if (element == nullptr)
        return;
    deleteTree(element->left);
    deleteTree(element->right);
    delete element;
}

void deleteTree(AVLTree* tree)
{
    deleteTree(tree->root);
    delete tree;
}

TreeElement *createElement(int value, int height)
{
    TreeElement *element = new TreeElement;
    element->left = nullptr;
    element->right = nullptr;
    element->value = value;
    element->height = height;
    return element;
}

void addElement(TreeElement* &current, int value)
{
    if (value > current->value)
    {
        if (current->right == nullptr)
        {
            TreeElement *newElement = createElement(value, 1);
            current->right = newElement;
            current = balance(current);
            return;
        }
        addElement(current->right, value);
        current = balance(current);
    }

    if (value < current->value)
    {
        if (current->left == nullptr)
        {
            TreeElement *newElement = createElement(value, 1);
            current->left = newElement;
            current = balance(current);
            return;
        }
        addElement(current->left, value);
        current = balance(current);
    }
    if (value == current->value)
    {
        cout << "Error - you have added this number." << endl;
        return;
    }
}

void addElement(AVLTree *&tree, int value)
{
    if (tree->root == nullptr)
    {
        TreeElement *newElement = createElement(value, 0);
        tree->root = newElement;
        return;
    }
    addElement(tree->root, value);
}

int elementType(TreeElement *element)
{
    if ((element->left == nullptr) && (element->right == nullptr))
        return noChildren;
    if (element->right == nullptr)
        return leftChild;
    if (element->left == nullptr)
        return rightChild;
    return twoChildren;
}

int leftmostChild(TreeElement* &element);

void deleteElement(TreeElement* &element)
{
    if (elementType(element) == noChildren)
    {
        delete element;
        element = nullptr;
        //cout << "noChildren\n";
    }
    else if (elementType(element) == leftChild)
    {
        element->value = element->left->value;
        element->right = element->left->right;
        TreeElement *removedElement = element->left->left;
        delete element->left;
        element->left = removedElement;
        //cout << "leftChild\n";
    }
    else if (elementType(element) == rightChild)
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

int leftmostChild(TreeElement* &element)
{
    if (element->left == nullptr)
    {
        int result = element->value;
        deleteElement(element);
        return result;
    }
    else
        return leftmostChild(element->left);
}

void deleteElementInSubtree(TreeElement* &current, int value)
{
    if (current == nullptr)
    {
        cout << "Error - there is no such number\n";
        return;
    }

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

void deleteElementInTree(AVLTree* &tree, int value)
{

    deleteElementInSubtree(tree->root, value);
}


bool wasFound(AVLTree *tree, int value)
{
    TreeElement *current = tree->root;

    while(true)
    {
        if (current == nullptr)
            return false;

        if (current->value > value)
            current = current->left;
        else if (current->value < value)
            current = current->right;
        else
            return true;
    }
}
void ascendingPrint(TreeElement *element)
{
    if (element == nullptr)
        return;
     ascendingPrint(element->left);
     cout << element->value << " ";// << element->height << " " << elementType(element) << endl;
     ascendingPrint(element->right);
}

void ascendingPrint(AVLTree *tree)
{
     ascendingPrint(tree->root);
}

void descendingPrint(TreeElement *element)
{
    if (element == nullptr)
        return;
     descendingPrint(element->right);
     cout << element->value << " ";
     descendingPrint(element->left);
}

void descendingPrint(AVLTree *tree)
{
    descendingPrint(tree->root);
}

void printElement(TreeElement *element)
{
    if (element == nullptr)
        cout << "null";
    else
    {
        cout << "(" << element->value << " ";
        printElement(element->left);
        cout << " ";
        printElement(element->right);
        cout << ")";
    }
}

void printTree(AVLTree *tree)
{
    printElement(tree->root);
}
