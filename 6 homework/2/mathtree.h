#pragma once

struct Tree;
struct TreeElement;

Tree *createTree();
void deleteTree(Tree *tree);
Tree *readTree();
void printTree(Tree *tree);
int countValueOfTree(Tree *tree);
