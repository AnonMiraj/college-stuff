#ifndef CATALOG_H
#define CATALOG_H

#include "book.h"
#include "menu/bookmenu.h"
#include "menu/menu.h"
#include "menu/menuINP.h"
#include "DynamicContainer.h"
#include "book.h"
#include <fstream>
class Catalog {
public:
  Catalog();

  void addBook();
  void editBook(int index);
  void removeBook(int index);

  DynamicContainer<Book> searchBooks(const std::string &keyword);


  int sortMenu();

  int getTotalBooks() const;
  int getAvailableBooks() const;
  int getBorrowedBooks() const;
  void displayStatisticsMenu() ;

  void showList();
  void saveList();
  void loadList();

private:
  // std::vector<Book> Books;
  DynamicContainer<Book> books;
  int total_avalBooks;
};

#endif // CATALOG_H
