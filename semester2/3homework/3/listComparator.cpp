#include "listComparator.h"

ComparableWithSize::ComparableWithSize() : size(0)
{

}

int ComparableWithSize::compareTo(ComparableWithSize *list)
{
    if(list->size < size)
        return bigger;
    if(list->size > size)
        return smaller;
    return equall;
}
