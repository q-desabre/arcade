
#include "AGame.hpp"

namespace Arcade
{
AGame::AGame(int width, int height) : map(width * height, '0')
{
    this->size.x = width;
    this->size.y = height;
}

const Vec2& AGame::getMapSize() const
{
    return (this->size);
}

const std::vector<char>& AGame::getMap() const
{
    return (this->map);
}

const std::vector<Arcade::TextData>& AGame::getTexts() const
{
    return (this->texts);
}
}  // namespace Arcade