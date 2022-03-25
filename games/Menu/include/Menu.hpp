
#pragma once

#include "AGame.hpp"
#include "ArcadeSwitch.hpp"
#include "DirectoryReader.hpp"
#include "LibraryData.hpp"

class Menu : public Arcade::AGame
{
   public:
    Menu();
    ~Menu();
    void init();
    void initLibs();
    void update(Arcade::Event event);

    std::size_t getScore() const;
    const std::string getName() const;

    void toggleDown();
    void toggleUp();
    void nextGraphic();
    void nextGame();
    void prevGraphic();
    void prevGame();
    int getSelectedGame() const;
    int getSelectedGraphic() const;
    Arcade::Switch getToggle() const;

      private:
    DirectoryReader dr;
    std::vector<LibraryData> libs;
    Arcade::Switch toggle;
    int selectedGame;
    int selectedGraphic;
};

extern "C"
{
    Arcade::IGame* create_game() { return new Menu(); }
}