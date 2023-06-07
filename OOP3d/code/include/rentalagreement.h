
#ifndef RENTALAGREEMENT_H
#define RENTALAGREEMENT_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>


class RentalAgreement {
public:
  RentalAgreement();
  RentalAgreement(int rental_period, double rental_rate, double insurance_charges );

  // Getters
  int getRentalPeriod() const;
  double getRentalRate() const;
  double getInsuranceCharges() const;
  int get_rental_price();

  void readRentalAgreementData(int rentalPeriod);
  void saveRentalAgreement()const;
  // Overloaded + operator for calculating rental charges
  double operator+(const RentalAgreement& other);
  friend std::ostream & operator<<(std::ostream &os,const RentalAgreement &rentalagreement);


private:
  int m_rental_period;
  double m_rental_rate;
  double m_insurance_charges;
};

#endif
