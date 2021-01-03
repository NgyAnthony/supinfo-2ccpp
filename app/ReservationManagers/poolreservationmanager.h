#ifndef POOLRESERVATIONMANAGER_H
#define POOLRESERVATIONMANAGER_H

#include "Reservations/poolreservation.h"
#include "ReservationManagers/basereservationmanager.h"

class PoolReservationManager
{
public:    
    PoolReservationManager();
    void CreateReservation(PoolReservation& poolReservation);
    void ModifyReservation(PoolReservation& oldPoolReservation, PoolReservation& newPoolReservation);
    void RemoveReservation(PoolReservation& poolReservation);
    QList<PoolReservation> ViewReservation(QDateTime& startDatetime, QDateTime& endDatetime);
    bool ReservationIsValid(PoolReservation& poolReservation);
};

#endif // POOLRESERVATIONMANAGER_H
