#include "traveldialog.h"
#include "ui_traveldialog.h"

TravelDialog::TravelDialog(QWidget *parent,TravelAgency* travelAgency_) :
    QDialog(parent),
    ui(new Ui::TravelDialog)
{
    ui->setupUi(this);
    this->travelAgency = travelAgency_;
    this->tableModel.setTravelAgency(travelAgency);

    ui->tableView->setModel(&tableModel);
}

TravelDialog::~TravelDialog()
{
    delete ui;
}

void TravelDialog::on_tableView_doubleClicked(const QModelIndex &index)
{
    int a = 0;
}
