#include "catalog.h"
#include "book.h"
#include "menu/bookmenu.h"
#include "menu/menu.h"
#include "menu/menuINP.h"
#include <algorithm>
#include <iostream>
#include <string>

Catalog::Catalog() { total_avalBooks = 0; }

void Catalog::addBook() {
  std::string title = "";
  std::string author = "";
  std::string ISBN = "";
  std::string genre = "";
  std::string desc = "";
  menuINP obj;
  obj.menu_head("enter book information");
  obj.add("title", title);
  obj.add("author", author);
  obj.add("ISBN", ISBN);
  obj.add("genre", genre);
  obj.add("desc", desc);
  bool success = obj.display();
  if (success) {
    Book book(books.size() + 1, title, author, ISBN, genre, desc, 1);
    books.push_back(book);
  }
}
void Catalog::editBook(int index) {
  std::string title = books[index].getTitle();
  std::string author = books[index].getAuthor();
  std::string ISBN = books[index].getISBN();
  std::string genre = books[index].getGenre();
  std::string desc = books[index].getDesc();
  menuINP obj;
  obj.menu_head("edit book information");
  obj.add("title", title);
  obj.add("author", author);
  obj.add("ISBN", ISBN);
  obj.add("genre", genre);
  obj.add("desc", desc);
  bool success = obj.display();
  if (success) {
    books[index] =
        Book(books[index].getInd(), title, author, ISBN, genre, desc, 1);
  }
}
void Catalog::removeBook(int index) { books.remove_at(index); }
DynamicContainer<Book> Catalog::searchBooks(const std::string &keyword) {
  DynamicContainer<Book> results;
  for (const Book &book : books) {
    if (book.getTitle().find(keyword) != std::string::npos ||
        book.getAuthor().find(keyword) != std::string::npos ||
        book.getISBN().find(keyword) != std::string::npos ||
        book.getGenre().find(keyword) != std::string::npos) {
      results.push_back(book);
    }
  }
  return results;
}

int Catalog::sortMenu() {
  menu obj;
  obj.menu_head("sorting by?");
  obj.add("NO SORT");
  obj.add("TITLE");
  obj.add("AUTHOR");
  obj.add("GENRE");
  obj.add("ISBN");
  int x = obj.display();
  switch (x) {
  case 1:
    books.sort(
        [](const Book &a, const Book &b) { return a.getInd() < b.getInd(); });
    break;
  case 2:
    books.sort([](const Book &a, const Book &b) {
      return a.getTitle() < b.getTitle();
    });
    break;
  case 3:
    books.sort([](const Book &a, const Book &b) {
      return a.getAuthor() < b.getAuthor();
    });
    break;
  case 4:
    books.sort([](const Book &a, const Book &b) {
      return a.getGenre() < b.getGenre();
    });
    break;
  case 5:
    books.sort(
        [](const Book &a, const Book &b) { return a.getISBN() < b.getISBN(); });
    break;
  }
  return x;
}
int Catalog::getTotalBooks() const { return books.size(); }

int Catalog::getAvailableBooks() const { return total_avalBooks; }

int Catalog::getBorrowedBooks() const {
  return getTotalBooks() - getAvailableBooks();
}
void Catalog::displayStatisticsMenu() {
  cout << "\033[2J\033[1;1H";
  cout << "---- Statistics Menu ----\n";
  cout << "Total Books: " << this->getTotalBooks() << "\n";
  cout << "Completed Books: " << this->getAvailableBooks() << "\n";
  cout << "Not Read Books: " << this->getBorrowedBooks() << "\n";
  cout << "-------------------\n";
  getch();
}

void Catalog::showList() {
resetMenu:
  booklist s(&books);
  books.sort(
      [](const Book &a, const Book &b) { return a.getInd() < b.getInd(); });
  int x = -1;
  while (x) {

    x = s.display();
    switch (x) {
    case 1:
      total_avalBooks--;
      break;
    case 2:
      total_avalBooks++;
      break;
    case 3:
      s.sort = sortMenu();
      if (s.rev) {
        books.reverse();
      }
      break;
    case 4:
      s.rev = !s.rev;
      books.reverse();
      break;
    case 5:
      this->addBook();
      goto resetMenu;
    case 6:
      this->editBook(s.getCurrent());
      goto resetMenu;
    case 7:
      this->removeBook(s.getCurrent());
      goto resetMenu;
    case 8:
      this->displayStatisticsMenu();
      goto resetMenu;
    }
  }
}
void Catalog::saveList() {
  int cnt = 0;
  std::ofstream oupt("./data/books.txt", std::ios::out);

  if (oupt.is_open()) {
      oupt << total_avalBooks << endl;
    for (int i = 0; i < books.size(); i++) {

      oupt << cnt + 1 << endl;
      oupt << books[i].getTitle() << endl;
      oupt << books[i].getAuthor() << endl;
      oupt << books[i].getGenre() << endl;
      oupt << books[i].getISBN() << endl;
      oupt << books[i].getDesc() << endl;
      oupt << books[i].isAvailable() << endl;
      cnt++;
    }
  }
  oupt.close();
}

void Catalog::loadList() {
  int ind, avalbooks;
  string title, author, genre, isbn, desc;
  bool aval;
  std::ifstream inp("./data/books.txt");
  if (inp.is_open()) {

    inp>>avalbooks;
    while (inp >> ind) {
      inp.ignore();
      std::getline(inp, title);
      std::getline(inp, author);
      std::getline(inp, isbn);
      std::getline(inp, genre);
      std::getline(inp, desc);

      // inp.ignore();
      inp >> aval;
      books.push_back(Book(ind, title, author, genre, isbn, desc, aval));
      total_avalBooks = avalbooks;
    }
  } else

    cout << "FUCK";
  inp.close();
}
