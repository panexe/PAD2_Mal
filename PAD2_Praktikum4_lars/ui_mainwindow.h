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
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionDatei_einlesen;
    QAction *actionBuchung_anlegen;
    QAction *actionRefresh;
    QAction *actionTextdatei_Erstellen;
    QWidget *centralWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_3;
    QLabel *label_detail1;
    QLabel *label_detail2;
    QLabel *label_detail4;
    QLabel *label_detail3;
    QLineEdit *line_detail4;
    QLineEdit *line_detail1;
    QLineEdit *line_detail3;
    QLineEdit *line_detail2;
    QGridLayout *gridLayout_2;
    QSpinBox *spinbox_reise;
    QLabel *label_kunde;
    QDoubleSpinBox *spinbox_preis;
    QLineEdit *line_kunde;
    QLabel *label_reise;
    QLabel *label_preis;
    QCalendarWidget *calendarWidget_to;
    QLabel *Label_const;
    QCalendarWidget *calendarWidget_from;
    QTableView *tableView;
    QMenuBar *menuBar;
    QMenu *menuFunktionen;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1036, 930);
        actionDatei_einlesen = new QAction(MainWindow);
        actionDatei_einlesen->setObjectName(QString::fromUtf8("actionDatei_einlesen"));
        actionBuchung_anlegen = new QAction(MainWindow);
        actionBuchung_anlegen->setObjectName(QString::fromUtf8("actionBuchung_anlegen"));
        actionRefresh = new QAction(MainWindow);
        actionRefresh->setObjectName(QString::fromUtf8("actionRefresh"));
        actionTextdatei_Erstellen = new QAction(MainWindow);
        actionTextdatei_Erstellen->setObjectName(QString::fromUtf8("actionTextdatei_Erstellen"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 1021, 871));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetMaximumSize);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_detail1 = new QLabel(gridLayoutWidget);
        label_detail1->setObjectName(QString::fromUtf8("label_detail1"));

        gridLayout_3->addWidget(label_detail1, 1, 0, 1, 1);

        label_detail2 = new QLabel(gridLayoutWidget);
        label_detail2->setObjectName(QString::fromUtf8("label_detail2"));

        gridLayout_3->addWidget(label_detail2, 2, 0, 1, 1);

        label_detail4 = new QLabel(gridLayoutWidget);
        label_detail4->setObjectName(QString::fromUtf8("label_detail4"));

        gridLayout_3->addWidget(label_detail4, 4, 0, 1, 1);

        label_detail3 = new QLabel(gridLayoutWidget);
        label_detail3->setObjectName(QString::fromUtf8("label_detail3"));

        gridLayout_3->addWidget(label_detail3, 3, 0, 1, 1);

        line_detail4 = new QLineEdit(gridLayoutWidget);
        line_detail4->setObjectName(QString::fromUtf8("line_detail4"));

        gridLayout_3->addWidget(line_detail4, 4, 1, 1, 1);

        line_detail1 = new QLineEdit(gridLayoutWidget);
        line_detail1->setObjectName(QString::fromUtf8("line_detail1"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(line_detail1->sizePolicy().hasHeightForWidth());
        line_detail1->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(line_detail1, 1, 1, 1, 1);

        line_detail3 = new QLineEdit(gridLayoutWidget);
        line_detail3->setObjectName(QString::fromUtf8("line_detail3"));

        gridLayout_3->addWidget(line_detail3, 3, 1, 1, 1);

        line_detail2 = new QLineEdit(gridLayoutWidget);
        line_detail2->setObjectName(QString::fromUtf8("line_detail2"));

        gridLayout_3->addWidget(line_detail2, 2, 1, 1, 1);


        gridLayout->addLayout(gridLayout_3, 4, 2, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        spinbox_reise = new QSpinBox(gridLayoutWidget);
        spinbox_reise->setObjectName(QString::fromUtf8("spinbox_reise"));
        spinbox_reise->setMaximum(100000);

        gridLayout_2->addWidget(spinbox_reise, 0, 1, 1, 1);

        label_kunde = new QLabel(gridLayoutWidget);
        label_kunde->setObjectName(QString::fromUtf8("label_kunde"));

        gridLayout_2->addWidget(label_kunde, 5, 0, 1, 1);

        spinbox_preis = new QDoubleSpinBox(gridLayoutWidget);
        spinbox_preis->setObjectName(QString::fromUtf8("spinbox_preis"));
        spinbox_preis->setMaximum(100000000.000000000000000);

        gridLayout_2->addWidget(spinbox_preis, 3, 1, 1, 1);

        line_kunde = new QLineEdit(gridLayoutWidget);
        line_kunde->setObjectName(QString::fromUtf8("line_kunde"));

        gridLayout_2->addWidget(line_kunde, 5, 1, 1, 1);

        label_reise = new QLabel(gridLayoutWidget);
        label_reise->setObjectName(QString::fromUtf8("label_reise"));

        gridLayout_2->addWidget(label_reise, 0, 0, 1, 1);

        label_preis = new QLabel(gridLayoutWidget);
        label_preis->setObjectName(QString::fromUtf8("label_preis"));

        gridLayout_2->addWidget(label_preis, 3, 0, 1, 1);


        gridLayout->addLayout(gridLayout_2, 4, 3, 1, 1);

        calendarWidget_to = new QCalendarWidget(gridLayoutWidget);
        calendarWidget_to->setObjectName(QString::fromUtf8("calendarWidget_to"));

        gridLayout->addWidget(calendarWidget_to, 0, 3, 1, 1);

        Label_const = new QLabel(gridLayoutWidget);
        Label_const->setObjectName(QString::fromUtf8("Label_const"));
        Label_const->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(Label_const, 2, 2, 1, 1);

        calendarWidget_from = new QCalendarWidget(gridLayoutWidget);
        calendarWidget_from->setObjectName(QString::fromUtf8("calendarWidget_from"));

        gridLayout->addWidget(calendarWidget_from, 1, 3, 1, 1);

        tableView = new QTableView(gridLayoutWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        gridLayout->addWidget(tableView, 0, 2, 2, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1036, 21));
        menuFunktionen = new QMenu(menuBar);
        menuFunktionen->setObjectName(QString::fromUtf8("menuFunktionen"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFunktionen->menuAction());
        menuFunktionen->addAction(actionDatei_einlesen);
        menuFunktionen->addAction(actionBuchung_anlegen);
        menuFunktionen->addAction(actionRefresh);
        menuFunktionen->addAction(actionTextdatei_Erstellen);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionDatei_einlesen->setText(QApplication::translate("MainWindow", "Datei einlesen", nullptr));
        actionBuchung_anlegen->setText(QApplication::translate("MainWindow", "Buchung anlegen", nullptr));
        actionRefresh->setText(QApplication::translate("MainWindow", "Refresh", nullptr));
        actionTextdatei_Erstellen->setText(QApplication::translate("MainWindow", "Textdatei Erstellen", nullptr));
        label_detail1->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        label_detail2->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        label_detail4->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        label_detail3->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        label_kunde->setText(QApplication::translate("MainWindow", "Kunde", nullptr));
        label_reise->setText(QApplication::translate("MainWindow", "Reise", nullptr));
        label_preis->setText(QApplication::translate("MainWindow", "Preis", nullptr));
        Label_const->setText(QApplication::translate("MainWindow", "Flugdetails", nullptr));
        menuFunktionen->setTitle(QApplication::translate("MainWindow", "Funktionen", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
