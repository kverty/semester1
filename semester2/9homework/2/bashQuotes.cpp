#include "bashQuotes.h"
#include "ui_bashQuotes.h"
#include <iostream>

BashQuotes::BashQuotes(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BashQuotes),
    bashPage(new QWebView(parent))
{
    ui->setupUi(this);
    bashPage->load(QUrl("http://bash.im/"));
    ui->nextButton->setEnabled(false);
    connect(ui->nextButton, SIGNAL(clicked()), this, SLOT(showNextQuote()));
    connect(bashPage, SIGNAL(loadFinished(bool)), this, SLOT(makeQuoteList()));
}

BashQuotes::~BashQuotes()
{
    delete ui;
    delete bashPage;
}

void BashQuotes::showNextQuote()
{
    ui->quote->clear();
    ui->rating->clear();

    while(quoteList[numberCurrentQuote].findFirst("div[class=text]").toPlainText().isEmpty())
        numberCurrentQuote = (numberCurrentQuote + 1) % quoteList.length();

    ui->quote->insertPlainText(quoteList[numberCurrentQuote].findFirst("div[class=text]").toPlainText());
    ui->rating->insertPlainText(quoteList[numberCurrentQuote].findFirst("span[class=rating]").toPlainText());
    numberCurrentQuote = (numberCurrentQuote + 1) % quoteList.length();
}

void BashQuotes::makeQuoteList()
{
    quoteList = bashPage->page()->mainFrame()->findAllElements("div[class=quote]").toList();
    numberCurrentQuote = 0;
    ui->nextButton->setEnabled(true);
    showNextQuote();
}

