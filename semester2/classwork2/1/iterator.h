#pragma once
#include "tree.h"

/// exception if we want to find next and both children are nullptr
class problemWithNextException
{

};

/// interator that helps to go throught the tree
class TreeIterator
{
public:
    TreeIterator(Tree* &tree) : tree(tree), current(tree->returnRoot())
    {
        if (current != nullptr)
            theEnd = false;
    }
    /// returns value of current element and finds next element of the tree
    int next()
    {
        int result = current->value;
        try
        {
            current = nextCurrent(tree->returnRoot(), current);
        }

        catch(problemWithNextException)
        {
            theEnd = true;
        }

        return result;
    }
    /// true if the last element was shown
    bool isLast()
    {
        return theEnd;
    }
    /// goes to the start
    void reset()
    {
        current = tree->returnRoot();
    }
    /// removes current value
    void remove()
    {
        if (!theEnd)
        {
            TreeElement *oldCurrent = current;
            tree->deleteElement(current);
            try
            {
                current = nextCurrent(tree->returnRoot(), oldCurrent);
            }

            catch(problemWithNextException)
            {
                theEnd = true;
            }

        }
    }

private:
    Tree *tree;
    TreeElement *current;
    TreeElement *nextCurrent(TreeElement *current, TreeElement *wanted);
    bool theEnd;
};
