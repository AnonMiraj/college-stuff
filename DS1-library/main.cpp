#include "catalog.h"
#include "menu/menu.h"
#include <cstdlib>
#include <iostream>
#include <string>
// using std::cin;
// using std::cout;
int main() {
  Catalog catalog;
  catalog.loadList();
  menu obj;
  obj.menu_head("bookery");
  obj.add("Add Book", 1, "Add a new book to the catalog.");
  obj.add("Book list", 2, "Displays a list of all books in the catalog, along with their details.");
  // obj.add("Search Books", 3,"Search for books by title, author, ISBN, or genre.");
  obj.add("Save and Exit", 3, "Exit and Save the program.");
  obj.add("Exit", 4, "Exit the program.");
  int x = -1;
  while (x != 0) {
    x = obj.display();
    switch (x) {
    case 1:
      catalog.addBook();
      break;
    case 2:
      catalog.showList();
      break;
    case 3:
      catalog.saveList();
    case 4:
  return 0;
      break;
    }
  }

  return 0;
}
