#include "func.h"
#ifndef EDITORKEY_HPP
#define EDITORKEY_HPP

    enum Key {
        ARROW_LEFT = 1000,
        ARROW_RIGHT,
        ARROW_UP,
        ARROW_DOWN,
        DEL_KEY,
    };


inline int readKey() {
  char c;
  c = getch();

  if (c == '\x1b') {
    char seq[3];

    seq[0] = getch();
    seq[1] = getch();

    if (seq[0] == '[') {
      if (seq[1] >= '0' && seq[1] <= '9') {

        seq[2] = getch();
        if (seq[2] == '~') {
          switch (seq[1]) {
          case '3':
            return DEL_KEY;
          }
        }
      } else {
        switch (seq[1]) {
        case 'A':
          return ARROW_UP;
        case 'B':
          return ARROW_DOWN;
        case 'C':
          return ARROW_RIGHT;
        case 'D':
          return ARROW_LEFT;
        }
      }
    }

    return '\x1b';
  } else {
    return c;
  }
}

#endif // EDITORKEY_HPP
