/********************************************************************************
** Form generated from reading UI file 'xsandos.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_XSANDOS_H
#define UI_XSANDOS_H

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

class Ui_XsAndOs
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *XsAndOs)
    {
        if (XsAndOs->objectName().isEmpty())
            XsAndOs->setObjectName(QStringLiteral("XsAndOs"));
        XsAndOs->resize(400, 300);
        menuBar = new QMenuBar(XsAndOs);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        XsAndOs->setMenuBar(menuBar);
        mainToolBar = new QToolBar(XsAndOs);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        XsAndOs->addToolBar(mainToolBar);
        centralWidget = new QWidget(XsAndOs);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        XsAndOs->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(XsAndOs);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        XsAndOs->setStatusBar(statusBar);

        retranslateUi(XsAndOs);

        QMetaObject::connectSlotsByName(XsAndOs);
    } // setupUi

    void retranslateUi(QMainWindow *XsAndOs)
    {
        XsAndOs->setWindowTitle(QApplication::translate("XsAndOs", "XsAndOs", 0));
    } // retranslateUi

};

namespace Ui {
    class XsAndOs: public Ui_XsAndOs {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_XSANDOS_H
