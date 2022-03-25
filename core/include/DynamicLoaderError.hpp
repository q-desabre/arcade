
#ifndef _DYNAMIC_LOADER_ERROR_
#define _DYNAMIC_LOADER_ERROR_

#include <exception>
#include <stdexcept>

class DynamicLoaderError : public std::runtime_error
{
   public:
    DynamicLoaderError(const std::string& error) : std::runtime_error(error) {}
};

#endif /* _DYNAMIC_LOADER_ERROR_ */
