/********************************************************************************
** Form generated from reading UI file 'findpair.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDPAIR_H
#define UI_FINDPAIR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FindPair
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *FindPair)
    {
        if (FindPair->objectName().isEmpty())
            FindPair->setObjectName(QStringLiteral("FindPair"));
        FindPair->resize(400, 300);
        menuBar = new QMenuBar(FindPair);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        FindPair->setMenuBar(menuBar);
        mainToolBar = new QToolBar(FindPair);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        FindPair->addToolBar(mainToolBar);
        centralWidget = new QWidget(FindPair);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        FindPair->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(FindPair);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        FindPair->setStatusBar(statusBar);

        retranslateUi(FindPair);

        QMetaObject::connectSlotsByName(FindPair);
    } // setupUi

    void retranslateUi(QMainWindow *FindPair)
    {
        FindPair->setWindowTitle(QApplication::translate("FindPair", "FindPair", 0));
    } // retranslateUi

};

namespace Ui {
    class FindPair: public Ui_FindPair {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDPAIR_H
