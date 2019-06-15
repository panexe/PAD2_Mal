#ifndef NEWBOOKINGDIALOG_H
#define NEWBOOKINGDIALOG_H

#include <QDialog>
#include <travelagency.h>

namespace Ui {
class NewBookingDialog;
}

class NewBookingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewBookingDialog(QWidget *parent = nullptr);
    ~NewBookingDialog();

    void setTravelAgency(TravelAgency *value);

private slots:
    void on_comboBox_currentIndexChanged(int index);

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::NewBookingDialog *ui;
    TravelAgency *travelAgency;

    char type;
    double price;
    std::string start;
    std::string end;
    long travelId;
    std::vector<std::string> bookingDetails;

};

#endif // NEWBOOKINGDIALOG_H
