#ifndef BASERESERVATION_H
#define BASERESERVATION_H

#include <QDateTime>
#include "Entities/customer.h"

class BaseReservation
{
protected:
    QDateTime startDatetime;
    QDateTime endDatetime;
    Customer& customer;
    QString specificDemands;
public:
    BaseReservation(QDateTime startDatetime, QDateTime endDatetime, Customer& customer);
    BaseReservation(QDateTime startDatetime, Customer& customer);
};

#endif // BASERESERVATION_H
