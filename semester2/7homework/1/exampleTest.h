#pragma once

#include <QtCore/QObject>
#include <QtTest/QTest>

#include "example.h"
#include <iostream>

class ExampleTest : public QObject
{
    Q_OBJECT
public:
    explicit ExampleTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    void testDestructor()
    {
        try
        {
            Example example;
            throw MyError();
        }

        catch(MyError const &)
        {
            std::cout << "Exception cought!\n";
        }
    }
};
