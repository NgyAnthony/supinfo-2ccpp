#ifndef BASERESERVATION_H
#define BASERESERVATION_H

#include <QDateTime>
#include "Entities/customer.h"

class BaseReservation
{
public:
    BaseReservation(QDateTime startDatetime, QDateTime endDatetime, Customer customer);
    BaseReservation(QDateTime startDatetime, Customer customer);

    QDateTime startDatetime;
    QDateTime endDatetime;
    Customer customer;
    QString specificDemands;
};

#endif // BASERESERVATION_H
