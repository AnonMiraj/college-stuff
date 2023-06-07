#include "hrSystem.h"

hrSystem::hrSystem(int size) {

  staff = new employee *[size];
  m_staffSize = size;
  m_staffCount = 0;
}
hrSystem::~hrSystem() {
  for (int i = 0; i < m_staffCount; i++) {
    delete staff[i];
  }
  delete[] staff;
}
void hrSystem::addEmployee() {
  char type;
  cout << "SELECT EMPLOYEE TYPE";
  cout
      << "\n (HOURLY[H] COMMISSION[C] SALARIED[S] MANGER[M] { 1 , 2 , 3 , 4 })";
  cin >> type;
  switch (type) {
  case '1':
  case 'H':
  case 'h':
    staff[m_staffCount] = new hourlyEmployee();
    break;
  case '2':
  case 'C':
  case 'c':
    staff[m_staffCount] = new commissionEmployee();
    break;
  case '3':
  case 'S':
  case 's':
    staff[m_staffCount] = new salariedEmployee();
    break;
  case '4':
  case 'M':
  case 'm':
    staff[m_staffCount] = new managerEmployee();
    break;
  default:
    cout << "INVAILD CHOICE";
    return;
  }
  staff[m_staffCount]->setDetails(m_staffCount + 1);
  for (; 1;) {
    cout << "ADD BENEFIT (y/N) ";
    char temp;
    cin >> temp;
    if ((temp == 'n' || temp == 'N') || !staff[m_staffCount]->addBenefit())
      break;
  }
  m_staffCount++;
}
void hrSystem::editEmployee(int id) {
if (id - 1 >= m_staffCount || id - 1 < 0) {
    cout << "\tINVALID ID\n";
    return;
  }
  cout << staff[id - 1]->getDetails() << '\n';
  cout << "\tCONFRIM EDITING (y/N)";
  char yes;
  cin >> yes;
  if (yes == 'y' || yes == 'Y')
    staff[id - 1]->setDetails(id);
}
void hrSystem::deleteEmployee(int id) {
if (id - 1 >= m_staffCount || id - 1 < 0) {
    cout << "\tINVALID ID\n";
    return;
  }

  // delete employee

  char y = 0;
  cout << staff[id - 1]->getDetails();
  cout << "\nCONFIRM PROCESS (y/N)\n";
  cin >> y;
  if (y == 'y' || y == 'Y') {
    for (int j = id; j < m_staffCount; ++j) {
      staff[j - 1]->setId(j - 1);
      staff[j - 1] = staff[j];
    }
    staff[m_staffCount - 1]->setId(m_staffCount - 1);
    m_staffCount--;
  }
}
void hrSystem::printany(int id) {
  if (id - 1 >= m_staffCount || id - 1 < 0) {
    cout << "\tINVALID ID\n";
    return;
  }
  cout << staff[id - 1]->getDetails() << "\n";
  staff[id - 1]->getBenefit();
  cout << "\n TOTAL BENEFIT : " << staff[id - 1]->totalBenefit() << "$\n";
}
void hrSystem::printall() {
  for (int i = 0; i < m_staffCount; i++) {
    printany(i + 1);
  }
}

void hrSystem::totalpay() {
  double totalpay = 0, totalbenefit = 0;

  for (int i = 0; i < m_staffCount; i++) {
    totalpay += staff[i]->getSalary();
    totalbenefit += staff[i]->totalBenefit();
  }
  cout << "\n"
       << "TOTAL SALARY : " << fixed << setprecision(5) << totalpay << "$\n";
  cout << "TOTAL BENEFIT :" << fixed << setprecision(5) << totalbenefit
       << "$\n";
  cout << "AVERAGE PAY PER EMPLOYEE : " << fixed << setprecision(5)
       << (totalpay + totalbenefit) / m_staffCount << "$\n";
  cout << "TOTAL AMOUNT : " << fixed << setprecision(5)
       << totalpay + totalbenefit << "$\n";
}
void hrSystem::benefitmanager(int id, int choice, int num) {
  if (id - 1 >= m_staffCount || id - 1 < 0) {
    cout << "\tINVALID ID\n";
    return;
  }
  switch (choice) {
  case 1:
    staff[id]->addBenefit();
    break;
  case 2:
    staff[id]->editBenefit(num);
    break;
  case 3:
    staff[id]->deleteBenefit(num);
  }
}
void hrSystem::assiagndeparttoemp(int id, department *Pdep) {
  if (id - 1 < 0 || id - 1 >= m_staffCount) {
    cout << "INVAILD ID";
    return;
  }
  staff[id - 1]->setDepartment(Pdep);
}
