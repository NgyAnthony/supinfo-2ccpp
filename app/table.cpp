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
    addressWidget = ui->addresses;

    // Get first index on init
    on_comboBox_currentIndexChanged(0);
}

Table::~Table()
{
    delete ui;
}

void Table::TriggerCreateCustomer(){
    QString fn = ui -> firstnameText-> text();
    QString ln = ui -> lastnameText -> text();
    QString pn = ui -> phonenumberText -> text();
    QString cn = ui -> countryText -> text();
    QString pc = ui -> postalcodeText -> text();
    QString sname = ui -> streetnameText -> toPlainText();
    QString snumber = ui -> streetNumberText -> text();
    Address* customerAddress = new Address(cn, pc, sname, snumber);
    Customer* currentCustomer = new Customer(fn, ln, pn, *customerAddress);
    customermanager.CreateCustomer(*currentCustomer);
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
        table->setModel(addressmanager.getAddressModel());
        stackedWidget->setCurrentWidget(addressWidget);
        break;

    case 2:
        table->setModel(customermanager.getCustomerModel());
        stackedWidget->setCurrentWidget(poolreservationWidget);
        break;

    default:
        table->setModel(customermanager.getCustomerModel());
        break;
    }
}

void Table::on_addButton_clicked()
{
    int clicked = ui->comboBox->currentIndex();
    switch (clicked)
    {

    case 0:
        TriggerCreateCustomer();
        break;

    case 1:
        break;

    case 2:
        break;

    default:
        break;
    }
}
