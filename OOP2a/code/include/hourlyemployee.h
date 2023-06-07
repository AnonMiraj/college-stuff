#include "employee.h"
#include <iostream>
#include <string>
using namespace std;
#ifndef HOURLYEMPLOYEE_H
#define HOURLYEMPLOYEE_H

class hourlyEmployee : public employee {
public:
  virtual string getDetails();
  virtual void setDetails(int);
  virtual double getSalary();
  // virtual double calcPay();
  void addHours(double );

private:
  double m_hourWorked;
  double m_rate;
};

#endif // !HOURLYEMPLOYEE_H

