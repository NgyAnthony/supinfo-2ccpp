#ifndef ADDRESSMANAGER_H
#define ADDRESSMANAGER_H

#include "Entities/address.h"
#include <QDateTime>

#include <QtSql>
#include <memory>


class AddressManager
{

private:
    QSqlRelationalTableModel *model = new QSqlRelationalTableModel;

public:
    AddressManager();

    void initializeAddressModel(QSqlRelationalTableModel *model);

    void CreateAddress(Address &address);

    int CreateAddressWithQuery(Address &address);

    bool AddressIsValid(Address &address);

    QSqlRelationalTableModel* getAddressModel(){
        return model;
    };
};

#endif // ADDRESSMANAGER_H
