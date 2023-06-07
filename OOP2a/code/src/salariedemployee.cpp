#include "salariedemployee.h"

// salariedEmployee class inheirted from employee
//
double salariedEmployee::getSalary() { return m_salary; }
void salariedEmployee::setDetails(int id) {
  employee::setDetails(id);
  m_jopTitle="SALARIED";
  cout << "ENTER SALARY : \n";
  cin>>m_salary;
}
string salariedEmployee::getDetails() {

  return employee::getDetails() + "\t SALARY : " + to_string(m_salary);
}
