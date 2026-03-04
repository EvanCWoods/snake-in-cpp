#include <utility>
#include <ncurses.h>

#define FOOD_CHAR '*'

class Food
{
    private:
        std::pair<int, int> position;

    public:
        Food()
        {
            position = std::make_pair(5, 5);
        }
        void draw()
        {
            mvaddch(position.first, position.second, FOOD_CHAR);
        }
        void respawn(int BORDER_HEIGHT, int BORDER_WIDTH)
        {
            position = std::make_pair(rand() % BORDER_HEIGHT, rand() % BORDER_WIDTH);
        }
        std::pair<int, int> get_position() { return position; }
};
