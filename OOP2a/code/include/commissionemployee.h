#include "employee.h"
using namespace std;
#ifndef COMMISSIONEMPLOYEE_H
#define COMMISSIONEMPLOYEE_H


class commissionEmployee : public employee {
public:
  virtual string getDetails();
  virtual void setDetails(int);
  virtual double getSalary();
  // virtual double calcPay();

private:
  double m_target;
  double m_rate;
};

#endif // !COMMISSIONEMPLOYEE_H
