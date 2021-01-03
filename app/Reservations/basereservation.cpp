#include "basereservation.h"
#include <QDateTime>

BaseReservation::BaseReservation(QDateTime startDatetime, QDateTime endDatetime, Customer& customer) : customer(customer)
{
    this->startDatetime = startDatetime;
    this->endDatetime = endDatetime;

}

BaseReservation::BaseReservation(QDateTime startDatetime, Customer& customer) : customer(customer) {
    this->startDatetime = startDatetime;
}
