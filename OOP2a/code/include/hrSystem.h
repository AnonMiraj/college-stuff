#include "employee.h"
#include "department.h"
#include "manageremployee.h"
#include "commissionemployee.h"
#include "hourlyemployee.h"
#include <iomanip>
#include <iostream>
#ifndef HRSYSTEM_H
#define HRSYSTEM_H
class hrSystem {
public:
  hrSystem(int);
  virtual ~hrSystem();
  void addEmployee();
  void editEmployee(int);
  void deleteEmployee(int);
  void printall();
  void totalpay();
  void printany(int);
  void benefitmanager(int,int ,int);
  void assiagndeparttoemp(int ,department *);
  
private:
  employee **staff;
  unsigned int m_staffCount;
  unsigned int m_staffSize;
};

#endif // !HRSYSTEM_H
