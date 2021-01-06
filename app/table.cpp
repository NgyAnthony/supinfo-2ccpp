#include "table.h"
#include "ui_table.h"
#include "connection.h"
#include <QLayoutItem>
#include <QTableView>
#include <QStackedWidget>

Table::Table(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Table)
{
    ui->setupUi(this);
    table = ui->tableView;
    stackedWidget = ui->stackedWidget;
    poolreservationWidget = ui->poolreservation;
    customersWidget = ui->customers;

    // Get first index on init
    on_comboBox_currentIndexChanged(0);
}

Table::~Table()
{
    delete ui;
}

// Figure out which Table is selected and fetch it
void Table::on_comboBox_currentIndexChanged(int index)
{
    switch (index)
    {

    case 0:
        table->setModel(customermanager.getCustomerModel());
        stackedWidget->setCurrentWidget(customersWidget);

        break;
    case 1:
        table->setModel(customermanager.getCustomerModel());
        stackedWidget->setCurrentWidget(poolreservationWidget);

        break;
    default:
        table->setModel(customermanager.getCustomerModel());
        break;
    }
}
