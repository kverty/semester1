#pragma once

struct BinaryTree;
struct TreeElement;

BinaryTree *createTree();
void deleteTree(BinaryTree *tree);
TreeElement *createElement(int value);
void addElement(BinaryTree* &tree, int value);
void deleteElementInTree(BinaryTree* &tree, int value);
bool wasFound(BinaryTree* tree, int value);
void ascendingPrint(BinaryTree* tree);
void descendingPrint(BinaryTree* tree);
void printTree(BinaryTree* tree);
