#include "findpair.h"
#include "ui_findpair.h"
#include <iostream>

#include <time.h>

/// return binary array with even number of ones and even number of zeros
int *makeArray(int size, int numberOfCards)
{
    int *countOfCards = new int[numberOfCards];
    for (int i = 0; i < numberOfCards; i++)
        countOfCards[i] = 0;

    int numberOfWrong = 0;
    int i = 0;
    srand(time(NULL));
    int *array = new int[size];

    while(i < size - numberOfWrong)
    {
        array[i] = rand() % numberOfCards;
        countOfCards[array[i]]++;
        if (countOfCards[array[i]] % 2 == 0)
            numberOfWrong--;
        else
            numberOfWrong++;
        i++;
    }


    int wrongCard = 0;
    int j = 0;

    while(j < numberOfWrong)
    {
        while (countOfCards[wrongCard] % 2 == 0)
            wrongCard++;
        array[i] = wrongCard;
        countOfCards[array[i]]++;

        i++;
        wrongCard++;
        j++;
    }

    return array;
}

FindPair::FindPair(int size, int numberOfCards, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FindPair),
    size(size),
    clickedOne(nullptr),
    moves(0),
    movesLine(new QLineEdit("0 moves"))
{
    ui->setupUi(this);

    buttons = new QGridLayout;
    MyButton *field[size * size];
    QString str;

    int *numbers = makeArray(size * size, numberOfCards);
    for (int i = 0; i < size * size; i++)
    {
        QPushButton *newButton = new QPushButton(" ");
        buttons->addWidget(newButton, i / size, i % size);
        field[i] = new MyButton(newButton, str.setNum(numbers[i]));
    }

    delete[] numbers;

    for (int i = 0; i < size * size; i++)
        connect(field[i], SIGNAL(clicked()), this, SLOT(nextButton()));


    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(buttons);
    mainLayout->addWidget(movesLine);
    ui->centralWidget->setLayout(mainLayout);
}

FindPair::~FindPair()
{
    delete[] field;
    delete ui;
}

void FindPair::nextButton()
{
    MyButton *newButton = static_cast<MyButton *>(sender());

    if (clickedOne == nullptr)
    {
        newButton->show();
        clickedOne = newButton;
    }
    else
    {
        if (newButton->wasClicked())
            return;

        if (clickedOne->number() == newButton->number())
        {
            clickedOne->disable();
            newButton->disable();
        }
        else
        {
            newButton->show();
            clickedOne->startTimer();
            newButton->startTimer();
        }
        clickedOne = nullptr;
        moves++;
        QString str;
        movesLine->setText(str.setNum(moves) + " moves");
    }
}
