#pragma once

#include <QMainWindow>
#include <QSignalMapper>
#include <QLineEdit>
#include <QString>
#include <QChar>
#include "simpleCalculator.h"

namespace Ui {
class Calculator;
}

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    explicit Calculator(QWidget *parent = 0);
    ~Calculator();

private:
    Ui::Calculator *ui;
    QSignalMapper *buttons;
    /// expression that enters user, updates each time user pushes button
    QString expression;
    /// shows if there is error in expression
    bool hasError;

private slots:
    /// slot that is used each time user pushes the button
    void newChar(int symbol);
};

