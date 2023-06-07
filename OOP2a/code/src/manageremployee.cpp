#include "manageremployee.h"
// mangerEmployee class inheirted from salariedEmployee
double managerEmployee::getSalary() { return m_salary * m_bouns; }
void managerEmployee::setDetails(int id){
  salariedEmployee::setDetails(id);
  m_jopTitle="MANAGER";
  cout<<"ENTER BOUNS : \n";
  cin>>m_bouns;
}
string managerEmployee::getDetails() {
  return employee::getDetails() + "\t BOUNS : " + to_string(m_bouns) +
         "\t SALARY : " + to_string(m_salary * m_bouns);
}
void managerEmployee::addBouns(double moreBouns) { m_bouns += moreBouns; }
