#include "healthBenefit.h"
//health benefit
void healthBenefit::setBenefit() {
  benefit::setBenefit();
  cout << "ENTER COVERGE : ";
  cin >> m_coverge;
}
string healthBenefit::displayBenefit() {

  return benefit::displayBenefit()  +
         "\t BENEFIT : " + to_string(m_amount * 0.3)+ "\t COVERGE : " + m_coverge;
}
double healthBenefit::calculateBenefit(){return m_amount*0.3;}

