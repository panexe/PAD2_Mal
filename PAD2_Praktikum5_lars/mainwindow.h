#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


#include "travelagency.h"
#include "tablemodel.h"



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionDatei_einlesen_triggered();

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_actionBuchung_anlegen_triggered();

    void on_actionRefresh_triggered();

    void on_actionTextdatei_Erstellen_triggered();

    void on_actionTrip_Attributes_triggered();

private:
    Ui::MainWindow *ui;
    TableModel tableModel;




    TravelAgency *travelAgency;
};

#endif // MAINWINDOW_H
