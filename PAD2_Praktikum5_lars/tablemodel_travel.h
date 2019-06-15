#ifndef TABLEMODEL_TRAVEL_H
#define TABLEMODEL_TRAVEL_H

#include <QAbstractTableModel>
#include <travelagency.h>

class tablemodel_travel : public QAbstractTableModel
{
    Q_OBJECT

    TravelAgency *travelAgency;

public:
    tablemodel_travel(QObject * parent = nullptr, TravelAgency* travelAgency = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant headerData(int section, Qt::Orientation orientation,int role) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    void setTravelAgency(TravelAgency *value);
    void refresh();
};

#endif // TABLEMODEL_TRAVEL_H
