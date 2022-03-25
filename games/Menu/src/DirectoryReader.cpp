
#include "DirectoryReader.hpp"
#include <iostream>

DirectoryReader::DirectoryReader(const std::string& path)
{
    dir = opendir(path.c_str());
    if (dir == NULL)
    {
        throw DirectoryException("Opendir Failed");
    }
    this->readFiles();
}

DirectoryReader::~DirectoryReader()
{
    closedir(dir);
}

void DirectoryReader::readFiles()
{
    struct dirent* ent;

    while ((ent = readdir(dir)) != NULL)
    {
        if (ent->d_type == DT_REG)
        {
            files.push_back(ent->d_name);
            std::cout << ent->d_name << std::endl;
        }
    }
}

const std::vector<std::string>& DirectoryReader::getFiles() const
{
    return files;
}
