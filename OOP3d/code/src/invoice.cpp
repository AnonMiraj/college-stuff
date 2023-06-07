#include "invoice.h"
#include <cmath>
#include <string>

using namespace std;

Invoice::Invoice()
    :  m_rental_charges(0), m_taxes(0),
      m_total_amount_due(0) {}

Invoice::Invoice(double taxes,RentalAgreement rental_agreement)
    : m_taxes(taxes), m_rental_agreement(rental_agreement) {
}

double Invoice::getRentalCharges() const { return m_rental_charges; }

double Invoice::getTaxes() const { return m_taxes; }

double Invoice::getTotalAmountDue() const { return m_total_amount_due; }

void Invoice::readInvoiceData(int period) {
  m_rental_agreement.readRentalAgreementData(period);
  cout << "Enter taxes on the car: " << endl;
  cin >> m_taxes;
  
  m_rental_charges = m_rental_agreement.getRentalPeriod() *
                         m_rental_agreement.getRentalRate() +
                     m_rental_agreement.getInsuranceCharges();
  m_total_amount_due = m_rental_charges + m_taxes;
}

void Invoice::saveInvoice()const{
std::fstream inpf;
  inpf.open("data.txt",std::ios::app);
      if (inpf.is_open()) {
        // Write data to the file
        inpf<<m_taxes<<endl;
        // Close the file
        inpf.close();
        m_rental_agreement.saveRentalAgreement();
    }
}


double Invoice::operator-(double amount_paid) {
  return m_total_amount_due - amount_paid;
}

ostream &operator<<(ostream &os, Invoice &invoice) {
  os << "Taxes are " << invoice.m_taxes << endl;
  os << "Rental Agreement details are: " << endl;
  os << invoice.m_rental_agreement << endl;
  os << "total amount due is " << invoice.getTotalAmountDue();
  return os;
}
