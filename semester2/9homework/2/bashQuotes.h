#pragma once
#include <QMainWindow>
#include <QWebElement>
#include <QWebView>
#include <QWebPage>
#include <QWebFrame>
#include <QLabel>

namespace Ui {
class BashQuotes;
}

class BashQuotes : public QMainWindow
{
    Q_OBJECT

public:
    explicit BashQuotes(QWidget *parent = 0);
    ~BashQuotes();

private slots:
    void showNextQuote();
    void makeQuoteList();

private:
    Ui::BashQuotes *ui;
    QWebView *bashPage;
    QList<QWebElement> quoteList;
    int numberCurrentQuote;
};
