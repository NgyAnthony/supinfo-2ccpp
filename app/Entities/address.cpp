#include "address.h"

Address::Address(QString country, QString postalCode, QString streetName,  QString streetNumber)
{
    this->country = country;
    this->postalCode = postalCode;
    this->streetName = streetName;
    this->streetNumber = streetNumber;
}
