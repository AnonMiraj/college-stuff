#include <iostream>
#include <string>
using namespace std;
#ifndef DEPARTMENT_H
#define DEPARTMENT_H
class department {
public:
  department();
  department(unsigned int, string);

  virtual ~department();
  void read();
  void print();
  string getname();
  int getId();
private:
  unsigned int m_id;
  string m_name;
};

#endif // !DEPARTMENT_H
