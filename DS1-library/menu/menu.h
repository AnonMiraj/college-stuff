
#pragma once
#include "editorkey.h"
#include "func.h"
#include <cstddef>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip> 
using std::cout;
using std::endl;
using std::string;

class item {
public:
  string name, desc;
  int ret;
  int y;
  item() {
    name = "";
    desc = "";
    y = 0;
    ret = 0;
  }
  item(string s1, int a, string s2="") {
    name = s1;
    desc = s2;
    ret = a;
  }
  void display();
  void disp_selected();
};

inline void item::display() {
  cout << std::setw(y + name.size()) << name << "  \n";
}

inline void item::disp_selected() {
  cout << std::setw(y + 9) << "\033[31;1;4m--> " << name << "\033[0m     \n";
}

class menu {
  item head;
  std::vector<item> entries;
  int num;
  int selected;

public:
  menu() : num(0), selected(0) {}
  void add(string, int, string);
  void menu_head(string);
  int display();
};

inline void menu::add(string s, int r = 0, string d = " ") {
  num++;
  if (r == 0)
    r = num;
  entries.push_back(item(s, r, d));
}

inline void menu::menu_head(string s) {
  head.name = s;
  return;
}

inline int menu::display() {
  hideCursor();
    std::cout << std::resetiosflags(std::ios::left | std::ios::right);
  // system("clear");
  cout << "\033[2J\033[1;1H";
  int opt = 66, last_x = getmax_x(), last_y = getmax_y();
  while (true) {
    int max_y = getmax_y(), i;
    head.y = (max_y - head.name.size()) / 2;
    for (item &a : entries) {
      a.y = (max_y - a.name.size()) / 2;
    }
    int max_x = getmax_x();
    // system("clear");
    cout << "\033[2J\033[1;1H";
    if (!(max_x == last_x && max_y == last_y)) {
      last_x = max_x;
      last_y = max_y;
    }
    int x = (max_x - num) / 2 - 2;
    gotoxy(0, 0);
    for (i = 2; i < x; i++)
      cout << endl;
    cout << std::setw(head.y) ; head.display();
    cout << std::setw(head.y + 2 * head.name.size()) << string(3 * head.name.size(), '*');
    // cout << "**********";
    cout << "\n\n";
    for (i = 0; i < (int)entries.size(); i++) {
      if (i == selected)
        entries[i].disp_selected();
      else
        entries[i].display();
    }
    cout << "\n\n\n\n\n\n\n";

    if (entries[selected].desc!=" ") {

      cout << "Desription: " << entries[selected].desc;
    }
    cout << '\n';
    opt = getch();
    if (opt == 10)
      return entries[selected].ret;
    switch (opt) {
    case 66:
      selected++;
      break;
    case 65:
      selected--;
      break;
    }
    if (selected == num)
      selected = 0;
    if (selected == -1)
      selected = num - 1;
  }
  showCursor();
}

