

#ifndef _DYNAMIC_LOADER_
#define _DYNAMIC_LOADER_

#include <dlfcn.h>
#include <iostream>
#include "DynamicLoaderError.hpp"

class DynamicLoader
{
   public:
    DynamicLoader();
    ~DynamicLoader();

    void open(const std::string& path);
    template <typename T>
    T getFunc(const std::string& func_name)
    {
        return ((T)dlsym(handler, func_name.c_str()));
    }
    void close();

   private:
    void* handler;
};

#endif /* _DYNAMIC_LOADER_ */
