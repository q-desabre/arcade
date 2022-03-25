
#ifndef _SNAKE_HPP_
# define _SNAKE_HPP_

# include <vector>
# include "Vec2.hpp"
# include "Event.hpp"

enum Direction
  {
   TOP,
   BOTTOM,
   LEFT,
   RIGHT,
  };

class				Snake
{
public:
  Snake(const Vec2& initialPos);
  ~Snake();

  void				update(const std::vector<char>& map, Vec2 mapSize);
  void				eat();
  void				move(Arcade::Event event);

  const std::vector<Vec2>&	getBody() const;
  
private:
  std::vector<Vec2>	body;
  Direction		direction;
  bool			grow;
};


#endif /* _SNAKE_HPP_ */
