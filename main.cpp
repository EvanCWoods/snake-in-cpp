#include <iostream>
#include <ncurses.h>
#include <string>

#include "./snake.hpp"
#include "./food.hpp"

#define BORDER_WIDTH 60
#define BORDER_HEIGHT 30
#define ch '0'

// Create a snake object from our class
Snake snake;
Food food;

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

void init_game()
{
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    draw_border();
    snake.draw();
    snake.move();
    refresh();
    getch();
}

int main ()
{
    init_game();
    while (true)
    {
        int key = getch();
        if (key == 'q')
        {
            endwin();
            break;
        }
        if (key == KEY_UP && snake.get_direction() != DOWN)
        {
            snake.set_direction(UP);
        }
        else if (key == KEY_DOWN && snake.get_direction() != UP)
        {
            snake.set_direction(DOWN);
        }
        else if (key == KEY_LEFT && snake.get_direction() != RIGHT)
        {
            snake.set_direction(LEFT);
        }
        else if (key == KEY_RIGHT && snake.get_direction() != LEFT)
        {
            snake.set_direction(RIGHT);
        }
        napms(100);
        clear();
        draw_border();
        snake.move();
        snake.draw();
        if (snake.get_head() == food.get_position())
        {
            snake.grow();
            food.respawn(BORDER_HEIGHT, BORDER_WIDTH);
        }
        food.draw();
        refresh();
    }
    return 0;
}