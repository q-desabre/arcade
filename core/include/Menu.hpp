

#ifndef _MENU_MODEL_
# define _MENU_MODEL_

# include <iostream>
# include "ArcadeSwitch.hpp"
# include "DirectoryReader.hpp"
# include "LibraryData.hpp"


class	Menu
{
public:
  Menu();
  ~Menu();

  void					init(const std::string & path);
  const std::vector<std::string>&	getGraphics() const;
  const std::vector<std::string>&	getGames() const;
  const std::vector<LibraryData>&	getLibs() const;

  void					toggleDown();
  void					toggleUp();
  void					nextGraphic();
  void					nextGame();
  void					prevGraphic();
  void					prevGame();
  int					getSelectedGame() const;
  int					getSelectedGraphic() const;
  Arcade::Switch			getToggle() const;
private:
  DirectoryReader		dr;
  Arcade::Switch		toggle;
  int				selectedGame;
  int				selectedGraphic;
  std::vector<LibraryData>	libs;
  std::vector<std::string>	graphicsPaths;
};


#endif /* _MENU_MODEL_ */
