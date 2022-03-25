
#ifndef _LIBRARY_DATA_
# define _LIBRARY_DATA_

# include <iostream>

enum LibType
  {
   LIB_GRAPHIC,
   LIB_GAME
  };

struct	LibraryData
{
  std::string		name;
  LibType		type;
  bool			selected;
};

#endif
