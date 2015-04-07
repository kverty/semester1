#include <QtCore/QObject>
#include <QtTest/QTest>

#include "expressions.h"
#include <time.h>

class TokenTest : public QObject
{
   Q_OBJECT
public:
   explicit TokenTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    ///test for constructor and two methods, that returns parameters of token
    void testToken()
    {
        srand(time(NULL));
        int x = rand() % testSize;
        Token *token = new Token(x, number);

        QVERIFY(token->mNumber() == x);
        QVERIFY(token->mType() == number);

        delete token;
    }
private:
    int testSize = 10;
};
