#include "pool.h"

Pool::Pool(int poolNumber, int maxNumberOfPeople, QDateTime lastMaintenanceCheck)
{
    this->poolNumber = poolNumber;
    this->maxNumberOfPeople = maxNumberOfPeople;
    this->lastMaintenanceCheck = lastMaintenanceCheck;
}
