#include "department.h"
#include "benefit.h"
#include "dentalBenefit.h"
#include "healthBenefit.h"
#include <cstring>
#include <iostream>
using namespace std;
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class employee {
public:
  employee();
  virtual ~employee();
  void setId(int );
  virtual string getDetails();
  virtual void setDetails(int);
  virtual double getSalary() = 0;
  // virtual double calcPay() = 0;
  bool addBenefit();
  void editBenefit(int);
  void deleteBenefit(int);
  void getBenefit();  
  double totalBenefit();
  void setDepartment(department*);
protected:
  unsigned int m_id;
  string m_name;
  string m_phone;
  string m_email;
  string m_jopTitle;
  department *m_department;

  int m_benefitCount;
  int m_benefitSize;
  benefit **benefitList;
};

#endif // !EMPLOYEE_H
