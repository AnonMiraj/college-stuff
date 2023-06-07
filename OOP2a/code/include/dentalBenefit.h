#include "benefit.h"
#ifndef DENTALBENEFIT_H
#define DENTALBENEFIT_H

class dentalBenefit : public benefit {
public:
  virtual double calculateBenefit();
  virtual string displayBenefit();

};


#endif // !DENTALBENEFIT_H
