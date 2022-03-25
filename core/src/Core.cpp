
#include "Core.hpp"

Core::Core()
{
    username = "Guest";
    graphic = NULL;
    game = NULL;
    score = 0;
}

Core::~Core()
{
    if (graphic) delete graphic;
    if (game) delete game;
}

void Core::init(const std::string& path)
{
    this->setGraphic(path);
    this->setGame("./lib/lib_menu.so");
}

void Core::graphicSwap()
{
    if (this->event == Arcade::NextGraphic)
    {
        //        this->menu.nextGraphic();
        //        setGraphic("./lib/" +
        //        menu.getLibs()[menu.getSelectedGraphic()].name);
    }
    else if (this->event == Arcade::PrevGraphic)
    {
        //        this->menu.prevGraphic();
        //        setGraphic("./lib/" +
        //        menu.getLibs()[menu.getSelectedGraphic()].name);
    }
}

void Core::start()
{
    while (1)
    {
        this->graphic->getEvents(this->event);
        this->graphicSwap();
        if (this->event == Arcade::Closed)
        {
            return;
        }
        game->update(event);
        this->score = game->getScore();
        graphic->display(game->getMap(), game->getTexts());
    }
}

void Core::startGame()
{
    // std::cout << "./lib/" + menu.getLibs()[menu.getSelectedGame()].name
    //           << std::endl;
    // setGame("./lib/" + menu.getLibs()[menu.getSelectedGame()].name);
    // setGraphic("./lib/" + menu.getLibs()[menu.getSelectedGraphic()].name);
    // state = GAME;
}

void Core::handleMenu()
{
    /*   switch (this->event)
       {
           case Arcade::Right:
               if (this->menu.getToggle() == Arcade::GRAPHICS)
                   this->menu.nextGraphic();
               else
                   this->menu.nextGame();
               break;
           case Arcade::Left:
               if (this->menu.getToggle() == Arcade::GRAPHICS)
                   this->menu.prevGraphic();
               else
                   this->menu.prevGame();
               break;
           case Arcade::Up:
               this->menu.toggleUp();
               break;
           case Arcade::Down:
               this->menu.toggleDown();
               break;
           case Arcade::Action1:
               startGame();
               break;
       } */
}

void Core::setGraphic(const std::string& path)
{
    if (graphic) delete graphic;
    dl_graphic.close();
    try
    {
        dl_graphic.open(path.c_str());
        graphic = dl_graphic.getFunc<graphic_ptr>("create_graphic")();
    }
    catch (std::exception& e)
    {
        // j'essaye la lib d'après, je reviens sur celle d'avant
    }
    graphic->init();
    if (game) graphic->initGame(game->getName(), game->getMapSize());
}

void Core::setGame(const std::string& path)
{
    if (game) delete game;
    dl_game.close();
    dl_game.open(path.c_str());
    game = dl_game.getFunc<game_ptr>("create_game")();
    game->init();
    if (graphic) graphic->initGame(game->getName(), game->getMapSize());
}
