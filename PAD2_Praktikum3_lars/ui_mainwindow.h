/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionDatei_einlesen;
    QAction *actionBuchung_anlegen;
    QAction *actionRefresh;
    QWidget *centralWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QCalendarWidget *calendarWidget_from;
    QCalendarWidget *calendarWidget_to;
    QTableView *tableView;
    QLabel *bookingNummer;
    QMenuBar *menuBar;
    QMenu *menuFunktionen;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(836, 585);
        actionDatei_einlesen = new QAction(MainWindow);
        actionDatei_einlesen->setObjectName(QString::fromUtf8("actionDatei_einlesen"));
        actionBuchung_anlegen = new QAction(MainWindow);
        actionBuchung_anlegen->setObjectName(QString::fromUtf8("actionBuchung_anlegen"));
        actionRefresh = new QAction(MainWindow);
        actionRefresh->setObjectName(QString::fromUtf8("actionRefresh"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 0, 811, 531));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetMaximumSize);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        calendarWidget_from = new QCalendarWidget(gridLayoutWidget);
        calendarWidget_from->setObjectName(QString::fromUtf8("calendarWidget_from"));

        gridLayout->addWidget(calendarWidget_from, 1, 1, 1, 1);

        calendarWidget_to = new QCalendarWidget(gridLayoutWidget);
        calendarWidget_to->setObjectName(QString::fromUtf8("calendarWidget_to"));

        gridLayout->addWidget(calendarWidget_to, 2, 1, 1, 1);

        tableView = new QTableView(gridLayoutWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        gridLayout->addWidget(tableView, 0, 0, 3, 1);

        bookingNummer = new QLabel(gridLayoutWidget);
        bookingNummer->setObjectName(QString::fromUtf8("bookingNummer"));

        gridLayout->addWidget(bookingNummer, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 836, 21));
        menuFunktionen = new QMenu(menuBar);
        menuFunktionen->setObjectName(QString::fromUtf8("menuFunktionen"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFunktionen->menuAction());
        menuFunktionen->addAction(actionDatei_einlesen);
        menuFunktionen->addAction(actionBuchung_anlegen);
        menuFunktionen->addAction(actionRefresh);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionDatei_einlesen->setText(QApplication::translate("MainWindow", "Datei einlesen", nullptr));
        actionBuchung_anlegen->setText(QApplication::translate("MainWindow", "Buchung anlegen", nullptr));
        actionRefresh->setText(QApplication::translate("MainWindow", "Refresh", nullptr));
        bookingNummer->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        menuFunktionen->setTitle(QApplication::translate("MainWindow", "Funktionen", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
