#include "benefit.h"
#ifndef HEALTHBENEFIT_H
#define HEALTHBENEFIT_H

class healthBenefit : public benefit {
public:
  virtual double calculateBenefit();
  virtual string displayBenefit();
  virtual void setBenefit() ;

private:
  string m_coverge;
};


#endif // !HEALTHBENEFIT_H
