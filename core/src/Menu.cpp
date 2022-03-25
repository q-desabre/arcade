
#include "Menu.hpp"

Menu::Menu() : dr("./lib/")
{
  toggle = Arcade::GAMES;
}

Menu::~Menu()
{

}

void						Menu::init(const std::string& path)
{
  std::vector<std::string>	f = dr.getFiles();
  std::size_t			pos = path.find("lib_");
  std::string			tmp = path.substr(pos);
  
  
  for (int i = 0; i != f.size(); i++) {
    if (!f[i].compare(0, 7, "lib_game", 7)) {
      libs.push_back((LibraryData){f[i], LIB_GAME, false});
    }
    else if (!f[i].compare(0, 10, "lib_graphic", 10)) {
      libs.push_back((LibraryData){f[i], LIB_GRAPHIC, false});
      if (tmp == f[i]) {
	libs[libs.size() - 1].selected = true;
      }
    }
  }
  for (int i = 0; i != libs.size(); i++) {
    if (libs[i].type == LIB_GAME) {
      libs[i].selected = true;
      break;
    }
  }
}

const std::vector<LibraryData>&			Menu::getLibs() const
{
  return libs;
}


int						Menu::getSelectedGame() const
{
  for (int i = 0; i != libs.size(); i++) {
    if (libs[i].selected == true && libs[i].type == LIB_GAME)
      return (i);
  }
  return -1;
}

int						Menu::getSelectedGraphic() const
{
  for (int i = 0; i != libs.size(); i++) {
    if (libs[i].selected == true && libs[i].type == LIB_GRAPHIC)
      return (i);
  }
  return -1;
}

Arcade::Switch					Menu::getToggle() const
{
  return toggle;
}

void						Menu::nextGame()
{
  int						j = -1;

  for (int i = 0; i != libs.size(); i++) {
    if (libs[i].type == LIB_GAME && libs[i].selected == true) {
      libs[i].selected = false;
      j = i;
    }
  }
  for (int i = 0; i != libs.size() && j != -1; i++) {
    if (libs[i].type == LIB_GAME && i > j) {
      libs[i].selected = true;
      j = -2;
      break;
    }
  }
  if (j != -2)
    libs[j].selected = true;
}

void						Menu::nextGraphic()
{
  int						j = -1;

  for (int i = 0; i != libs.size(); i++) {
    if (libs[i].type == LIB_GRAPHIC && libs[i].selected == true) {
      libs[i].selected = false;
      j = i;
    }
  }
  for (int i = 0; i != libs.size() && j != -1; i++) {
    if (libs[i].type == LIB_GRAPHIC && i > j) {
      libs[i].selected = true;
      j = -2;
      break;
    }
  }
  if (j != -2)
    libs[j].selected = true;
}

void						Menu::prevGame()
{
  int						j = -1;

  for (int i = 0; i != libs.size(); i++) {
    if (libs[i].type == LIB_GAME && libs[i].selected == true) {
      libs[i].selected = false;
      j = i;
    }
  }
  for (int i = j; i >= 0 && j != -1; i--) {
    if (libs[i].type == LIB_GAME && i < j) {
      libs[i].selected = true;
      j = -2;
      break;
    }
  }
  if (j != -2)
    libs[j].selected = true; 
}

void						Menu::prevGraphic()
{
  int						j = -1;

  for (int i = 0; i != libs.size(); i++) {
    if (libs[i].type == LIB_GRAPHIC && libs[i].selected == true) {
      libs[i].selected = false;
      j = i;
    }
  }
  for (int i = j; i >= 0 && j != -1; i--) {
    if (libs[i].type == LIB_GRAPHIC && i < j) {
      libs[i].selected = true;
      j = -2;
      break;
    }
  }
  if (j != -2)
    libs[j].selected = true; 
}


void						Menu::toggleDown()
{
  if (toggle == Arcade::GAMES)
    toggle = Arcade::GRAPHICS;
  else if (toggle == Arcade::GRAPHICS)
    toggle = Arcade::GAMES;
}

void						Menu::toggleUp()
{
  if (toggle == Arcade::GAMES)
    toggle = Arcade::GRAPHICS;
  else if (toggle == Arcade::GRAPHICS)
    toggle = Arcade::GAMES;
}
