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

    void setAddress(Address ad){
        address = ad;
    }
};

#endif // CUSTOMER_H
