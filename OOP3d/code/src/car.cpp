#include "car.h"
#include "reservation.h"
#include <iostream>

using namespace std;
Car::Car() : m_make(""), m_model(""), m_year(0) {
}

Car::Car(int ID, const string &make, const string &model, int year)
    : m_id(ID), m_make(make), m_model(model), m_year(year){

}

void Car::readCarData() {
  cout << "Enter Car's ID: " << endl;
  cin >> m_id;
  cout << "Enter Car's brand" << endl;
  cin >> m_make;
  cout << "Enter Car's Model: " << endl;
  cin >> m_model;
  cout << "Enter Car's Year of Production: " << endl;
  cin >> m_year;
}

const string &Car::getMake() const { return m_make; }

const string &Car::getModel() const { return m_model; }

int Car::getYear() const { return m_year; }

int Car::getId() const { return m_id; }

void Car::saveCar(){
  std::fstream inpf;
  inpf.open("data.txt",std::ios::app);
      if (inpf.is_open()) {
        // Write data to the file
        inpf<<m_id<<" " << m_make <<" " << m_model << " "<< m_year <<endl;

        // Close the file
        inpf.close();
    } else {
        std::cout << "Failed to open the file." << std::endl;
    }


}


ostream &operator<<(ostream &os, const Car &car) {
  os << car.m_id <<" "<< car.getMake() << " " << car.getModel() << " (" << car.getYear() << ") ";
  return os;
}
