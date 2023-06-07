#include "department.h"
department::department() {}
department::department(unsigned int, string) {}
department::~department() {}
void department::read() {
  cout << "Enter ID: ";
  cin >> m_id;
  cout << "Enter Name: ";
  cin >> m_name;
}
void department::print() {
  cout<<"ID: "<<m_id<<"\t"<<m_name<<"\n";
}
string department::getname(){return m_name;}
int department::getId(){return m_id;}
