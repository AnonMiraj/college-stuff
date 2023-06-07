#include "reservation.h"
#include "invoice.h"
#include <iostream>
#include <string>

// Constructor
Reservation::Reservation()
    : m_carId(0), m_customerId(0), m_startDate(), m_endDate(), m_invoice() {}

Reservation::Reservation(int carId, int customerId, tm start, tm end,
                         Invoice invoice)
    : m_carId(carId), m_customerId(customerId), m_startDate(start),
      m_endDate(end), m_invoice(invoice) {}

Reservation::~Reservation() {}

// Setters kinda

void Reservation::readReservation() {
  std::cout << "Enter ID of car you want to reserve: " << std::endl;
  std::cin >> m_carId;
  std::cout << "Enter Customer's ID: " << std::endl;
  std::cin >> m_customerId;
  std::cout << "Enter your reservation start time(yyyy-mm-dd): " << std::endl;
  std::cin >> m_startDate.tm_year;
  std::cin.get();
  std::cin >> m_startDate.tm_mon;
  std::cin.get();
  std::cin >> m_startDate.tm_mday;
  std::cout << "Enter your reservation end time(yyyy-mm-dd): " << std::endl;
  std::cin >> m_endDate.tm_year;
  std::cin.get();
  std::cin >> m_endDate.tm_mon;
  std::cin.get();
  std::cin >> m_endDate.tm_mday;
  m_invoice.readInvoiceData(
      (m_endDate.tm_year * 360 + m_endDate.tm_mon * 30 + m_endDate.tm_mday) -
      (m_startDate.tm_year * 360 + m_startDate.tm_mon * 30 +
       m_startDate.tm_mday));
}
void Reservation::saveReservation() const{
  std::fstream inpf;
  inpf.open("data.txt", std::ios::app);
  if (inpf.is_open()) {
    // Write data to the file
    inpf << m_carId << " " << m_customerId << " "
         << m_startDate.tm_year << " "
         << m_startDate.tm_mon << " " << m_startDate.tm_mday << " "
         << m_endDate.tm_year << " "
         << m_endDate.tm_mon << " " << m_endDate.tm_mday << std::endl;
    
    // Close the file
    inpf.close();
m_invoice.saveInvoice();
  }
}
// Getters
int Reservation::getCarId() const { return m_carId; }

int Reservation::getCustomerId() const { return m_customerId; }

tm Reservation::getStartDate() const { return m_startDate; }

tm Reservation::getEndDate() const { return m_endDate; }
Invoice Reservation::getInvoice() const { return m_invoice; }


std::ostream &operator<<(std::ostream &os, Reservation &reservation) {
  os << "Reservation details: " << std::endl;
  os << "Car ID: " << reservation.m_carId << std::endl;
  os << "Customer ID: " << reservation.m_customerId << std::endl;
  os << "Start date : " << reservation.m_startDate.tm_year << "/"
     << reservation.m_startDate.tm_mon << "/" << reservation.m_startDate.tm_mday
     << std::endl;
  os << "End date: " << reservation.m_endDate.tm_year << "/"
     << reservation.m_endDate.tm_mon << "/" << reservation.m_endDate.tm_mday
     << std::endl;
  os << "Invoice details :" << std::endl;
  os << reservation.m_invoice;
  return os;
}
