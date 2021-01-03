#ifndef POOL_H
#define POOL_H

#include <QDateTime>

class Pool
{
public:
    Pool(int poolNumber, int maxNumberOfPeople, QDateTime lastMaintenanceCheck);
    int poolNumber;
    int maxNumberOfPeople;
    QDateTime lastMaintenanceCheck;
};

#endif // POOL_H
