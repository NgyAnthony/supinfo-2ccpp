#include "customermanager.h"
#include "Entities/customer.h"
#include <QDateTime>
#include <QtSql>
#include <memory>

CustomerManager::CustomerManager()
{    
    initializeCustomerTable();
    initializeCustomerModel(model);
}

void CustomerManager::initializeCustomerModel(QSqlRelationalTableModel *model)
{
    //! [0]
        model->setTable("customer");
    //! [0]

        model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    //! [1]
        model->setRelation(4, QSqlRelation("address", "id", "country"));
        model->setRelation(5, QSqlRelation("address", "id", "streetname"));

    //! [1]

    //! [2]
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("First name"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Last name"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Phone number"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Country"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("Address"));
    //! [2]

        model->select();
}


void CustomerManager::initializeCustomerTable()
{
    QSqlQuery query;
    query.exec("create table customer(id int primary key, firstname varchar(20), lastname varchar(20), phonenumber varchar(20), address int)");
    query.exec("insert into customer values(1, 'Espen', 'LastName1', '+331222345', 1)");
    query.exec("insert into customer values(2, 'Harald', 'LastName2', '+33433321', 2)");
    query.exec("insert into customer values(3, 'Sam', 'LastName3', '+339090909', 3)");

    query.exec("create table address(id int, country varchar(20), streetname varchar(20))");
    query.exec("insert into address values(1, 'Germany', 'Rue allemagne')");
    query.exec("insert into address values(2, 'France', 'Rue france')");
    query.exec("insert into address values(3, 'Italy', 'Rue italie')");

}

void CustomerManager::CreateCustomer(Customer &customer){
    if (CustomerIsValid(customer)){
        QSqlRecord record;

        QSqlField field1("firstname", QMetaType::fromType<QString>());
        QSqlField field2("lastname", QMetaType::fromType<QString>());
        QSqlField field3("phonenumber", QMetaType::fromType<QString>());
        QSqlField field4("address", QMetaType::fromType<int>());

        field1.setValue(customer.firstName);
        field2.setValue(customer.lastName);
        field3.setValue(customer.phoneNumber);
        // TODO: create the address manager, make the program create the address and return the ID
        field4.setValue(1);

        record.append(field1);
        record.append(field2);
        record.append(field3);
        record.append(field4);

        model->insertRecord(-1, record);
        model->submitAll();
        model->select();
    }
}

void CustomerManager::ModifyCustomer(Customer &oldCustomer, Customer &newCustomer){

}

void CustomerManager::RemoveCustomer(Customer &customer){

}

QList<Customer> CustomerManager::ViewCustomer(QDateTime &startDatetime, QDateTime &endDatetime){

    QList<Customer> list;
    return list;
}

bool CustomerManager::CustomerIsValid(Customer &customer){
    return true;
}
