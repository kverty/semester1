#pragma once

const int nameSize = 100;

struct Name
{
    char* str;
    int length;
};

Name *createName(char* str, int length);
bool isEqual(Name *name1, Name *name2);
