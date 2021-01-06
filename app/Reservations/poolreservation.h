#ifndef POOLRESERVATION_H
#define POOLRESERVATION_H
#include "basereservation.h"
#include "Entities/pool.h"

class PoolReservation : public BaseReservation
{

private:
    Pool pool;

public:
    PoolReservation(QDateTime startDatetime, QDateTime endDatetime, Customer customer, Pool pool);

    void setPool(Pool pl){
        pool = pl;
    }

    Pool& getPool(){
        return pool;
    }
};

#endif // POOLRESERVATION_H
