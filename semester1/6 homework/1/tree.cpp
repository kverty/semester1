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

struct BinaryTree
{
    TreeElement *root;
};

struct TreeElement
{
    int value;
    TreeElement *left;
    TreeElement *right;
};

BinaryTree *createTree()
{
    BinaryTree *tree = new BinaryTree;
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

void deleteTree(BinaryTree* tree)
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
    return element;
}

void addElement(BinaryTree* &tree, int value)
{
    TreeElement *current = tree->root;
    if (current == nullptr)
    {
        TreeElement *newElement = createElement(value);
        tree->root = newElement;
        return;
    }

    while (true)
    {
        if (value > current->value)
        {
            if (current->right == nullptr)
            {
                TreeElement *newElement = createElement(value);
                current->right = newElement;
                return;
            }
            current = current->right;
        }
        if (value < current->value)
        {
            if (current->left == nullptr)
            {
                TreeElement *newElement = createElement(value);
                current->left = newElement;
                return;
            }
            current = current->left;
        }
        if (value == current->value)
        {
            cout << "Error - you have added this number." << endl;
            return;
        }
    }
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
        deleteElementInSubtree(current->left, value);
    else if (current->value < value)
        deleteElementInSubtree(current->right, value);
    else
        deleteElement(current);
}

void deleteElementInTree(BinaryTree* &tree, int value)
{

    deleteElementInSubtree(tree->root, value);
}


bool wasFound(BinaryTree *tree, int value)
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
     cout << element->value << " ";
     ascendingPrint(element->right);
}

void ascendingPrint(BinaryTree *tree)
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

void descendingPrint(BinaryTree *tree)
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

void printTree(BinaryTree *tree)
{
    printElement(tree->root);
}
