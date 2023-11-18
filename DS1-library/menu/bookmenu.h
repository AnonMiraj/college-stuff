#pragma once
#include "../DynamicContainer.h"
#include "../book.h"

#include "editorkey.h"

#include "func.h"
#include <algorithm>
#include <cstddef>
#include <cstdio>
#include <fstream>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;

inline void displayHelpMenu() {
  cout << "\033[2J\033[1;1H";

  cout << "-------- Help Menu --------\n";
  cout << "?            Show this help menu\n";
  cout << "↑/↓:         Move selection up/down\n";
  cout << "Enter:       Toggle between reading and not reading status\n";
  cout << "a [a]dd:     Add a new book to the catalog\n";
  cout << "e [e]dit:    Edit book details\n";
  cout << "R [R]emove:  Remove the selected book\n";
  cout << "s [s]ort:    Sort the book list\n";
  cout << "r [r]everse: Reverse the book list\n";
  cout << "S [S]tats:   Display book statistics\n";
  cout << "q [q]uit:    quit the program\n";
  cout << "---------------------------\n";
  getch();
}
class bookItem {
public:
  string name;
  Book *bookitem;
  int y;
  bookItem() {
    bookitem = NULL;
    y = 0;
  }

  bookItem(Book &bookadd) {
    bookitem = &bookadd;
    y = 0;
  }
  void display();
  void disp_selected();
};
inline void bookItem::display() {
  cout << std::left << std::setw(y) << bookitem->getTitle() << std::setw(y)
       << bookitem->getAuthor() << std::setw(y) << bookitem->getGenre()
       << std::setw(y) << bookitem->getISBN() << std::setw(y)
       << (!bookitem->isAvailable() ? "COMPLETED" : "NOT READ") << endl;
}
inline void bookItem::disp_selected() {
  cout << "\033[31;1;4m" << std::left << std::setw(y) << bookitem->getTitle()
       << std::setw(y) << bookitem->getAuthor() << std::setw(y)
       << bookitem->getGenre() << std::setw(y) << bookitem->getISBN()
       << std::setw(y) << (!bookitem->isAvailable() ? "COMPLETED" : "NOT READ")
       << "\033[0m" << endl;
}

class booklist {
  bookItem head;
  std::vector<bookItem> entries;
  int num, start, end, listLim;
  int selected;
  DynamicContainer<Book> *Booklist;

public:
  int sort, rev;
  booklist() : num(0), selected(0), sort(0), rev(0) {
    listLim = (getmax_x() / 3) / 10 * 10;
    start = 0, end = listLim;
  }
  booklist(DynamicContainer<Book> *bookadd)
      : num(0), selected(0), sort(0), rev(0) {

    listLim = (getmax_x() / 3) / 10 * 10;
    start = 0, end = listLim;
    Booklist = bookadd;
    for (int i = 0; i < Booklist->size(); i++) {
      add((Booklist->begin() + i));
    }
  }
  void add(Book *bookadd);
  void displayHead(int);
  int display();
  int getCurrent();
};

inline void booklist::add(Book *bookadd) {
  num++;
  entries.push_back(bookItem(*bookadd));
}

inline void booklist::displayHead(int max_y) {
  string list[6] = {"", "TITLE", "AUTHOR", "GENRE", "ISBN", "STATE"};
  cout << string(max_y, '-') << endl;
  cout << std::left;

  for (int i = 1; i <= 5; i++) {
    int cellWidth = max_y / 5;
    if (i == sort - 1) {
      if (rev) {
        cout << "|\033[1;34m" + list[i] + "↑\033[0m";
      } else {
        cout << "|\033[1;34m" + list[i] + "↓\033[0m";
      }
      int spaces = cellWidth - list[i].length() - 1;
      for (int j = 1; j < spaces; j++) {
        cout << " ";
      }
    } else {
      cout << "|" + list[i];
      int spaces = cellWidth - list[i].length();
      for (int j = 1; j < spaces; j++) {
        cout << " ";
      }
    }
  }

  cout << std::right << "|";
  cout << endl;

  cout << string(max_y, '-') << endl;
}
inline int booklist::getCurrent(){
  return selected;
}

inline int booklist::display() {
  // hideCursor();
  // system("clear");
  cout << "\033[2J\033[1;1H";
  int opt = 66, last_x = getmax_x(), last_y = getmax_y();
  while (true) {
    int max_y = getmax_y(), i;
    head.y = (max_y - head.name.size()) / 2;
    for (bookItem &a : entries) {
      a.y = (max_y / 5);
    }
    int max_x = getmax_x();

    cout << "\033[2J\033[1;1H";
    if (!(max_x == last_x && max_y == last_y)) {
      last_x = max_x;
      last_y = max_y;
    }
    int x = (max_x - num) / 2 - 2;
    gotoxy(0, 0);
    // for (i = 2; i < x / 2; i++)
    // cout << endl;
    displayHead(max_y);
    // cout.width(head.y + 2 * head.name.size());
    // cout << num;
    // cout << "**********";
    cout << "\n";
    if (start) {
      cout << string(max_y / 2, ' ') << "\033[31;1;4m↑\n\n\033[0m";

    } else {
      cout << "\n\n";
    }
    for (i = start; i < end; i++) {
      if (i == selected)
        entries[i].disp_selected();
      else
        entries[i].display();
    }
    cout << "\n";

    if (end != num) {
      cout << string(max_y / 2, ' ') << "\033[31;1;4m↓\n\033[0m";
    } else {
      cout << "\n";
    }

    cout << "\n\n\n\n\n";
    cout << "Desription: " << entries[selected].bookitem->getDesc();
    cout << '\n';
    printf("\033[%d;1H", max_x-1);
    cout << "Press \"?\" for a help menu" << std::right << std::setw(max_y - 28)
         << selected + 1 << "/" << num;
    opt = getch();
    switch (opt) {
    case 'q':
      return 0;
    case 10:
      if (entries[selected].bookitem->toggleAvailable()) {
        return 1;
      } else {
        return 2;
      }
    case 's':
      start = 0;
      end = listLim;
      selected = 0;
      return 3;
    case 'r':
      start = 0;
      end = listLim;
      selected = 0;
      return 4;
    case 'a':
      return 5;
    case 'e':
      return 6;
    case 'R':
      {
        cout<<"are you sure you want to delete ? press R again";
        if (getch()!='R') {
        break; 
        }
      }
      return 7;
    case 'S':
      return 8;




    case '?':
      displayHelpMenu();
      break;
    case 66:
      selected++;
      break;
    case 65:
      selected--;
      break;
    }
    if (selected == num) {
      start = 0;
      end = listLim;
      selected = 0;
    }
    if (selected == -1) {
      start = num - listLim;
      end = num;
      selected = num - 1;
    }
    if (selected == end && end != num) {
      end++;
      start++;
    }
    if (selected == start && start != 0) {
      end--;
      start--;
    }
  }
  showCursor();
}
