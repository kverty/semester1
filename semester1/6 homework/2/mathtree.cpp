#include <iostream>
#include <stdio.h>
#include "mathtree.h"
#include "digits.h"

using std::cout;

const int nameSize = 100;

struct Tree
{
    TreeElement *root;
};

struct TreeElement
{
    char operation;
    int value;
    TreeElement *left;
    TreeElement *right;
};

Tree *createTree()
{
    Tree *tree = new Tree;
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

void deleteTree(Tree* tree)
{
    deleteTree(tree->root);
    delete tree;
}

TreeElement *createElement(char value)
{
    TreeElement *element = new TreeElement;
    element->left = nullptr;
    element->right = nullptr;
    element->operation = value;
    element->value = 0;
    return element;
}

TreeElement *createElement(int value)
{
    TreeElement *element = new TreeElement;
    element->left = nullptr;
    element->right = nullptr;
    element->operation = '\n';
    element->value = value;
    return element;
}

int readNumber(FILE *file, int startValue)
{
    int newValue = startValue;
    while (true)
    {
        char symbol;
        fscanf(file, "%c", &symbol);
        if (!isDigit(symbol))
            break;
        newValue = newValue * 10 + (symbol - '0');
    }
    return newValue;
}

void readTree(TreeElement* &element, FILE *file)
{
    char symbol;
    fscanf(file, "%c", &symbol);

    if (isDigit(symbol))
    {
        element = createElement(readNumber(file, (symbol - '0')));
        return;
    }

    if (symbol == '-')
    {
        char symbol2;
        fscanf(file, "%c", &symbol2);
        if (isDigit(symbol2))
        {
            element = createElement(-readNumber(file, (symbol2 - '0')));
            return;
        }
    }

    if (isOperation(symbol))
    {
        element = createElement(symbol);
        readTree(element->left, file);
        readTree(element->right, file);
    }
    else if (symbol != '\n')
    {
       readTree(element, file);
    }
}

Tree *readTree()
{
    Tree *newTree = createTree();
    char filename[nameSize] = {'\0'};

    printf("Please, enter the filename : \n");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL)
        cout << "There is no such file!\n";
    else
        readTree(newTree->root, file);
    fclose(file);
    return newTree;
}

void printElement(TreeElement *element)
{
    if (element->operation == '\n')
        cout << " " << element->value;
    else
    {
        cout << " (" << element->operation;
        printElement(element->left);
        printElement(element->right);
        cout << ")";
    }
}

void printTree(Tree *tree)
{
    printElement(tree->root);
}

int countValueOfTree(TreeElement *element)
{
    if (element->operation == '\n')
        return element->value;
    if (element->operation == '+')
        return countValueOfTree(element->left) + countValueOfTree(element->right);
    if (element->operation == '*')
        return countValueOfTree(element->left) * countValueOfTree(element->right);
    if (element->operation == '-')
        return countValueOfTree(element->left) - countValueOfTree(element->right);
    if (countValueOfTree(element->right) == 0)
    {
        cout << "Division by zero!!\nAnswer is incorrect\n";
        return 42;
    }
    return countValueOfTree(element->left) / countValueOfTree(element->right);
}

int countValueOfTree(Tree *tree)
{
    return countValueOfTree(tree->root);
}

