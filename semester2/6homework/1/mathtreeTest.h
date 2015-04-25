#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>

#include "mathtree.h"

class MathtreeTest : public QObject
{
    Q_OBJECT
public:
    explicit MathtreeTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    void testMathTree()
    {
        char filename[13] = "testfile.txt";
        FILE *fileW = fopen(filename, "w");

        fprintf(fileW, "+ 1 (* 2 3)\n");

        fclose(fileW);

        MathTree *tree = new MathTree();

        FILE *file = fopen(filename, "r");
        tree->readFromFile(file);
        fclose(file);

        QVERIFY(tree->count() == 7);

        delete tree;
    }
};
