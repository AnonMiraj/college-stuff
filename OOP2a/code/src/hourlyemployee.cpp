#include "hourlyemployee.h"


// hourlyEmployee class inheirted from employee
double hourlyEmployee::getSalary() { return m_hourWorked * m_rate; }
void hourlyEmployee::setDetails(int id) {
  employee::setDetails(id);
  int temp;
  m_jopTitle="HOURLY";
  cout << "ENTER RATE : \n";
  cin >> m_rate;
  cout << "ENTER HOURWORKED : \n";
  cin >> m_hourWorked;
}
string hourlyEmployee::getDetails() {

  return employee::getDetails() +
         "\t HOUR WORKED : " + to_string(m_hourWorked) +
         "\t RATE : " + to_string(m_rate) +
         "\t SALARY : " + to_string(m_hourWorked * m_rate);
}
// double hourlyEmployee::calcPay() {}
void hourlyEmployee::addHours(double moreHours) { m_hourWorked += moreHours; }
