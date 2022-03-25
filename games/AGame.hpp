
#pragma once

#include "IGame.hpp"

namespace Arcade
{
class AGame : public IGame
{
   public:
    AGame(int width, int height);

    const std::vector<TextData>& getTexts() const;
    const std::vector<char>& getMap() const;
    const Vec2& getMapSize() const;

   protected:
    std::vector<TextData> texts;
    std::vector<char> map;
    Vec2 size;
};
}  // namespace Arcade