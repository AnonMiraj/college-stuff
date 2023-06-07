#include "employee.h"
employee::employee() {
  m_department = nullptr;
  m_benefitSize = 10;
  m_benefitCount = 0;
  benefitList = new benefit *[m_benefitSize];
}
employee::~employee() {
  for (int i = 0; i < m_benefitCount; i++) {
    delete benefitList[i];
  }
  delete[] benefitList;
}
void employee::setDetails(int id) {
  string temp;
  m_id = id;
  cin.ignore();
  cout << "ENTER NAME : \n";
  getline(cin, temp);
  m_name = temp;
  cout << "ENTER EMAIL : \n";
  cin >> m_email;
  cout << "ENTER PHONE : \n";
  cin >> m_phone;
}

string employee::getDetails() {

  return "ID : " + to_string(m_id) + "\t NAME : " + m_name +
         "\t EMAIL : " + m_email + "\t PHONE : " + m_phone +
         "\t TITLE : " + m_jopTitle +
         (m_department != nullptr ? "\t DEPARTMENT : " + m_department->getname()
                                  : "");
}
void employee::setId(int id) { m_id = id; }
void employee::setDepartment(department *Pdep){
  m_department=Pdep;
}
bool employee::addBenefit() {
  cout << "\n CHOOSE BENEFIT TYPE";
  cout << "\n\t DENTAL[D] HEALTH[H] { 1 , 2 }";
  char ch;
  cin >> ch;
  switch (ch) {
  case 'D':
  case 'd':
  case '1':
    benefitList[m_benefitCount] = new dentalBenefit();
    break;
  case 'H':
  case 'h':
  case '2':
    benefitList[m_benefitCount] = new healthBenefit();
    break;
  default:
    cout << "INVALID CHOICE";
    return true;
  }
  benefitList[m_benefitCount++]->setBenefit();
  if (m_benefitCount == 10)
    return false;
  return true;
}
void employee::getBenefit() {
  double total = 0;
  for (int i = 0; i < m_benefitCount; i++)
    cout << i + 1 << "- " << benefitList[i]->displayBenefit() << "\n";
}
void employee::editBenefit(int num) {
  if (num  > m_benefitCount) {
    cout << "\tTHIS BENEFIT DOES NOT EXIST\n";
    return;
  }

  cout << num  << "- " << benefitList[num-1]->displayBenefit() << '\n';
  cout << "\tCONFRIM EDITING (y/N)";
  char yes;
  cin >> yes;
  if (yes == 'y' || yes == 'Y')
    benefitList[num-1]->setBenefit();
}
void employee::deleteBenefit(int num) {
  if (num>m_benefitCount) {
    cout << "THIS BENEFIT DOES NOT EXIST\t";
    return;
  }

  char yes = 0;
  cout << num  << "- " << benefitList[num-1]->displayBenefit() << '\n';
  cout << "\nCONFIRM PROCESS (y/N)\n";
  cin >> yes;
  if (yes == 'y' || yes == 'Y') {
    for (int j = num; j < m_benefitCount; j++) {
      benefitList[j - 1] = benefitList[j];
    }
    m_benefitCount--;
  }
}
double employee::totalBenefit() {
  double total = 0;
  for (int i = 0; i < m_benefitCount; i++) {
    total += benefitList[i]->calculateBenefit();
  }
  return total;
}
