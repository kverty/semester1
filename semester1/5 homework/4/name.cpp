#include <iostream>
#include "name.h"

Name *createName(char *str, int length)
{
    Name *newName = new Name;
    newName->str = str;
    newName->length = length;
    return newName;
}

bool isEqual(Name *name1, Name *name2)
{
    bool result = true;
    if (name1->length != name2->length)
        result = false;
    for (int i = 0; i < name1->length; i++)
    {
        if (name1->str[i] != name2->str[i])
            result = false;
    }
    return result;
}
