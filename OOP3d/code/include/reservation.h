#ifndef RESERVATION_H
#define RESERVATION_H
#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include "invoice.h"
using  namespace std;
class Reservation
{
public:
    // Constructor
    Reservation();
    Reservation(int carId, int customerId, tm start, tm end,Invoice m_invoice);
    ~Reservation();
    // Getters
    int getCarId() const;
    int getCustomerId() const;
    tm getStartDate() const;
    tm getEndDate() const;
    Invoice getInvoice()const;

    void readReservation() ;
    void saveReservation() const;
    // Overloaded operators
   friend std::ostream& operator<<(std::ostream& os, Reservation& reservation);
    

private:
    int m_carId;
    int m_customerId;
    tm m_startDate;
    tm m_endDate;
    Invoice m_invoice;
  };

#endif // RESERVATION_H

