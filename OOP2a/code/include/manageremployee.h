#include "salariedemployee.h"
using namespace std;
#ifndef MANAGEREMPLOYEE_H
#define MANAGEREEMPLOYEE_H
class managerEmployee : public salariedEmployee { // with what i am doing make it a derived class from salariedEmployee is useless but whatever
public:
  virtual string getDetails();
  virtual void setDetails(int);
  virtual double getSalary();
  // virtual double calcPay();
  void addBouns(double );

protected:
  double m_bouns;
};
#endif // !MANAGEREEMPLOYEE_H
