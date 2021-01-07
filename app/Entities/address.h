#ifndef ADDRESS_H
#define ADDRESS_H

#include <QString>

class Address
{
public:

    Address(QString country, QString postalCode, QString streetName,  QString streetNumber);
    QString country;
    QString postalCode;
    QString streetName;
    // String because we might have a number like "14bis"
    QString streetNumber;
};

#endif // ADDRESS_H
