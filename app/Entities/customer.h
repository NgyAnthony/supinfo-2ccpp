#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <QString>
#include "address.h"

class Customer
{
public:
    Customer(QString firstName, QString lastName, QString phoneNumber, Address address);
    QString firstName;
    QString lastName;
    QString phoneNumber;
    Address address;
};

#endif // CUSTOMER_H
