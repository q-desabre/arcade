
#ifndef _GRAPHIC_HPP_
#define _GRAPHIC_HPP_

#include <iostream>
#include <vector>
#include "ArcadeSwitch.hpp"
#include "Event.hpp"
#include "LibraryData.hpp"
#include "TextData.hpp"
#include "Vec2.hpp"

namespace Arcade
{
class IGraphic
{
   public:
    virtual ~IGraphic() = default;
    virtual void init() = 0;
    virtual void initGame(const std::string& gameName, const Vec2& mapSize) = 0;

    virtual void getEvents(Event& arcadeEvent) = 0;

    // replace with Draw text ?
    virtual const std::string& getUsername() const = 0;

    virtual void displayMap(const std::vector<char>& map) = 0;
    virtual void displayTexts(const std::vector<TextData>& texts) = 0;

        virtual void display(const std::vector<char>& map,
                         const std::vector<TextData>& texts) = 0;
};
};  // namespace Arcade

#endif /* _GRAPHIC_HPP_ */
