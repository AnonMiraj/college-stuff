#include "commissionemployee.h"
// commissionEmployee class inheirted from employee
double commissionEmployee::getSalary() { return m_target * m_rate; }
void commissionEmployee::setDetails(int id) {
  employee::setDetails(id);
  m_jopTitle="COMMISSION";
  cout << "ENTER RATE : \n";
  cin >> m_rate;
  cout << "ENTER TARGET : \n";
  cin >> m_target;
}
string commissionEmployee::getDetails() {

  return employee::getDetails() + "\t TARGET : " + to_string(m_target) +
         "\t RATE : " + to_string(m_rate) +
         "\t SALARY : " + to_string(m_target * m_rate);
}
