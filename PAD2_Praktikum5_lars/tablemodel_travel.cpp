#include "tablemodel_travel.h"


void tablemodel_travel::setTravelAgency(TravelAgency *value)
{
    travelAgency = value;
}

void tablemodel_travel::refresh()
{
    emit dataChanged(index(0,0),index(rowCount(),columnCount()));
    emit layoutChanged();
}

tablemodel_travel::tablemodel_travel(QObject *parent, TravelAgency* travelAgency_) : QAbstractTableModel (parent), travelAgency(travelAgency_)
{



}

int tablemodel_travel::rowCount(const QModelIndex &parent) const
{
    return this->travelAgency->getTravelSize();

}

int tablemodel_travel::columnCount(const QModelIndex &parent) const
{
    return 5;
}

QVariant tablemodel_travel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal){
        switch(section){
        case 0:
            return QString("TravelID");
        case 1:
            return QString("Roundtrip");
        case 2:
            return QString("Hotel fehlt");
        case 3:
            return QString("Hotel zuviel");
        case 4:
            return QString("Auto zuviel");

        }
    }

    return QVariant();
}

QVariant tablemodel_travel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole){
        switch(index.column()){
        case 0:
            return QString::number(travelAgency->getTravel(index.row())->getId());
        case 1:
            return travelAgency->getTravel(index.row())->checkRoundtrip() == true ? "Ok" : "Kein Roundtrip";
        case 2:
            return travelAgency->getTravel(index.row())->checkMissingHotel() == true ? "Ok" : "Obdachlos";

        case 3:
            return travelAgency->getTravel(index.row())->checkNeedlessHotel() == true ? "Überflüssig" : "Ok";
        case 4:
            return travelAgency->getTravel(index.row())->checkNeedlessCar() == true ? "Überflüssig" : "Ok";





        }


    }

    return QVariant();

}


