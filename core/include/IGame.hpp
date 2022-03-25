
#ifndef _IGAME_HPP_
#define __IGAME_HPP_

#include <iostream>
#include <vector>
#include "Event.hpp"
#include "TextData.hpp"
#include "Vec2.hpp"

namespace Arcade
{

class IGame
{
   public:
    virtual ~IGame() = default;

    virtual void init() = 0;
    virtual void update(Event event) = 0;

    virtual const std::string getName() const = 0;
    virtual std::size_t getScore() const = 0;

    // AGame
    virtual const std::vector<TextData>& getTexts() const = 0;
    virtual const std::vector<char>& getMap() const = 0;
    virtual const Vec2& getMapSize() const = 0;
};

}  // namespace Arcade

#endif /* _IGAME_HPP_ */
