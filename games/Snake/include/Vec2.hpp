
#ifndef _VEC2_HPP_
# define _VEC2_HPP_

# include <iostream>

struct		Vec2
{
  Vec2(std::size_t x = 0, std::size_t y = 0) { this->x = x; this->y = y; } 
  std::size_t	x;
  std::size_t	y;
};

#endif /* _VEC2_HPP_ */
