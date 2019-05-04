#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QAbstractTableModel>
#include "travelagency.h"

class TableModel : public QAbstractTableModel
{
    Q_OBJECT

    TravelAgency *travelAgency;
public:
    TableModel(QObject * parent = nullptr, TravelAgency* travelAgency = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant headerData(int section, Qt::Orientation orientation,int role) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    void setTravelAgency(TravelAgency *value);
    void refresh();
};

#endif // TABLEMODEL_H
