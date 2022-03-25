
#include "Core.hpp"

int			main(int ac, char **av, char **env)
{
  Core			core;

  if (ac != 2) {
    std::cout << "Usage : ./arcade libraryPath" << std::endl;
    return (0);
  }
  try {
    core.init(av[1]);
    core.start();

  } catch (const std::exception& err) {
    std::cerr << err.what() << std::endl;
  }    
  return (0);
}
