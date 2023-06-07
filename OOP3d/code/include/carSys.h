#ifndef CARSYS_H
#define CARSYS_H
#include "car.h"
#include "customer.h"
#include <vector>
#include <sstream>
#include <fstream>

class CarSys {
public:
  CarSys();
  ~CarSys();
  void addCar();
  int findCar(int carId);
  void addCustomer();
  int findCustomer(int customerId);
  void rentCar();
  void printCar();
  void printAllCars();
  void printCustomer();
  void printReport();
  void saveSys();
  void loadSys();
private:
 Car*m_cars;
 int m_carCount;
 Customer* m_customers;
 int m_customersCount;
 
};

#endif // !CARSYS_H
