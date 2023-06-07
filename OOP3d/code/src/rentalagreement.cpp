
#include "rentalagreement.h"

using namespace std;
RentalAgreement::RentalAgreement()
  : m_rental_period(0), m_rental_rate(0), m_insurance_charges(0){}


RentalAgreement::RentalAgreement(int rental_period, double rental_rate, double insurance_charges)
  : m_rental_period(rental_period), m_rental_rate(rental_rate), m_insurance_charges(insurance_charges){}

int RentalAgreement::getRentalPeriod() const {
  return m_rental_period;
}

double RentalAgreement::getRentalRate() const {
  return m_rental_rate;
}

double RentalAgreement::getInsuranceCharges() const {
  return m_insurance_charges;
}
int RentalAgreement::get_rental_price()
{
    return m_rental_period*m_rental_rate+m_insurance_charges*2;
}


void RentalAgreement::readRentalAgreementData(int rentalPeriod)
{
    m_rental_period=rentalPeriod;  
    cout<<"Enter the Car's Rental Rate: "<<endl;
    cin>>m_rental_rate;
    cout<<"Enter the Car's Insurance Charges: "<<endl;
    cin>>m_insurance_charges;
}

void RentalAgreement::saveRentalAgreement()const{
std::fstream inpf;
  inpf.open("data.txt",std::ios::app);
      if (inpf.is_open()) {
        // Write data to the file
        inpf<<m_rental_rate<<" "<<m_insurance_charges<<endl;
        
    }
        // Close the file
        inpf.close();
  return;
}

double RentalAgreement::operator+(const RentalAgreement& other) {
  return m_rental_period * m_rental_rate + m_insurance_charges*2 + other.m_rental_period * other.m_rental_rate + other.m_insurance_charges*2;
}


ostream & operator<<(ostream &os,const RentalAgreement& rentalAgreement)
{
    os<<"Rental Period is "<<rentalAgreement.m_rental_period<<endl;
    os<<"Rental rate is "<<rentalAgreement.m_rental_rate<<endl;
    os<<"Insurance Charges are "<<rentalAgreement.m_insurance_charges<<endl;
    return os;
}
