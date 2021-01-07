#ifndef CUSTOMERMANAGER_H
#define CUSTOMERMANAGER_H
#include "Entities/customer.h"
#include "addressmanager.h"

#include <QDateTime>
#include <QtSql>
#include <memory>

class CustomerManager
{
private:
    QSqlRelationalTableModel *model = new QSqlRelationalTableModel;
    AddressManager addressmanager;

public:
    CustomerManager();

    void initializeCustomerModel(QSqlRelationalTableModel *model);

    void CreateCustomer(Customer &customer);

    void ModifyCustomer(Customer &oldCustomer, Customer &newCustomer);

    void RemoveCustomer(Customer &customer);

    QList<Customer> ViewCustomer(QDateTime &startDatetime, QDateTime &endDatetime);

    bool CustomerIsValid(Customer &customer);

    QSqlRelationalTableModel* getCustomerModel(){
        return model;
    };

};

#endif // CUSTOMERMANAGER_H
