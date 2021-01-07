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

void CustomerManager::CreateCustomer(Customer &customer){
    if (CustomerIsValid(customer)){
        QSqlRecord record;
        QSqlQuery query;
        QSqlField field1("firstname", QMetaType::fromType<QString>());
        QSqlField field2("lastname", QMetaType::fromType<QString>());
        QSqlField field3("phonenumber", QMetaType::fromType<QString>());
        QSqlField field4("addressID", QMetaType::fromType<int>());
        addressmanager.CreateAddressWithQuery(customer.address);
        field1.setValue(customer.firstName);
        field2.setValue(customer.lastName);
        field3.setValue(customer.phoneNumber);
        field4.setValue(7);

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
