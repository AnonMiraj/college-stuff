#pragma once
#include <termios.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>

static struct termios old, newa;

inline void gotoxy(int x, int y)
{
    printf("\033[%d;%dH", x, y);
}

inline void initTermios(int echo)
{
    tcgetattr(0, &old);
    newa = old;
    newa.c_lflag &= ~ICANON;
    newa.c_lflag &= echo ? ECHO : ~ECHO;
    tcsetattr(0, TCSANOW, &newa);
}

inline void resetTermios(void)
{
    tcsetattr(0, TCSANOW, &old);
}

inline bool kbhit()
{
    termios term;
    tcgetattr(0, &term);

    termios term2 = term;
    term2.c_lflag &= ~ICANON;
    tcsetattr(0, TCSANOW, &term2);

    int byteswaiting;
    ioctl(0, FIONREAD, &byteswaiting);

    tcsetattr(0, TCSANOW, &term);

    return byteswaiting > 0;
}

inline char getch_(int echo)
{
    char ch;
    initTermios(echo);
    ch = getchar();
    resetTermios();
    return ch;
}

inline char getch(void)
{
    return getch_(0);
}

inline char getche(void)
{
    return getch_(1);
}

inline int getmax_x()
{
    int lines = 24;
    #ifdef TIOCGSIZE
        struct ttysize ts;
        ioctl(STDIN_FILENO, TIOCGSIZE, &ts);

        lines = ts.ts_lines;
    #elif defined(TIOCGWINSZ)
        struct winsize ts;
        ioctl ( STDIN_FILENO, TIOCGWINSZ, &ts);

        lines = ts.ws_row;
    #endif /* TIOCGSIZE */
        return lines;
}

inline int getmax_y()
{
    int cols = 80;

    #ifdef TIOCGSIZE
        struct ttysize ts;
        ioctl(STDIN_FILENO, TIOCGSIZE, &ts);
        cols = ts.ts_cols;

    #elif defined(TIOCGWINSZ)
        struct winsize ts;
        ioctl ( STDIN_FILENO, TIOCGWINSZ, &ts);
        cols = ts.ws_col;

    #endif /* TIOCGSIZE */
    return cols;
}

inline void hideCursor()
{
printf("\e[?25l");
}

inline void showCursor()
{
printf("\e[?25h");
}
