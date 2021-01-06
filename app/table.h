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

private:
    Ui::Table *ui;
    QTableView *table;
    QStackedWidget *stackedWidget;
    QWidget *customersWidget;
    QWidget *poolreservationWidget;
    CustomerManager customermanager;
};

#endif // TABLE_H
