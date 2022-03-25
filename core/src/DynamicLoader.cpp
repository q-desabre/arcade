
#include "DynamicLoader.hpp"

DynamicLoader::DynamicLoader()
{
    handler = NULL;
}

DynamicLoader::~DynamicLoader() {}

void DynamicLoader::open(const std::string& path)
{
    handler = dlopen(path.c_str(), RTLD_LAZY);
    if (!handler)
    {
        throw DynamicLoaderError(dlerror());
    }
}

void DynamicLoader::close()
{
    if (handler) dlclose(handler);
    handler = NULL;
}
