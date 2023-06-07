#include "customer.h"
#include "invoice.h"
#include "rentalagreement.h"
#include "reservation.h"
#include <ctime>
#include <string>

using namespace std;

Customer::Customer() : m_id(0), m_name(""), m_address(""), m_phone_number("") ,m_reservationCount(0) {
  m_reservation = new Reservation[100];
}

Customer::Customer(int id, string name, string address, string phone_number)
    : m_id(id), m_name(name), m_address(address), m_phone_number(phone_number) ,m_reservationCount(0){
  m_reservation = new Reservation[100];
}
Customer::~Customer() { delete[] m_reservation; }
int Customer::getId() const { return m_id; }

string Customer::getName() const { return m_name; }

string Customer::getAddress() const { return m_address; }

string Customer::getPhoneNumber() const { return m_phone_number; }

int Customer::getReservationCount() const { return m_reservationCount; }

void Customer::setId(int id) { m_id = id; }
void Customer::setName(string name) { m_name = name; }

void Customer::setAddress(string address) { m_address = address; }

void Customer::setPhoneNumber(string phone_number) {
  m_phone_number = phone_number;
}
void Customer::saveCustomer() {
  std::fstream inpf;
  inpf.open("data.txt", std::ios::app);
  if (inpf.is_open()) {
    // Write data to the file
    inpf << m_id << " " << m_name << " " << m_address << " " << m_phone_number
         << endl;
    inpf<<m_reservationCount<<endl;
    // Close the file
    inpf.close();

    for (int i = 0; i < m_reservationCount; i++) {
      m_reservation[i].saveReservation();
    }
  }
}
void Customer::readCustomerData() {
  cout << "Enter the customer ID: " << endl;
  cin >> m_id;
  cout << "Enter the customer name: " << endl;
  cin >> m_name;
  cout << "Enter the customer address: " << endl;
  cin >> m_address;
  cout << "Enter the customer phone: " << endl;
  cin >> m_phone_number;
}

void Customer::addReservation(Reservation reservation) {
  m_reservation[m_reservationCount++] = reservation;
}
ostream &operator<<(ostream &os, Customer &customer) {
  os << "customer's ID is " << customer.m_id << endl;
  os << "customer's name is " << customer.m_name << endl;
  os << "customer's address is " << customer.m_address << endl;
  os << "customer's phone is " << customer.m_phone_number << endl;
  os << "customer's number of reservations is " << customer.m_reservationCount
     << endl;
  int totalPay = 0;
  for (int i = 0; i < customer.m_reservationCount; i++) {
    os << customer.m_reservation[i] << endl;
    totalPay = customer.m_reservation[i].getInvoice().getTotalAmountDue();
  }
  os << "total Pay of this customer is " << totalPay << endl;
  return os;
}
