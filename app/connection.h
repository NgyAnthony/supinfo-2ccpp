
#ifndef CONNECTION_H
#define CONNECTION_H

#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

/*
    This file defines a helper function to open a connection to an
    in-memory SQLITE database and to create a test table.

    If you want to use another database, simply modify the code
    below. All the examples in this directory use this function to
    connect to a database.
*/
//! [0]
static bool createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(":memory:");
    if (!db.open()) {
        QMessageBox::critical(nullptr, QObject::tr("Cannot open database"),
            QObject::tr("Unable to establish a database connection.\n"
                        "This example needs SQLite support. Please read "
                        "the Qt SQL driver documentation for information how "
                        "to build it.\n\n"
                        "Click Cancel to exit."), QMessageBox::Cancel);
        return false;
    }

    QSqlQuery query;


    query.exec("create table address(id INTEGER PRIMARY KEY AUTOINCREMENT, country varchar(20), postalcode varchar(20), streetname varchar(20), streetnumber varchar(20))");
    query.exec("insert into address values(1, 'Allemagne', '11150', 'Rue allemagne', '1')");
    query.exec("insert into address values(2, 'France', '44150', 'Rue france', '7')");
    query.exec("insert into address values(3, 'Italy', '33000', 'Rue italie', '12bis')");

    query.exec("create table customer(id INTEGER PRIMARY KEY AUTOINCREMENT, firstname varchar(20), lastname varchar(20), phonenumber varchar(20), addressID int, FOREIGN KEY (addressID) REFERENCES address(id))");
    query.exec("insert into customer values(1, 'Espen', 'LastName1', '+331222345', 1)");
    query.exec("insert into customer values(2, 'Harald', 'LastName2', '+33433321', 2)");
    query.exec("insert into customer values(3, 'Sam', 'LastName3', '+339090909', 3)");

    return true;
}
//! [0]

#endif
