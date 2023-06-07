#include "department.h"
#include "employee.h"
#include "hrSystem.h"
#include <bits/stdc++.h> // stringstream
#include <cstring>       // string, to_string
#include <iostream>      // cin, cout
#include <string>
using namespace std;
void _pause() {
  cin.ignore();
  do {
    cout << '\n' << "Press the Enter key to continue.";
  } while (cin.get() != '\n');
}
/** ASSISTANT INLINE FUNCTIONS **/
inline void wait_or_clear(unsigned int sec, bool clear_screen = false) {
  sleep(sec);
  if (clear_screen)
    system("clr");
}

inline void printline(string msg, bool end_line = true) {
  cout << msg << (end_line ? "\n" : "\t");
}

inline void print_try_again() {
  printline("\n\n\n\aInvalid Choice Try Again!!!!!!!!", 1);
  wait_or_clear(3, 1);
}

/** MAIN PRINT MENU FUNCTION **/
int get_menu_choise(string menu, int level = 0) {
  stringstream X(menu);
  string line, padding;
  int i = 1;
  for (int p = 0; p < level + 1; ++p)
    padding += "\t";

  while (getline(X, line, ','))
    printline(padding + to_string(i++) + ". " + line, 1);

  printline(level ? padding + "0. RETURN BACK" : padding + "0. EXIT APP", 1);
  int c;
  printline("ENTER YOUR CHOICE :", false);
  cin >> c;
  return c;
}
// data inilization (department & staff)
unsigned int depart_size = 10;
unsigned int depart_count = 0;
department *depart = new department[depart_size];

hrSystem staff(100);
/** Department SUB MENU  **/
void sub_menu_1_department_management() {
  int c = -1;
  while (c != 0) {
    wait_or_clear(0, 1);
    int depId, depIdx = -1, empID;
    char yes = 'y';
    printline("\n\nMAIN MENU -> DEPARTMENT MANAGEMENT ....");
    c = get_menu_choise("ADD,PRINT,ASSIGN EMPLOYEE", 1);
    switch (c) {
    case 1:
      if (depart_count < depart_size)
        depart[depart_count++].read();
      else
        printline("MAXED THE SIZE");
      _pause();
      break;
    case 2:
      for (auto i = 0; i < depart_count; i++)
        depart[i].print();

      _pause();
      break;
    case 3:

      printline("ENTER DEPARTMENT ID : ");
      cin >> depId;

      for (int i = 0; i < depart_count; i++) {
        if (depId == depart[i].getId()) {
          depIdx = i;
          break;
        }
      }
      if (depIdx == -1) {
        cout << "INVAILD ID";
        return;
      }
      while (yes == 'y' || yes == 'Y') {

        printline("ENTER EMPLOYEE ID : ");
        cin >> empID;
        staff.assiagndeparttoemp(empID, &depart[depId]);

        printline("AGAIN (y/N) ");
        cin >> yes;
      }
      break;
    case 0:
      return;
    default:
      print_try_again();
    }
  }
}

/** DATA ENTRY AND SUB MENU **/
void sub_sub_menu_1_benefits_management(int id) {
  int c = -1, num = 0;
  while (c != 0) {
    wait_or_clear(0, 1);
    printline(
        "\n\nMAIN MENU -> EMPLOYEE MANAGEMENT["+to_string(id+1)+"] -> BENEFITS MANAGEMENT ....");
    c = get_menu_choise("ADD BENEFIT,EDIT BENEFIT,DELETE BENEFIT", 1);
    if (c > 1) {

      printline("ENTER BENEFIT NUMBER :");
      cin >> num;
    }
    switch (c) {
    case 1:
      staff.benefitmanager(id, 1, 0);
      break;
    case 2:
      staff.benefitmanager(id, 2, num);
      break;
    case 3:
      staff.benefitmanager(id, 3, num);
      break;
    case 0:
      return;
    default:
      print_try_again();
    }
  }
}

void sub_menu_2_employee_management() {
  int c = -1;
  while (c != 0) {
    wait_or_clear(0, 1);
    printline("\n\nMAIN MENU -> EMPLOYEE MANAGEMENT ....");
    c = get_menu_choise("ADD,EDIT,DELELE,BENEFIT MANAGEMENT", 2);
    int id;
    if (c > 1) {

      printline("ENTER EMPLOYEE Id :");
      cin >> id;
    }
    switch (c) {
    case 1:

      staff.addEmployee();
      _pause();
      break;
    case 2:
      staff.editEmployee(id);
      _pause();
      break;
    case 3:
      staff.deleteEmployee(id);
      _pause();
      break;
    case 4:
      sub_sub_menu_1_benefits_management(id - 1);
      break;
    case 0:
      return;
    default:
      print_try_again();
    }
  }
}

/** REPORTING CALCULATION AND SUB MENU **/

void sub_menu_3_REPORTING() {
  int c = -1;
  while (c != 0) {
    wait_or_clear(0, 1);
    printline("\n\nMAIN MENU -> REPORTING ....");
    c = get_menu_choise("STAFF LIST,PAY,EMPLOYEE REPORT", 1);
    int id;
    if (c == 3) {

      printline("ENTER EMPLOYEE Id :");
      cin >> id;
    }
    switch (c) {
    case 1:
      staff.printall();
      _pause();
      break;
    case 2:
      staff.totalpay();
      _pause();
      break;
    case 3:
      staff.printany(id);
      _pause();
      break;
    case 0:
      return;
    default:
      print_try_again();
    }
  }
}

/** MAIN FUNCTION **/
int main() {
  printline("START APPLICATION ....", 1);
  wait_or_clear(1, 1);
  int c = -1;
  while (c != 0) {
    wait_or_clear(0, 1);
    printline("\n\nMAIN MENU ....", 1);
    c = get_menu_choise("DEPARTMENT MANAGEMENT,EMPLOYEE MANAGEMENT,REPORTING",
                        0);

    switch (c) {
    case 1:
      sub_menu_1_department_management();
      break;
    case 2:
      sub_menu_2_employee_management();
      break;
    case 3:
      sub_menu_3_REPORTING();
      break;
    case 0:
      printline("\n\n\a\t\t\tGoodbye :)......\n\n\n\n\n\n", 1);
      break;
    default:
      print_try_again();
      wait_or_clear(3, true);
    }
  }
  return 0;
}
// pink red purple black
// white blue cyan violet crimson gray orange yellow green darkgreen darkred
// brown coral azure beige maroon lime aqua aquamarine indigo teal
// turquoise ivory fuchsia gold silver  #efa0ea #aaaaaa  #f80000
// #3b83bd
