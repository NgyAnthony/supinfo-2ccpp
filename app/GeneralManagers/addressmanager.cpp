#include "addressmanager.h"

AddressManager::AddressManager()
{
    initializeAddressModel(model);
}

Address AddressManager::FetchAddressWithIndex(int index){
    QSqlQuery query;


    bool prepRet = query.exec("SELECT * FROM address WHERE id = " + QString::number(index));

    if (!prepRet) {
         qDebug() << query.lastError().text();
    }

    if (!query.exec()) {
         qDebug() << query.lastError().text();
    }

    query.first();
    Address* fetchedAddress = new Address(query.value(1).toString(), query.value(2).toString(), query.value(3).toString(), query.value(4).toString());
    return *fetchedAddress;
}

void AddressManager::CreateAddress(Address &address){
    if (AddressIsValid(address)){
        QSqlRecord record;

        QSqlField field1("country", QMetaType::fromType<QString>());
        QSqlField field2("postalcode", QMetaType::fromType<QString>());
        QSqlField field3("streetname", QMetaType::fromType<QString>());
        QSqlField field4("streetnumber", QMetaType::fromType<QString>());

        field1.setValue(address.country);
        field2.setValue(address.postalCode);
        field3.setValue(address.streetName);
        field4.setValue(address.streetNumber);

        record.append(field1);
        record.append(field2);
        record.append(field3);
        record.append(field4);

        model->insertRecord(-1, record);
        model->submitAll();
        model->select();
    }
}

int AddressManager::CreateAddressWithQuery(Address &address){
        QSqlQuery query;
        query.prepare("INSERT INTO address (country, postalcode, streetname, streetnumber) "
                   "VALUES (:country, :postalcode, :streetname, :streetnumber)");
        query.bindValue(":country", address.country);
        query.bindValue(":postalcode", address.postalCode);
        query.bindValue(":streetname", address.streetName);
        query.bindValue(":streetnumber", address.streetNumber);

        query.exec();
        model->select();
        return query.lastInsertId().toInt();
}

void AddressManager::initializeAddressModel(QSqlRelationalTableModel *model)
{
    //! [0]
        model->setTable("address");
    //! [0]

        model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    //! [1]
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Country"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Postal Code"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Street Name"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Street Number"));

    //! [1]

        model->select();
}

bool AddressManager::AddressIsValid(Address &address){
    return true;
}

void AddressManager::Refresh(){
    model->select();
}

void AddressManager::SubmitChanges(){
    model->submitAll();
    model->select();
}
