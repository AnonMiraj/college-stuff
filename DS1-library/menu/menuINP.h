#pragma once
#include "editorkey.h"
#include "func.h"
#include <cstddef>
#include <cstdio>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;

class itemINP {
public:
  string name;
  string *var;
  string origstr;
  int y;
  itemINP() {
    name = " ";
    y = 0;
    var = NULL;
    origstr = "";
  }
  itemINP(string s1) {
    name = s1;
    y = 0;
    var = NULL;
    origstr = "";
  }
  itemINP(string s1, string &varadd) {
    name = s1;
    var = &varadd;
    origstr = varadd;
  }
  void display();
  void displayinput();
  void disp_selected();
  void disp_selectedinput();
};

inline void itemINP::display() {
  cout << std::setw(y + (name.size())) << name << "  \n";
}

inline void itemINP::displayinput() {
  cout << std::setw(0.6 * y + (name.size())) << name << ": " << *var << "  \n";
}

inline void itemINP::disp_selected() {
  cout << std::setw(y + 9) << "\033[31;1;4m--> " << name << "\033[0m     \n";
}

inline void itemINP::disp_selectedinput() {
  cout << std::setw(0.6 * y + 9) << "\033[31;1;4m--> " << name << ": " << *var
       << "\033[0m     \n";
}

class menuINP {
  itemINP head;
  std::vector<itemINP> entries;
  int num;
  int selected;

public:
  menuINP() : num(0), selected(0) {}
  void add(string, string &);
  void menu_head(string);
  int display();
};

inline void menuINP::add(string s, string &v) {
  num++;
  entries.push_back(itemINP(s, v));
}

inline void menuINP::menu_head(string s) {
  head.name = s;
  return;
}

inline int menuINP::display() {
  hideCursor();
  std::cout << std::resetiosflags(std::ios::left | std::ios::right);

  if (entries.end()->name != "CANCEL") {
    entries.push_back(itemINP("SUPMIT"));
    entries.push_back(itemINP("CANCEL"));
    num += 2;
  }
  // system("clear");
  cout << "\033[2J\033[1;1H";
  int opt = 66, last_x = getmax_x(), last_y = getmax_y();
  while (true) {
    int max_y = getmax_y(), i;
    head.y = (max_y - head.name.size()) / 2;
    for (itemINP &a : entries) {
      a.y = (max_y - a.name.size()) / 2;
    }

    // system("clear");
    cout << "\033[2J\033[1;1H";
    int max_x = getmax_x();
    if (!(max_x == last_x && max_y == last_y)) {
      last_x = max_x;
      last_y = max_y;
    }
    int x = (max_x - num) / 2 - 2;
    gotoxy(0, 0);
    for (i = 2; i < x; i++)
      cout << endl;
    head.display();
    cout << std::setw(head.y + 2 * head.name.size())
         << string(3 * head.name.size(), '*');
    cout << "\n\n";
    for (i = 0; i < (int)entries.size() - 2; i++) {
      if (i == selected)
        entries[i].disp_selectedinput();
      else
        entries[i].displayinput();
    }
    for (i = entries.size() - 2; i < (int)entries.size(); i++) {
      if (i == selected)
        entries[i].disp_selected();
      else
        entries[i].display();
    }
    opt = readKey();
    if (opt == 10 && selected == entries.size() - 1) // cancel
    {
      for (i = 0; i < (int)entries.size() - 2; i++) {
        entries[i].var = &entries[i].origstr;
      }
      return 0;
    }
    if (opt == 10 && selected == entries.size() - 2) // submit
      return 1;
    switch (opt) {
    case 127:
    case '\b':
    case DEL_KEY:
      if (selected < entries.size() - 2) {
        if (!entries[selected].var->empty()) {
          entries[selected].var->pop_back();
        }
      }
      break;
    case ARROW_DOWN:
      selected++;
      break;
    case ARROW_UP:
      selected--;
      break;
    }
    if (selected < entries.size() - 2) {
      if (opt > 31 && 127 > opt) {
        entries[selected].var->push_back(opt);
      }
    }
    cout << '\n';
    if (selected == num)
      selected = 0;
    if (selected == -1)
      selected = num - 1;
  }
  showCursor();
}
