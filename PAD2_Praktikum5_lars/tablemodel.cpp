#include "tablemodel.h"

void TableModel::setTravelAgency(TravelAgency *value)
{
    travelAgency = value;
}

void TableModel::refresh()
{
    emit dataChanged(index(0,0),index(rowCount(),columnCount()));
    emit layoutChanged();
}

TableModel::TableModel(QObject *parent, TravelAgency* travelAgency_) : QAbstractTableModel (parent), travelAgency(travelAgency_)
{



}

int TableModel::rowCount(const QModelIndex &parent) const
{
    return this->travelAgency->getBookingsSize();

}

int TableModel::columnCount(const QModelIndex &parent) const
{
    return 5;
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal){
        switch(section){
        case 0:
            return QString("Buchungsdaten");
        case 1:
            return QString("Preis");
        case 2:
            return QString("Kunde");
        case 3:
            return QString("Reisenummer");
        case 4:
            return QString("Roundtrip");

        }
    }

    return QVariant();
}

QVariant TableModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole){
        switch(index.column()){
        case 0:
            return QString::number(this->travelAgency->getBooking(index.row())->getId());
        case 1:
            return QString::number(this->travelAgency->getBooking(index.row())->getPrice());
        case 2:
            return QString::fromStdString(this->travelAgency->findCustomer(
                                              this->travelAgency->findTravel(
                                                  this->travelAgency->getBooking(index.row())->getTravelID()
                                                  )->getCustomerId())->getName());
        case 3:
            return QString::number(this->travelAgency->getBooking(index.row())->getTravelID());


        }


    }

    return QVariant();

}

