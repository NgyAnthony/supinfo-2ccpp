#include "customermanager.h"
#include "Entities/customer.h"
#include <QDateTime>
#include <QtSql>
#include <memory>

CustomerManager::CustomerManager()
{    
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

    //! [1]

    //! [2]
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("First name"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Last name"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Phone number"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Country"));

    //! [2]

        model->select();
}

int CustomerManager::CreateCustomerWithQuery(Customer &customer){
        QSqlQuery query;
        query.prepare("INSERT INTO customer (firstname, lastname, phonenumber, addressID) "
                   "VALUES (:firstname, :lastname, :phonenumber, :addressID)");

        query.bindValue(":firstname", customer.firstName);
        query.bindValue(":lastname", customer.lastName);
        query.bindValue(":phonenumber", customer.phoneNumber);

        int addressFk = addressmanager.CreateAddressWithQuery(customer.address);
        query.bindValue(":addressID", addressFk);

        query.exec();
        model->select();
        return query.lastInsertId().toInt();
}


void CustomerManager::Refresh(){
    model->select();
}

void CustomerManager::SubmitChanges(){
    model->submitAll();
    model->select();
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
