#include "tree.h"

enum ElementType
{
    noChildren,
    leftChild,
    rightChild,
    twoChildren
};

void Tree::addValue(int value)
{
    if (root == nullptr)
    {
        TreeElement *newElement = new TreeElement(value);
        root = newElement;
        return;
    }
    addElement(root, value);
}

bool Tree::contains(int value)
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

int TreeElement::type()
{
    if ((left == nullptr) && (right == nullptr))
        return noChildren;
    if (right == nullptr)
        return leftChild;
    if (left == nullptr)
        return rightChild;
    return twoChildren;
}

void Tree::addElement(TreeElement* &current, int value)
{
    if (value > current->value)
    {
        if (current->right == nullptr)
        {
            TreeElement *newElement = new TreeElement(value);
            current->right = newElement;
            return;
        }
        addElement(current->right, value);
    }

    if (value <= current->value)
    {
        if (current->left == nullptr)
        {
            TreeElement *newElement = new TreeElement(value);
            current->left = newElement;
            return;
        }
        addElement(current->left, value);
    }
}

void Tree::deleteElement(TreeElement* &element)
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

}

void Tree::deleteElementInSubtree(TreeElement* &current, int value)
{
    if (current->value > value)
    {
        deleteElementInSubtree(current->left, value);
    }
    else if (current->value < value)
    {
        deleteElementInSubtree(current->right, value);
    }
    else
        deleteElement(current);
}

void Tree::deleteTree(TreeElement* &element)
{
    if (element != nullptr)
    {
        deleteTree(element->left);
        deleteTree(element->right);
        delete element;
    }
}

int Tree::leftmostChild(TreeElement* &element)
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
