#include <iostream>
#include <ncurses.h>
#include <string>

#define BORDER_WIDTH 60
#define BORDER_HEIGHT 30

// Draw the border
void draw_border()
{
    // Left border
    for (int i = 0; i < BORDER_HEIGHT; i++)
    {
        mvaddch(i, 0, '|');
    }
    // Top border
    for (int i = 0; i < BORDER_WIDTH; i++)
    {
        mvaddch(0, i, '-');
    }   
    // Right border
    for (int i = 0; i < BORDER_HEIGHT; i++)
    {
        mvaddch(i, BORDER_WIDTH, '|');
    }
    // Bottom border
    for (int i = 0; i < BORDER_WIDTH; i++)
    {
        mvaddch(BORDER_HEIGHT, i, '-');
    }
}

int main ()
{
    int ch = '0';
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    // nodelay(stdscr, TRUE);
    mvaddch(BORDER_WIDTH, BORDER_HEIGHT, ch);
    draw_border();
    refresh();
    getch();
    endwin();
    return 0;
}