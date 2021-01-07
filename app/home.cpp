#include "home.h"
#include "ui_home.h"
#include <QtSql>
#include "connection.h"
#include <QCompleter>
#include "Entities/customer.h"

Home::Home(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Home)
{
    ui->setupUi(this);
}

Home::~Home()
{
    delete ui;
}

void Home::AddSearchSuggestions(QString fullName){
    // SQL Query LIKE to wordlist

    QSqlQuery query;
    bool prepRet = query.prepare("SELECT * FROM customer WHERE  firstname ||  ' ' || lastname LIKE :fullname");
    query.bindValue(":fullname", ("%" + fullName + "%"));

    if (!prepRet) {
         qDebug() << query.lastError().text();
         return;
    }
    if (!query.exec()) {
         qDebug() << query.lastError().text();
        return;
    }

    QStringList customerNameList;
    while (query.next()) {
        QString fullName =  query.value(1).toString() + ' ' +  query.value(2).toString();
        customerNameList << fullName;
    }

    QCompleter *completer = new QCompleter(customerNameList, this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    ui->lineEdit->setCompleter(completer);
}

void Home::FetchCustomer(QString fullName){
    QSqlQuery query;

    QStringList list_str = fullName.split(" ");
    QString firstName = list_str.first();
    QString lastName = list_str.back();
    qDebug() << firstName;
    qDebug() << lastName;

    bool prepRet = query.prepare("SELECT * FROM customer WHERE firstname = :firstname AND lastname = :lastname");
    query.bindValue(":firstname", firstName);
    query.bindValue(":lastname", lastName);

    if (!prepRet) {
         qDebug() << query.lastError().text();
         return;
    }
    if (!query.exec()) {
         qDebug() << query.lastError().text();
        return;
    }

    QStringList customerNameList;
    while (query.next()) {
        qDebug() << "HAPPENED";
        Address address = addressmanager.FetchAddressWithIndex(query.value(4).toInt());
        Customer* customer = new Customer(query.value(1).toString(), query.value(2).toString(), query.value(3).toString(), address);
        SetCustomerOnHome(*customer);
        qDebug() << query.value(1).toString();
    }
}

void Home::SetCustomerOnHome(Customer customer){
    ui->customerFullName->setText(customer.firstName + ' ' + customer.lastName);
    ui->customerPhoneNumber->setText(customer.phoneNumber);
    ui->customerCountry->setText(customer.address.country);
    ui->customerPostalCode->setText(customer.address.postalCode);
    ui->customerStreetName->setText(customer.address.streetName);
    ui->customerStreetNumber->setText(customer.address.streetNumber);
}

void Home::on_lineEdit_textChanged(const QString &arg1)
{
    AddSearchSuggestions(arg1);
    FetchCustomer(arg1);
}
