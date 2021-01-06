#ifndef BASERESERVATION_H
#define BASERESERVATION_H

#include <QDateTime>
#include "Entities/customer.h"

class BaseReservation
{
protected:
    QDateTime startDatetime;
    QDateTime endDatetime;
    Customer customer;
    QString specificDemands;

public:
    BaseReservation(QDateTime startDatetime, QDateTime endDatetime, Customer customer);
    BaseReservation(QDateTime startDatetime, Customer customer);

    void setStartDatetime(QDateTime sD) {
      startDatetime = sD;
    }

    QDateTime getStartDatetime() {
      return startDatetime;
    }


    void setEndDatetime(QDateTime eD) {
      endDatetime = eD;
    }

    QDateTime getEndDatetime() {
      return endDatetime;
    }

    void setCustomer(Customer cs) {
      customer = cs;
    }

    Customer getCustomer(){
        return customer;
    }

    void setSpecificDemands(QString spD){
        specificDemands = spD;
    }

    QString getSpecificDemands(){
        return specificDemands;
    }
};

#endif // BASERESERVATION_H
