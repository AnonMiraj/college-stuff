#include "employee.h"
using namespace std;
#ifndef SALARIEDEMPLOYEE_H
#define SALARIEDEEMPLOYEE_H
// salariedEmployee and its child class

class salariedEmployee : public employee {
public:
  virtual string getDetails();
  virtual void setDetails(int);
  virtual double getSalary();
  // virtual double calcPay();

protected:
  double m_salary;
};

#endif // !SALARIEDEEMPLOYEE_H
