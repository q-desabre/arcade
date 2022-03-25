

#include "SnakeGame.hpp"
#include <algorithm>

SnakeGame::SnakeGame() : AGame(20, 20), snake(Vec2(9, 5))
{
    srand(time(NULL));
    spawnApple();
    score = 0;
}

SnakeGame::~SnakeGame() {}

void SnakeGame::update(Arcade::Event event)
{
    snake.move(event);
    if (timer.getElapsedTime() >= 0.1525)
    {
        std::replace(map.begin(), map.end(), '1', '0');
        snake.update(map, size);
        for (int i = 0; i != snake.getBody().size(); i++)
        {
            if (i == 0)
                map[snake.getBody()[i].x + snake.getBody()[i].y * size.x] = '3';
            else
                map[snake.getBody()[i].x + snake.getBody()[i].y * size.x] = '1';
        }
        if (std::find(map.begin(), map.end(), '2') == map.end())
        {
            spawnApple();
            score++;
        }
        // DEATH GESTION TO DO
        timer.restart();
    }
}

void SnakeGame::spawnApple()
{
    bool b = true;
    int r1 = 0;
    int r2 = 0;

    while (map[r1 + r2 * size.x] == '1' || b)
    {
        r1 = rand() % size.x;
        r2 = rand() % size.y;
        b = false;
    }
    map[r1 + r2 * size.x] = '2';
}

std::size_t SnakeGame::getScore() const
{
    return score;
}

const std::string SnakeGame::getName() const
{
    return "Snake";
}
