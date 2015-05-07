#include "findpair.h"
#include "ui_findpair.h"

#include <time.h>

/// return binary array with even number of ones and even number of zeros
int *binaryArray(int size)
{
    int countOfOnes = 0;
    srand(time(NULL));
    int *array = new int[size * size];
    for (int i = 0; i < size - 1; i++)
    {
        array[i] = rand() % 2;
        countOfOnes += array[i];
    }

    if (countOfOnes % 2 == 1)
        array[size - 1] = 1;
    else
        array[size - 1] = 0;

    return array;
}


FindPair::FindPair(int size, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FindPair),
    size(size)
{
    ui->setupUi(this);

    QGridLayout *gridLayout = new QGridLayout;
    MyButton *field[size * size];
    QString str;

    int *numbers = binaryArray(size * size);
    for (int i = 0; i < size * size; i++)
    {
        QPushButton *newButton = new QPushButton(" ");
        gridLayout->addWidget(newButton, i / size, i % size);
        field[i] = new MyButton(newButton, str.setNum(numbers[i]));
    }

    delete[] numbers;

    for (int i = 0; i < size * size; i++)
        for (int j = 0; j < size * size; j++)
            if (i != j)
            {
                connect(field[i], SIGNAL(clicked(QString)), field[j], SLOT(compare(QString)));
                connect(field[i], SIGNAL(guessed()), field[j], SLOT(disable()));
                connect(field[i], SIGNAL(notGuessed()), field[j], SLOT(enable()));
            }

    ui->centralWidget->setLayout(gridLayout);
}

FindPair::~FindPair()
{
    delete[] field;
    delete ui;
}
