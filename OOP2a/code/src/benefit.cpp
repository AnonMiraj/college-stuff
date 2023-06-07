#include "benefit.h"
#include <string>
benefit::benefit() {
}
benefit::~benefit() {}
void benefit::setBenefit() {
  
  cout << "ENTER PLAN TYPE : \n";
  cin >> m_planType;
  cout << "ENTER INFO : \n";
  cin.ignore();
  getline(cin, m_info);
  cout << "ENTER AMOUNT : \n";
  cin >> m_amount;
}
string benefit::displayBenefit() {

  return  " \t PLAN : " + m_planType + "\t INFO : " + m_info;
}
