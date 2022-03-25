
#ifndef _SFML_GRAPHIC_HPP_
#define _SFML_GRAPHIC_HPP_

#include <SFML/Graphics.hpp>
#include "Clock.hpp"
#include "IGraphic.hpp"

class SfmlGraphic : public Arcade::IGraphic
{
   public:
    SfmlGraphic();
    virtual ~SfmlGraphic();

    // A remove
    const std::string& getUsername() const;
    //  From IGraphic
    void init();
    void initGame(const std::string& gameName, const Vec2& mapSize);

    void getEvents(Arcade::Event& arcadeEvent);

    void displayMap(const std::vector<char>& map);
    void displayTexts(const std::vector<Arcade::TextData>& texts);
    void display(const std::vector<char>& map,
                 const std::vector<Arcade::TextData>& texts);

   private:
    void drawScore(std::size_t score);
    void drawMenuLabel(Arcade::Switch toggle);
    void drawMenuBackground(Arcade::Switch toggle);

   private:
    void initTexts();
    void initText(sf::Text& text,
                  sf::Color color,
                  const sf::Vector2f& pos,
                  int fontSize);

   private:
    // Basic Elements
    sf::RenderWindow* window;
    sf::Event event;
    Clock timer;

    // Data
    Vec2 mapSize;
    Vec2 windowSize;
    std::string username;

    // Tools
    sf::RectangleShape rect;
    sf::RectangleShape topBar;

    // Text
    sf::Font font;
    sf::Text textTmp;
    sf::Text playerText;

    // Games Sprites
    sf::Texture backgroundTexture;
    sf::Texture backgroundGameTexture;
    sf::Sprite background;
    sf::Sprite backgroundGame;
    sf::Texture inputBoxTexture;
    sf::Sprite inputBoxSprite;
};

extern "C"
{
    Arcade::IGraphic* create_graphic() { return new SfmlGraphic; }
}

#endif /* _SFML_GRAPHIC_HPP */
