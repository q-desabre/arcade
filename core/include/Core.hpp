
#ifndef _CORE_HPP_
#define _CORE_HPP_

#include "Clock.hpp"
#include "DynamicLoader.hpp"
#include "IGame.hpp"
#include "IGraphic.hpp"

typedef Arcade::IGraphic* (*graphic_ptr)();
typedef Arcade::IGame* (*game_ptr)();

enum CoreState
{
    MENU,
    GAME
};

class Core
{
   public:
    Core();
    ~Core();

    void start();
    void startGame();
    void init(const std::string& path);

    void graphicSwap();
    void handleMenu();
    void setGraphic(const std::string& path);
    void setGame(const std::string& path);

   private:
    DynamicLoader dl_graphic;
    DynamicLoader dl_game;
    Arcade::IGraphic* graphic;
    Arcade::IGame* game;
    Arcade::Event event;

    Clock timer;
    /* Player Data */
    std::string username;
    std::size_t score;
};

#endif /* _CORE_HPP_ */
