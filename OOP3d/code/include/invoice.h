
#ifndef INVOICE_H
#define INVOICE_H

#include <fstream>
#include "rentalagreement.h"

class Invoice {
public:
  Invoice();
  Invoice(double m_taxes,RentalAgreement rental_agreement);

  // Getters
  double getRentalCharges() const;
  double getTaxes() const;
  double getTotalAmountDue() const;

  void readInvoiceData(int period);
  void saveInvoice()const;
  // output Overloaded
  std::ostream& operator <<(std::ostream &os);
  friend std::ostream & operator<<(std::ostream &os,Invoice& invoice);



  // Overloaded - operator for calculating the amount due
  double operator-(double amount_paid);

private:
  RentalAgreement m_rental_agreement;
  double m_rental_charges;
  double m_taxes;
  double m_total_amount_due;
};

#endif

