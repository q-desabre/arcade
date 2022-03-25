
#ifndef _NCURSES_GRAPHIC_
# define _NCURSES_GRAPHIC_

# include "IGraphic.hpp"
# include "Clock.hpp"
# include <ncurses.h>

class NcursesGraphic : public Arcade::IGraphic
{
public:
  NcursesGraphic();
  ~NcursesGraphic();

  void			init();
  void			initGame(const std::string& gameName, const Vec2& mapSize);
  void			getEvents(Arcade::Event& arcadeEvent);
  void			display(const std::vector<char>& map, std::size_t score);
  const std::string&	getUsername() const;
  void			displayMenu(const std::vector<LibraryData>& libs, std::size_t score, Arcade::Switch toggle);

private:
  Clock			timer;
  Vec2			mapSize;
  WINDOW		*win;
  std::string		username;
};

extern "C"
{
  Arcade::IGraphic		*create_graphic()
  {
    return new NcursesGraphic;
  }
}

#endif /* _NCURSES_GRAPHIC_ */
