#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newbookingdialog.h"
#include <QMessageBox>
#include <iostream>

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
    std::cerr << s;
    this->tableModel.refresh();
    ui->tableView->update();

    QMessageBox::information(nullptr,QString("Einlesen erfolgreich"),QString::fromStdString(s));
    ui->actionDatei_einlesen->setEnabled(false);


}

void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)
{
    ui->bookingNummer->setText(QString::number(this->travelAgency->getBooking(index.row())->getId()));
    std::string fromDate= this->travelAgency->getBooking(index.row())->getFromDate();
    std::string toDate = this->travelAgency->getBooking(index.row())->getToDate();
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
