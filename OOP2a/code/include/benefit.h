#include <iostream>
#include <string>
using namespace std;
#ifndef BENEFIT_H
#define BENEFIT_H

class benefit {
public:
  benefit();
  virtual ~benefit();
  virtual double calculateBenefit() = 0;
  virtual string displayBenefit();
  virtual void setBenefit();

protected:
  string m_info;
  string m_planType;
  double m_amount;
};

#endif // !BENEFIT_H
