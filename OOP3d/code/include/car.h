#ifndef CAR_H
#define CAR_H

#include <cwctype>
#include <string>
#include <fstream>

class Car {
public:
  Car();
  Car(int ID,const std::string& make, const std::string& model, int year);

  // Getters and setters
  const std::string& getMake() const;
  const std::string& getModel() const;
  int getYear() const;
  int getId() const;
  void readCarData();
  void saveCar();
  void loadCar(int Id,std::string make ,std::string model ,int year);
  // Overloaded << operator
  friend std::ostream& operator<<(std::ostream& os, const Car& car);

private:
  int m_id;
  std::string m_make;
  std::string m_model;
  int m_year;
  bool m_available;
};

#endif //!CAR_H
