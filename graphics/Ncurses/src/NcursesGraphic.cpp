
#include "NcursesGraphic.hpp"

NcursesGraphic::NcursesGraphic()
{
}

NcursesGraphic::~NcursesGraphic()
{
  clear();
  endwin();
}

void NcursesGraphic::init()
{
  initscr();
  curs_set(0);
  noecho();
  cbreak();
  refresh();
  start_color();
  init_pair(1, COLOR_GREEN, COLOR_GREEN);   /* create foreground / background combination */
  init_pair(2, COLOR_RED, COLOR_RED);       /* create foreground / background combination */
  init_pair(3, COLOR_YELLOW, COLOR_YELLOW); /* create foreground / background combination */
}

void NcursesGraphic::initGame(const std::string &gameName, const Vec2 &mapSize)
{
  win = newwin(mapSize.y + 3, (2 * (mapSize.x + 2)), 1, 2);
  nodelay(win, TRUE);
  keypad(win, TRUE);
  this->mapSize = mapSize;
  wrefresh(win);
}

void NcursesGraphic::getEvents(Arcade::Event &arcadeEvent)
{
  int c;

  arcadeEvent = Arcade::None;
  c = wgetch(win);
  switch (c)
  {
  case KEY_LEFT:
    arcadeEvent = Arcade::Left;
    break;
  case KEY_RIGHT:
    arcadeEvent = Arcade::Right;
    break;
  case 'a':
    arcadeEvent = Arcade::NextGraphic;
    break;
  default:
    break;
  }
}

void NcursesGraphic::display(const std::vector<char> &map, std::size_t score)
{
  int offset_x = 1;
  int offset_y = 1;

  // clear();
  box(win, 0, 0);
  for (int i = 0; i != map.size(); i++)
  {
    mvwprintw(win,
              offset_y + i * 2 / (mapSize.x * 2),
              offset_x + i * 2 % (mapSize.x * 2) + 1, "  ");
  }
  for (int i = 0; i != map.size(); i++)
  {
    if (map[i] != '0')
    {
      wattron(win, COLOR_PAIR(map[i] - '0'));
      mvwprintw(win,
                offset_y + i * 2 / (mapSize.x * 2),
                offset_x + i * 2 % (mapSize.x * 2) + 1,
                "%c%c", map[i], map[i]);
      wattroff(win, COLOR_PAIR(map[i] - '0'));
    }
  }
  wrefresh(win);
  refresh();
}

void NcursesGraphic::displayMenu(const std::vector<LibraryData> &libs, std::size_t score, Arcade::Switch toggle)
{
}

const std::string &NcursesGraphic::getUsername() const
{
  return this->username;
}
