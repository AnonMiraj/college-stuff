#include "dentalBenefit.h"
#include <type_traits>
// dental benefit
string dentalBenefit::displayBenefit() {

  return benefit::displayBenefit() +
         "\t BENEFIT : " + to_string(m_amount * 0.2);
}
double dentalBenefit::calculateBenefit(){return m_amount*0.2;}

