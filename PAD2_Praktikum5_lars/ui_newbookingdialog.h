/********************************************************************************
** Form generated from reading UI file 'newbookingdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWBOOKINGDIALOG_H
#define UI_NEWBOOKINGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewBookingDialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QDoubleSpinBox *input_price;
    QSpinBox *reise_id_input;
    QDateEdit *fromDate_input;
    QDateEdit *to_date_input;
    QComboBox *comboBox;
    QLineEdit *change_box1;
    QLineEdit *change_box2;
    QLineEdit *change_box3;
    QLineEdit *change_box3_2;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_3;
    QLabel *label_6;
    QLabel *change_label1;
    QLabel *change_label2;
    QLabel *change_label3;
    QLabel *change_label4;

    void setupUi(QDialog *NewBookingDialog)
    {
        if (NewBookingDialog->objectName().isEmpty())
            NewBookingDialog->setObjectName(QString::fromUtf8("NewBookingDialog"));
        NewBookingDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(NewBookingDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        verticalLayoutWidget = new QWidget(NewBookingDialog);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(150, 10, 221, 230));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        input_price = new QDoubleSpinBox(verticalLayoutWidget);
        input_price->setObjectName(QString::fromUtf8("input_price"));

        verticalLayout->addWidget(input_price);

        reise_id_input = new QSpinBox(verticalLayoutWidget);
        reise_id_input->setObjectName(QString::fromUtf8("reise_id_input"));

        verticalLayout->addWidget(reise_id_input);

        fromDate_input = new QDateEdit(verticalLayoutWidget);
        fromDate_input->setObjectName(QString::fromUtf8("fromDate_input"));

        verticalLayout->addWidget(fromDate_input);

        to_date_input = new QDateEdit(verticalLayoutWidget);
        to_date_input->setObjectName(QString::fromUtf8("to_date_input"));

        verticalLayout->addWidget(to_date_input);

        comboBox = new QComboBox(verticalLayoutWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        verticalLayout->addWidget(comboBox);

        change_box1 = new QLineEdit(verticalLayoutWidget);
        change_box1->setObjectName(QString::fromUtf8("change_box1"));

        verticalLayout->addWidget(change_box1);

        change_box2 = new QLineEdit(verticalLayoutWidget);
        change_box2->setObjectName(QString::fromUtf8("change_box2"));

        verticalLayout->addWidget(change_box2);

        change_box3 = new QLineEdit(verticalLayoutWidget);
        change_box3->setObjectName(QString::fromUtf8("change_box3"));

        verticalLayout->addWidget(change_box3);

        change_box3_2 = new QLineEdit(verticalLayoutWidget);
        change_box3_2->setObjectName(QString::fromUtf8("change_box3_2"));

        verticalLayout->addWidget(change_box3_2);

        verticalLayoutWidget_2 = new QWidget(NewBookingDialog);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(9, 9, 141, 231));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget_2);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(verticalLayoutWidget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        label_4 = new QLabel(verticalLayoutWidget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_2->addWidget(label_4);

        label_3 = new QLabel(verticalLayoutWidget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);

        label_6 = new QLabel(verticalLayoutWidget_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_2->addWidget(label_6);

        change_label1 = new QLabel(verticalLayoutWidget_2);
        change_label1->setObjectName(QString::fromUtf8("change_label1"));

        verticalLayout_2->addWidget(change_label1);

        change_label2 = new QLabel(verticalLayoutWidget_2);
        change_label2->setObjectName(QString::fromUtf8("change_label2"));

        verticalLayout_2->addWidget(change_label2);

        change_label3 = new QLabel(verticalLayoutWidget_2);
        change_label3->setObjectName(QString::fromUtf8("change_label3"));

        verticalLayout_2->addWidget(change_label3);

        change_label4 = new QLabel(verticalLayoutWidget_2);
        change_label4->setObjectName(QString::fromUtf8("change_label4"));

        verticalLayout_2->addWidget(change_label4);


        retranslateUi(NewBookingDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), NewBookingDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NewBookingDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(NewBookingDialog);
    } // setupUi

    void retranslateUi(QDialog *NewBookingDialog)
    {
        NewBookingDialog->setWindowTitle(QApplication::translate("NewBookingDialog", "Dialog", nullptr));
        input_price->setSuffix(QApplication::translate("NewBookingDialog", " Euro", nullptr));
        comboBox->setItemText(0, QApplication::translate("NewBookingDialog", "Flugbuchung", nullptr));
        comboBox->setItemText(1, QApplication::translate("NewBookingDialog", "Hotelbuchung", nullptr));
        comboBox->setItemText(2, QApplication::translate("NewBookingDialog", "Autoreservierung", nullptr));

        label->setText(QApplication::translate("NewBookingDialog", "Preis", nullptr));
        label_2->setText(QApplication::translate("NewBookingDialog", "Reise-ID", nullptr));
        label_4->setText(QApplication::translate("NewBookingDialog", "Startdatum", nullptr));
        label_3->setText(QApplication::translate("NewBookingDialog", "Enddatum", nullptr));
        label_6->setText(QApplication::translate("NewBookingDialog", "Buchungstyp", nullptr));
        change_label1->setText(QApplication::translate("NewBookingDialog", "Startflughafen", nullptr));
        change_label2->setText(QApplication::translate("NewBookingDialog", "Zielflughafen", nullptr));
        change_label3->setText(QApplication::translate("NewBookingDialog", "Fluglinie", nullptr));
        change_label4->setText(QApplication::translate("NewBookingDialog", "Sitzpr\303\244ferenz", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NewBookingDialog: public Ui_NewBookingDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWBOOKINGDIALOG_H
