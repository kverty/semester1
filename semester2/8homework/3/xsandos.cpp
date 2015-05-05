#include "xsandos.h"
#include "ui_xsandos.h"

XsAndOs::XsAndOs(int size, QWidget *parent) : QMainWindow(parent), ui(new Ui::XsAndOs), size(size)
{
    ui->setupUi(this);

    QPushButton *pushButtons[size * size];
    QGridLayout *gridLayout = new QGridLayout;
    MyButton *field[size * size];

    for (int i = 0; i < size * size; i++)
    {
        pushButtons[i] = new QPushButton(".");
        field[i] = new MyButton(pushButtons[i]);
        gridLayout->addWidget(pushButtons[i], i / size, i % size);
        connect(pushButtons[i], SIGNAL(clicked()), field[i], SLOT(changeSymbol()));
    }

    for (int i = 0; i < size * size; i++)
        for (int j = 0; j < size * size; j++)
            connect(field[i], SIGNAL(clickedCorrectly()), field[j], SLOT(nextTurn()));

    ui->centralWidget->setLayout(gridLayout);
}

XsAndOs::~XsAndOs()
{
    delete ui;
}

void MyButton::changeSymbol()
{
    if (!wasClicked)
    {
        wasClicked = true;
        if (turn % 2 == 0)
        {
            pushButton->setText("X");
        }
        else
        {
            pushButton->setText("O");
        }

        emit clickedCorrectly();
    }
}

void  MyButton::nextTurn()
{
    turn++;
}
