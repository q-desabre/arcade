
#ifndef _DIRECTORY_READER_
#define _DIRECTORY_READER_

#include <dirent.h>
#include <vector>

#include <stdexcept>

class DirectoryException : public std::logic_error
{
public:
  DirectoryException(const std::string &what_arg) : std::logic_error(what_arg) {}
};

class DirectoryReader
{
public:
  DirectoryReader(const std::string &path);
  ~DirectoryReader();

  void readFiles();
  const std::vector<std::string> &getFiles() const;

private:
  std::vector<std::string> files;
  DIR *dir;
};

#endif /* _DIRECTORY_READER */
