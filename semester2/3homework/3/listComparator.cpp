#include "listComparator.h"

ComparableWithSize::ComparableWithSize() : size(0)
{

}

int ComparableWithSize::CompareTo(ComparableWithSize *list)
{
    if(list->size < size)
        return bigger;
    if(list->size > size)
        return smaller;
    return equall;
}
