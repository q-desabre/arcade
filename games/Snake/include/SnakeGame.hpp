
#ifndef _SNAKE_GAME_HPP_
#define _SNAKE__GAME_HPP_

#include "AGame.hpp"
#include "Clock.hpp"
#include "Snake.hpp"

class SnakeGame : public Arcade::AGame
{
   public:
    SnakeGame();
    ~SnakeGame();

    void init();
    void update(Arcade::Event event);

    bool isRunning() const;
    std::size_t getScore() const;
    const std::string getName() const;

   private:
    void spawnApple();

   private:
    std::size_t score;
    Snake snake;
    Clock timer;
};

extern "C"
{
    Arcade::IGame* create_game() { return new SnakeGame; }
}

#endif /* _SNAKE_GAME_HPP_ */
