#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newbookingdialog.h"
#include <QMessageBox>
#include <iostream>
#include <flightbooking.h>
#include <hotelbooking.h>
#include <rentalcarreservation.h>
#include "test.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->travelAgency = new TravelAgency();
    this->tableModel.setTravelAgency(this->travelAgency);


    ui->setupUi(this);
    ui->tableView->setModel(&tableModel);


}

MainWindow::~MainWindow()
{
    delete ui;
    delete travelAgency;
}

void MainWindow::on_actionDatei_einlesen_triggered()
{
    std::string s = this->travelAgency->readFile();
    if(s == "Fehlerhates einlesen"){
        return;
    }

    //std::cerr << s;
    this->tableModel.refresh();
    ui->tableView->update();

    QMessageBox::information(nullptr,QString("Einlesen erfolgreich"),QString::fromStdString(s));
    ui->actionDatei_einlesen->setEnabled(false);


}

void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)
{
    Booking* booking = this->travelAgency->getBooking(index.row());
    //ui->bookingNummer->setText(QString::number(booking->getId()));
    std::string fromDate= booking->getFromDate();
    std::string toDate = booking->getToDate();

    int year_from = stoi(fromDate.substr(0,4));
    int month_from = stoi(fromDate.substr(4,2));
    int day_from = stoi(fromDate.substr(6,2));
    int year_to = stoi(toDate.substr(0,4));
    int month_to = stoi(toDate.substr(4,2));
    int day_to = stoi(toDate.substr(6,2));

    std::cerr << year_from <<std::endl;
    std::cerr << month_from <<std::endl;
    std::cerr << day_from <<std::endl;

    ui->calendarWidget_from->setSelectedDate(QDate(year_from,month_from,day_from));
    ui->calendarWidget_to->setSelectedDate(QDate(year_to,month_to,day_to));

    ui->spinbox_preis->setValue(booking->getPrice());
    ui->spinbox_reise->setValue(booking->getTravelID());
    std::string kundenname = travelAgency->findCustomer(travelAgency->findTravel(booking->getTravelID())->getCustomerId())->getName();
    ui->line_kunde->setText(QString::fromStdString(kundenname));

    if(dynamic_cast<FlightBooking*>(booking)){
        FlightBooking* fb = dynamic_cast<FlightBooking*>(booking);

        ui->label_detail1->setText("Abflugdestination");
        ui->label_detail2->setText("Zieldestination");
        ui->label_detail3->setText("Sitzplatzreferenz");
        ui->label_detail4->setVisible(false);

        ui->line_detail1->setText(QString::fromStdString(fb->getFromDest()));
        ui->line_detail2->setText(QString::fromStdString(fb->getToDest()));
        ui->line_detail3->setText(QString(fb->getSeatPref()));
        ui->line_detail3->setText(QString::fromStdString(fb->showDetails()));

        ui->line_detail4->setVisible(false);



    }else if (dynamic_cast<HotelBooking*>(booking)) {
        ui->label_detail4->setVisible(false);
        ui->line_detail4->setVisible(false);

        HotelBooking* hb = dynamic_cast<HotelBooking*>(booking);

        ui->label_detail1->setText("Hotel");
        ui->label_detail2->setText("Stadt");
        ui->label_detail3->setText("Rauchen");

        ui->line_detail1->setText(QString::fromStdString(hb->getHotel()));
        ui->line_detail2->setText(QString::fromStdString(hb->getTown()));
        std::string text = hb->getSmoke() == true ? "Gestattet" : "Verboten";
        //ui->line_detail3->setText(QString::fromStdString(text));
        ui->line_detail3->setText(QString::fromStdString(hb->showDetails()));


    }else if (dynamic_cast<RentalCarReservation*>(booking)) {
        ui->label_detail4->setVisible(true);
        ui->line_detail4->setVisible(true);

        RentalCarReservation * rc = dynamic_cast<RentalCarReservation*>(booking);


        ui->label_detail1->setText("Autovermietung");
        ui->label_detail2->setText("Abholstation");
        ui->label_detail3->setText("Rueckgabestation");
        ui->label_detail4->setText("Versicherung");


        ui->line_detail1->setText(QString::fromStdString(rc->getCompany()));
        ui->line_detail2->setText(QString::fromStdString(rc->getPickupLocation()));
        ui->line_detail3->setText(QString::fromStdString(rc->getReturnLocation()));
        //ui->line_detail4->setText(QString::fromStdString(rc->getInsuranceType()));
        ui->line_detail4->setText(QString::fromStdString(rc->showDetails()));


    }



}

void MainWindow::on_actionBuchung_anlegen_triggered()
{
    NewBookingDialog* n = new NewBookingDialog();
    n->setTravelAgency(this->travelAgency);
    //n->show();
    n->exec();
    this->tableModel.refresh();
    ui->tableView->update();


}

void MainWindow::on_actionRefresh_triggered()
{
    this->tableModel.refresh();
    ui->tableView->update();

}

void MainWindow::on_actionTextdatei_Erstellen_triggered()
{
    std::string txtFileContent = this->travelAgency->toFileString();

    QString fileName = QFileDialog::getSaveFileName(this,"Save as");
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this,"Warning", "Datei konnte nicht gespeichert werden!"+file.errorString());
        return;
    }
    QTextStream out(&file);
    QString text = QString::fromStdString(txtFileContent);
    out << text;
    file.close();

}
