#pragma once

#include <QtCore/QObject>
#include <QtTest/QTest>

#include "computer.h"
#include <time.h>

class ComputerTest : public QObject
{
   Q_OBJECT
public:
   explicit ComputerTest(QObject *parent = 0) : QObject(parent) {}

private slots:
