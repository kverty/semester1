#include "iterator.h"

TreeElement *TreeIterator::nextCurrent(TreeElement *current, TreeElement *wanted)
{
    if (current == wanted)
    {
        if (current->left != nullptr)
            return current->left;
        if (current->right != nullptr)
            return current->right;
        throw problemWithNextException();
    }
    else
    {
        try
        {
            TreeElement *tryLeft = nextCurrent(current->left, wanted);
            if (tryLeft != nullptr)
                return tryLeft;
        }
        catch(problemWithNextException)
        {
            if (current->right != nullptr)
                return current->right;
            throw problemWithNextException();
        }

        try
        {
            TreeElement *tryRight = nextCurrent(current->right, wanted);
            if (tryRight != nullptr)
                return tryRight;
        }
        catch(problemWithNextException)
        {
            throw problemWithNextException();
        }
    }
}
