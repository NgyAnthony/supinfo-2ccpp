#include "customer.h"

Customer::Customer(QString firstName, QString lastName, QString phoneNumber, Address address) : address(address)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->phoneNumber = phoneNumber;
    this->address = address;
}
