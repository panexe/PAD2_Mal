#ifndef TRAVELDIALOG_H
#define TRAVELDIALOG_H

#include <QDialog>
#include "travelagency.h"
#include "tablemodel_travel.h"

namespace Ui {
class TravelDialog;
}

class TravelDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TravelDialog(QWidget *parent = nullptr, TravelAgency* travelAgency = nullptr);
    ~TravelDialog();

private slots:
    void on_tableView_doubleClicked(const QModelIndex &index);

private:
    Ui::TravelDialog *ui;
    TravelAgency* travelAgency;
    tablemodel_travel tableModel;
};

#endif // TRAVELDIALOG_H
