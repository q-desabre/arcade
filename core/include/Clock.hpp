
#ifndef _CLOCK_HPP_
# define _CLOCK_HPP_

#include <time.h>

class Clock
{
public:
  Clock();
  ~Clock();

  void		restart();
  float		getElapsedTime() const;

private:
  clock_t	_clock;
};

#endif /* _CLOCK_HPP_ */
