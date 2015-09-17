#pragma once

#include <QObject>
#include <QPushButton>
#include <QString>
#include <QTimer>

/// each button have its number and connections with other buttons
class MyButton : public QObject
{
    Q_OBJECT

public:
    MyButton(QPushButton *pushButton, QString number) : mNumber(number), pushButton(pushButton),
        timer(new QTimer()), mWasClicked(false)
    {
        connect(pushButton, SIGNAL(clicked()), this, SIGNAL(clicked()));
        connect(timer, SIGNAL(timeout()), this, SLOT(enable()));
    }
    ~MyButton()
    {
        delete pushButton;
    }

    void show()
    {
        pushButton->setText(mNumber);
        mWasClicked = true;
    }

    QString number()
    {
        return mNumber;
    }

    /// works when we guess
    void disable()
    {
        pushButton->setText(mNumber);
        pushButton->setEnabled(false);
    }

    void startTimer()
    {
        timer->start(400);
    }

    bool wasClicked()
    {
        return mWasClicked;
    }

private:
    QString mNumber;
    QPushButton *pushButton;
    QTimer *timer;
    bool mWasClicked;

signals:
    void clicked();

public slots:
    /// works when we don't guess
    void enable()
    {
        mWasClicked = false;
        pushButton->setText("");
        timer->stop();
    }
};
