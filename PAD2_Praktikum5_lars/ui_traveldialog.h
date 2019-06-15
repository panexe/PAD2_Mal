/********************************************************************************
** Form generated from reading UI file 'traveldialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRAVELDIALOG_H
#define UI_TRAVELDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_TravelDialog
{
public:
    QGridLayout *gridLayout;
    QTableView *tableView;

    void setupUi(QDialog *TravelDialog)
    {
        if (TravelDialog->objectName().isEmpty())
            TravelDialog->setObjectName(QString::fromUtf8("TravelDialog"));
        TravelDialog->resize(443, 291);
        gridLayout = new QGridLayout(TravelDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tableView = new QTableView(TravelDialog);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        gridLayout->addWidget(tableView, 0, 0, 1, 1);


        retranslateUi(TravelDialog);

        QMetaObject::connectSlotsByName(TravelDialog);
    } // setupUi

    void retranslateUi(QDialog *TravelDialog)
    {
        TravelDialog->setWindowTitle(QApplication::translate("TravelDialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TravelDialog: public Ui_TravelDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAVELDIALOG_H
