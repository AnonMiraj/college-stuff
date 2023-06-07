#include "carSys.h"
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
CarSys::CarSys() {
  m_cars = new Car[100];
  m_carCount = 0;
  m_customers = new Customer[100];
  m_customersCount = 0;
}
CarSys::~CarSys() {
  delete[] m_cars;
  delete[] m_customers;
}
void CarSys::addCar() { m_cars[m_carCount++].readCarData(); }
void CarSys::addCustomer() {
  m_customers[m_customersCount++].readCustomerData();
}

int CarSys::findCar(int carId) {
  for (int i = 0; i < m_carCount; i++)
    if (m_cars[i].getId() == carId)
      return i;
  return -1;
}
int CarSys::findCustomer(int customerId) {
  for (int i = 0; i < m_customersCount; i++)
    if (m_customers[i].getId() == customerId)
      return i;
  return -1;
}

void CarSys::rentCar() {
  Reservation reservation;
  reservation.readReservation();
  int carIdx = findCar(reservation.getCarId());
  int customerIdx = findCustomer(reservation.getCustomerId());
  if (carIdx == -1) {
    cout << "car not found" << endl;
  } else if (customerIdx == -1) {
    cout << "customer not found" << endl;
  } else {
    m_customers[customerIdx].addReservation(reservation);
    cout << "Reservation Completed" << endl;
  }
}

void CarSys::printCar() {
  int carId;
  cout << "Enter car ID: ";
  cin >> carId;
  int idx = findCar(carId);
  if (idx == -1) {
    cout << "car not found" << endl;
  } else {
    cout << m_cars[idx];
  }
}
void CarSys::printAllCars() {
  for (int idx = 0; idx < m_carCount; idx++) {
    cout << m_cars[idx];
  }
}

void CarSys::printCustomer() {
  int customerId;
  cout << "Enter customer's ID: " << endl;
  cin >> customerId;
  cout << endl;
  int idx = findCustomer(customerId);
  if (idx == -1) {
    cout << "Customer not found" << endl;
  } else {
    cout << m_customers[idx];
  }
}
void CarSys::printReport() {
  cout << "All Customers' Rental History" << endl;
  for (int index = 0; index < m_customersCount; index++) {
    cout << index + 1 << ": \n" << m_customers[index] << endl;
  }
  cout << "All cars' Rental History" << endl;
  for (int index = 0; index < m_carCount; index++) {
    cout << "[" << index + 1 << "]- \n" << m_cars[index] << endl;
  }
}
void CarSys::saveSys() {
  std::fstream inpf;
  inpf.open("data.txt", std::ios::out);
  if (inpf.is_open()) {
    // Write data to the file
    inpf << m_carCount << endl;
    // Close the file
    inpf.close();
  }
  for (int i = 0; i < m_carCount; i++) {
    m_cars[i].saveCar();
  }
  inpf.open("data.txt", std::ios::app);
  if (inpf.is_open()) {
    inpf << m_customersCount << endl;
    inpf.close();
  }
  for (int i = 0; i < m_customersCount; i++) {
    m_customers[i].saveCustomer();
  }
}
void CarSys::loadSys() {
  std::fstream inpf;
  inpf.open("data.txt", std::ios::in);

  if (inpf.is_open()) {
    std::string line;
    std::getline(inpf, line);
    m_carCount = stoi(line);
    // Read data from the txt file line by line
    for (int i = 0; i < m_carCount; i++) {

      std::getline(inpf, line);
      std::string token;
      std::istringstream tokenStream(line);

      // Read space separated values from each line
      std::getline(tokenStream, token, ' ') ;
      int car_id=stoi(token);
      std::getline(tokenStream, token, ' ') ;
      int year=stoi(token);
      string make ,model; 
      std::getline(tokenStream, make, ' ') ;
      std::getline(tokenStream, model, ' ') ;
      m_cars[i] = Car(car_id,make,model,year);
    }
    std::getline(inpf, line);
    m_customersCount = stoi(line);

    for (int i = 0; i < m_customersCount; i++) {

      std::getline(inpf, line);
      std::string token;
      std::istringstream tokenStream(line);

      // Read space separated values from each line
      std::getline(tokenStream, token, ' ');
      int customerId = stoi(token);
      string name, phone, addreas;
      std::getline(tokenStream, name, ' ');
      std::getline(tokenStream, phone, ' ');
      std::getline(tokenStream, addreas, ' ');

      m_customers[i] = Customer(customerId, name, phone, addreas);

      std::getline(inpf, line);
      int reservationCount = stoi(line);
      for (int i = 0; i < reservationCount; i++) {
        std::getline(inpf, line);
        std::stringstream tokenStream1(line);
        std::getline(inpf, line);
        int taxes=stoi(line);
        std::getline(inpf, line);
        std::stringstream tokenStream2(line);
        string rentalAgreementString=line;


        int  carid;

        std::getline(tokenStream1, token, ' ');
        carid = stoi(token);
        std::getline(tokenStream1, token, ' ');
        tm startDate, endDate;
        std::getline(tokenStream1, token, ' ');
        startDate.tm_year = stoi(token),
        std::getline(tokenStream1, token, ' ');
        startDate.tm_mon = stoi(token),
        std::getline(tokenStream1, token, ' ');
        startDate.tm_mday = stoi(token);
        std::getline(tokenStream1, token, ' ');
        endDate.tm_year = stoi(token),
        std::getline(tokenStream1, token, ' ');
        endDate.tm_mon = stoi(token),
        std::getline(tokenStream1, token, ' ');
        endDate.tm_mday = stoi(token);
        
        int period = (endDate.tm_year - startDate.tm_year) * 360 +
                     (endDate.tm_mon - startDate.tm_mon) * 30 +
                     (endDate.tm_mday - startDate.tm_mday);
        string info1,info2;


        std::getline(tokenStream2, info1, ' ');
        std::getline(tokenStream2, info2, ' ');

        m_customers[i].addReservation(Reservation(carid,i,startDate,endDate,Invoice(taxes,RentalAgreement(period,stoi(info1),stoi(info2)))));
      }
    }
    inpf.close();
  }
}
