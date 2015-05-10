#include "xsandos.h"
#include "ui_xsandos.h"

XsAndOs::XsAndOs(int size, QWidget *parent) : QMainWindow(parent), ui(new Ui::XsAndOs), size(size)
{
    ui->setupUi(this);

    symbolsInTheRow = 1;
    if (size == 2)
        symbolsInTheRow =2;
    else if (size == 3)
        symbolsInTheRow = 3;
    else if (size == 4 || size == 5)
        symbolsInTheRow = 4;
    else
        symbolsInTheRow = 5;

    QPushButton *pushButton;
    QGridLayout *gridLayout = new QGridLayout;
    field = new MyButton* *[size];

    whoseTurn = new QLineEdit("X turn");

    for (int i = 0; i < size; i++)
    {
        field[i] = new MyButton*[size];
        for (int j = 0; j < size; j++)
        {
            pushButton = new QPushButton(".");
            field[i][j] = new MyButton(pushButton);
            gridLayout->addWidget(pushButton, i, j);
            connect(pushButton, SIGNAL(clicked()), field[i][j], SLOT(changeSymbol()));
            connect(field[i][j], SIGNAL(clickedCorrectly()), this, SLOT(changeWhoseTurn()));
            connect(field[i][j], SIGNAL(clickedCorrectly()), this, SLOT(check()));
        }
    }

    for (int i = 0; i < size * size; i++)
        for (int j = 0; j < size * size; j++)
            connect(field[i % size][i / size], SIGNAL(clickedCorrectly()), field[j % size][j / size], SLOT(nextTurn()));

    //gridLayout->addWidget(rules, size + 1, 1);
    gridLayout->addWidget(whoseTurn, size + 1, size - 1);

    ui->centralWidget->setLayout(gridLayout);

    QString str;
    QLineEdit *rules = new QLineEdit("Click on buttons to write O or X\nTo win you need to get " + str.setNum(symbolsInTheRow) + " in line.");
    rules->resize(500, 20);
    rules->show();
}

XsAndOs::~XsAndOs()
{
    delete ui;
}

void XsAndOs::changeWhoseTurn()
{
    QString str = "X turn";
    if (str == whoseTurn->text())
        whoseTurn->setText("O turn");
    else
        whoseTurn->setText("X turn");
}

void XsAndOs::check()
{
    for (int i = 0; i <= size - symbolsInTheRow; i++)
        for (int j = 0; j <= size - symbolsInTheRow; j++)
        {
            bool allAreEqual = true;
            if (field[i][j]->symbol() == ".")
                continue;
            for (int k = 1; k < symbolsInTheRow; k++)
                allAreEqual = allAreEqual && (field[i + k][j + k]->symbol() == field[i][j]->symbol());
            if (allAreEqual)
            {
                finishGame();
                return;
            }
        }
    for (int i = 0; i < size; i++)
        for (int j = 0; j <= size - symbolsInTheRow; j++)
        {
            if (field[i][j]->symbol() == ".")
                continue;
            bool allAreEqual = true;
            for (int k = 1; k < symbolsInTheRow; k++)
                allAreEqual = allAreEqual && (field[i][j + k]->symbol() == field[i][j]->symbol());
            if (allAreEqual)
            {
                finishGame();
                return;
            }
        }
    for (int i = 0; i <= size - symbolsInTheRow; i++)
        for (int j = 0; j < size; j++)
        {
            if (field[i][j]->symbol() == ".")
                continue;
            bool allAreEqual = true;
            for (int k = 1; k < symbolsInTheRow; k++)
                allAreEqual = allAreEqual && (field[i + k][j]->symbol() == field[i][j]->symbol());
            if (allAreEqual)
            {
                finishGame();
                return;
            }
        }

    for (int i = symbolsInTheRow - 1; i < size; i++)
        for (int j = 0; j <= size - symbolsInTheRow; j++)
        {
            if (field[i][j]->symbol() == ".")
                continue;
            bool allAreEqual = true;
            for (int k = 1; k < symbolsInTheRow; k++)
                allAreEqual = allAreEqual && (field[i - k][j + k]->symbol() == field[i][j]->symbol());
            if (allAreEqual)
            {
                finishGame();
                return;
            }
        }
}

void XsAndOs::finishGame()
{
    QString str = "X turn";
    if (str == whoseTurn->text())
        whoseTurn->setText("O win");
    else
        whoseTurn->setText("X win");

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            field[i][j]->finishGame();
        }
    }
}

void MyButton::changeSymbol()
{
    if (!mWasClicked)
    {
        mWasClicked = true;
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
