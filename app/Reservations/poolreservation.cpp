#include "poolreservation.h"

PoolReservation::PoolReservation(QDateTime startDatetime, QDateTime endDatetime, Customer customer, Pool pool) :
    BaseReservation(startDatetime, endDatetime, customer), pool(pool)
{

}
