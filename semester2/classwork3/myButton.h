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
        timer(new QTimer())
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

private:
    QString mNumber;
    QPushButton *pushButton;
    QTimer *timer;

signals:
    void clicked();

public slots:
    /// works when we don't guess
    void enable()
    {
        pushButton->setText("");
        timer->stop();
    }
};
