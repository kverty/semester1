#pragma once
#include <string>

/// list of string
/// if hash of two strings is the same they form list
class SimpleList
{
public:
    SimpleList();
    ~SimpleList();

    /// everything is quite obvious
    void addElement(std::string value);
    bool deleteElement(std::string value);
    bool wasAdded(std::string value);
    void print();
    int length();
    std::string pop();

private:
    class ListElement
    {
    public:
        ListElement(std::string value, ListElement *next);
        ~ListElement() {}
        std::string value;
        ListElement *next;
    };

    ListElement *head;
};

