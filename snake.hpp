#include <vector>
#include <utility>
#include <ncurses.h>

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

class Snake
{
    private:
        std::vector<std::pair<int, int>> body;
        int direction;
    public:
        Snake()
        {
            body.push_back(std::make_pair(15, 30));
            direction = RIGHT; // start moving right (int = 1)
        }
        void move()
        {
            std::pair<int, int> head = body.front();
            switch (direction)
            {
                case UP:
                    head.first--;
                    break;
                case DOWN:
                    head.first++;
                    break;
                case LEFT:
                    head.second--;
                    break;
                case RIGHT:
                    head.second++;
                    break;
            }
            body.insert(body.begin(), head); // insert the new head at the beginning of the body
            body.pop_back(); // remove the tail
        }
        void grow()
        {
            body.push_back(body.back());
        }
        void draw()
        {
            for (auto &part : body)
            {
                mvaddch(part.first, part.second, '0');
            }
        }
        void set_direction(int direction)
        {
            this->direction = direction;
        }
        int get_direction() { return direction; }
        std::pair<int, int> get_head() { return body.front(); }
};