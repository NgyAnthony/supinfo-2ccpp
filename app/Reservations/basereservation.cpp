#include "basereservation.h"
#include <QDateTime>

BaseReservation::BaseReservation(QDateTime startDatetime, QDateTime endDatetime, Customer customer)
{
    this->startDatetime = startDatetime;
    this->endDatetime = endDatetime;
    this->customer = customer;
}

BaseReservation::BaseReservation(QDateTime startDatetime, Customer customer){
    this->startDatetime = startDatetime;
    this->customer = customer;
}
