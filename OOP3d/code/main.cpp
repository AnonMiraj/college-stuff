#include "carSys.h"
#include <sstream> // stringstream
#include <unistd.h>
// #include <windows.h>
#include <cstring>       // string, to_string
#include <iostream>      // cin, cout
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
    system("clear");
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




/** MAIN FUNCTION **/
int main() {
    CarSys rentalSystem;
    // rentalSystem.loadSys();
  // i gave up there is no hope and i have already lost my sanity 
  printline("START APPLICATION ....", 1);
  wait_or_clear(1, 0);
  int c = -1;
  while (c != 0) {
    // wait_or_clear(0, 1);
    printline("\n\nMAIN MENU ....", 1);
    c = get_menu_choise("ADD CAR ,ADD CUSTOMER ,RENT CAR ,DISPLAY CAR,DISPLAY EVERY CAR,CUSTOMER HISTORY ,PRINT REPORT",
                        0);

    switch (c) {
      case 1:
      rentalSystem.addCar();
      break;
    case 2:
      rentalSystem.addCustomer();
      break;
    case 3:
      rentalSystem.rentCar();
      break;
    case 4:
      rentalSystem.printCar();
      break;
    case 5:
      rentalSystem.printAllCars();
      break;
    case 6:
      rentalSystem.printCustomer();
      break;
    case 7:
      rentalSystem.printReport();
      break;
    case 0:
      printline("\n\n\a\t\t\tGoodbye :)......\n\n\n\n\n\n", 1);
      break;
    default:
      print_try_again();
      wait_or_clear(3, true);
    }
  }
      rentalSystem.saveSys();

  return 0;
}
