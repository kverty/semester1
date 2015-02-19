#pragma once

struct AVLTree;
struct TreeElement;

AVLTree *createTree();
void deleteTree(AVLTree *tree);
TreeElement *createElement(int value, int height);
void addElement(AVLTree* &tree, int value);
void deleteElementInTree(AVLTree *&tree, int value);
bool wasFound(AVLTree* tree, int value);
void ascendingPrint(AVLTree *tree);
void descendingPrint(AVLTree* tree);
void printTree(AVLTree *tree);
