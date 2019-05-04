#include "newbookingdialog.h"
#include "ui_newbookingdialog.h"
#include <iostream>

NewBookingDialog::NewBookingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewBookingDialog)
{
    ui->setupUi(this);
    this->type = 'F';
}

NewBookingDialog::~NewBookingDialog()
{

    delete ui;
}

void NewBookingDialog::setTravelAgency(TravelAgency *value)
{
    travelAgency = value;
}

void NewBookingDialog::on_comboBox_currentIndexChanged(int index)
{
    switch(index){
    case 0:
        this->type = 'F';
        ui->change_box3->setVisible(true);
        ui->change_label3->setVisible(true);
        ui->change_label1->setText("Startflughafen");
        ui->change_label2->setText("Zielflughafen");
        ui->change_label3->setText("Fluglinie");
        break;
    case 1:
        this->type = 'H';
        ui->change_label1->setText("Hotel");
        ui->change_label2->setText("Stadt");
        ui->change_label3->setVisible(false);
        ui->change_box3->setVisible(false);
        break;
    case 2:
        this->type = 'R';
        ui->change_box3->setVisible(true);
        ui->change_label3->setVisible(true);
        ui->change_label1->setText("Pickup-Ort");
        ui->change_label2->setText("Rückgabe-Ort");
        ui->change_label3->setText("Leih-Firma");
        break;
    default:
        this->type = ' ';
    }
}

void NewBookingDialog::on_buttonBox_accepted()
{

    this->price = ui->input_price->value();
    this->travelId = ui->reise_id_input->value();
    QDate from = ui->fromDate_input->date();
    QDate to = ui->to_date_input->date();
    std::string from_month = from.month() >= 10 ? std::to_string(from.month()) : "0" + std::to_string(from.month());
    std::string from_day = from.day() >= 10 ? std::to_string(from.day()) : "0" + std::to_string(from.day());
    std::string to_month = to.month() >= 10 ? std::to_string(to.month()) : "0" + std::to_string(to.month());
    std::string to_day = to.day() >= 10 ? std::to_string(to.day()) : "0" + std::to_string(to.day());

    this->start = std::to_string(from.year()) +  from_month + from_day;
    this->end = std::to_string(to.year())+ to_month + to_day;
    std::cerr << start;
    std::cerr << end;
    this->bookingDetails.push_back(ui->change_box1->text().toStdString());
    this->bookingDetails.emplace_back(ui->change_box2->text().toStdString());
    this->bookingDetails.emplace_back(ui->change_box3->text().toStdString());

    this->travelAgency->createBooking(this->type,this->price,this->start,this->end,this->travelId,this->bookingDetails);
    this->close();


}

void NewBookingDialog::on_buttonBox_rejected()
{
    this->close();
}
