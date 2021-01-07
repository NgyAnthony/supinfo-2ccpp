#ifndef TABLE_H
#define TABLE_H

#include <QWidget>
#include <QtSql>
#include <QTableView>
#include <QStackedWidget>
#include "GeneralManagers/customermanager.h"

namespace Ui {
class Table;
}

class Table : public QWidget
{
    Q_OBJECT

public:
    explicit Table(QWidget *parent = nullptr);
    ~Table();

private slots:
    void on_comboBox_currentIndexChanged(int index);

    void on_addButton_clicked();

private:
    Ui::Table *ui;
    QTableView *table;
    QStackedWidget *stackedWidget;
    QWidget *customersWidget;
    QWidget *addressWidget;
    QWidget *poolreservationWidget;
    AddressManager addressmanager;
    CustomerManager customermanager;
    void TriggerCreateCustomer();
};

#endif // TABLE_H
