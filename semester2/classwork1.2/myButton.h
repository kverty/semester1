#pragma once

#include <QObject>
#include <QPushButton>
#include <QString>
//#include "binaryArray.h"

/// each button have its number and connections with other buttons
class MyButton : public QObject
{
    Q_OBJECT

public:
    MyButton(QPushButton *pushButton, QString number) : mNumber(number), pushButton(pushButton), mWasClicked(false)
    {
        connect(pushButton, SIGNAL(clicked()), this, SLOT(clicked()));
    }
    ~MyButton()
    {
        delete pushButton;
    }

private:
    QString mNumber;
    QPushButton *pushButton;
    bool mWasClicked;

signals:
    void clicked(QString mNumber);
    void guessed();
    void notGuessed();

public slots:
    /// works when we guess
    void disable()
    {
        if (mWasClicked)
        {
            mWasClicked = false;
            pushButton->setDisabled(false);
        }
    }
    /// works when we don't guess
    void enable()
    {
        if (mWasClicked)
        {
            mWasClicked = false;
            pushButton->setText(" ");
        }
    }

    /// works when we click button
    void clicked()
    {
        if (!mWasClicked)
        {
            mWasClicked = true;
            pushButton->setText(mNumber);
            emit clicked(mNumber);
        }
    }

    /// works when another button is clicked and if this is clicked then we compare the numbers
    void compare(QString secondNumber)
    {
        if (mWasClicked)
        {
            if (secondNumber == mNumber)
            {
                pushButton->setText(mNumber);
                pushButton->setDisabled(false);
                mWasClicked = false;
                emit guessed();
            }
            else
            {
                pushButton->setText(" ");
                mWasClicked = false;
                emit notGuessed();
            }
        }
    }
};
