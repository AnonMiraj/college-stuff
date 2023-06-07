#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <iostream>
#include <fstream>
#include "reservation.h"
using namespace std;
class Customer {
public:
  Customer();
  Customer(int id, std::string name, std::string address, std::string phone_number);
  ~Customer();

  // Getters
  int getId() const;
  string getName() const;
  string getAddress() const;
  string getPhoneNumber() const;
  int getReservationCount() const;


  // Setters
  void setId(int id);
  void setName(std::string name);
  void setAddress(std::string address);
  void setPhoneNumber(std::string phone_number);
  void readCustomerData();
  void addReservation(Reservation reservation);
  void saveCustomer();
  // Overloaded operators
  ostream& operator <<(ostream &os);
  friend ostream& operator<<(ostream& os, Customer& customer);

private:
  int m_id;
  int m_reservationCount;
  string m_name;
  string m_address;
  string m_phone_number;
  Reservation *m_reservation;
};

#endif
