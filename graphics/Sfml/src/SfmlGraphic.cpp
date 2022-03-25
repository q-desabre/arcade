
#include "SfmlGraphic.hpp"

SfmlGraphic::SfmlGraphic()
{
    windowSize.x = 1600;
    windowSize.y = 900;
    topBar.setFillColor(sf::Color(155, 155, 155));
    topBar.setPosition(sf::Vector2f(0, 0));
    topBar.setSize(sf::Vector2f(windowSize.x, 30));

    initTexts();
}

SfmlGraphic::~SfmlGraphic()
{
    window->close();
}

void SfmlGraphic::init()
{
    window = new sf::RenderWindow(
        sf::VideoMode(windowSize.x, windowSize.y + 30), "Arcade");
    window->setFramerateLimit(60);
}

void SfmlGraphic::initTexts()
{
    if (!font.loadFromFile("./graphics/Sfml/assets/font.ttf"))
        std::cout << "failed ttf" << std::endl;
    initText(textTmp, sf::Color(255, 255, 255), sf::Vector2f(50, 3), 24);
}

void SfmlGraphic::initGame(const std::string& gameName, const Vec2& mapSize)
{
    this->mapSize = mapSize;
    rect.setSize(sf::Vector2f(900 / mapSize.x, 900 / mapSize.y));
}

void SfmlGraphic::getEvents(Arcade::Event& arcadeEvent)
{
    arcadeEvent = Arcade::None;
    while (window->pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::Closed:
                arcadeEvent = Arcade::Closed;
                break;

            case sf::Event::TextEntered:
                if (event.text.unicode == 8)
                {
                    username = username.substr(0, username.length() - 1);
                }
                else
                    username += event.text.unicode;
                playerText.setString(username);

            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::A)
                    arcadeEvent = Arcade::PrevGraphic;
                if (event.key.code == sf::Keyboard::Left)
                    arcadeEvent = Arcade::Left;
                if (event.key.code == sf::Keyboard::Right)
                    arcadeEvent = Arcade::Right;
                if (event.key.code == sf::Keyboard::Up)
                    arcadeEvent = Arcade::Up;
                if (event.key.code == sf::Keyboard::Down)
                    arcadeEvent = Arcade::Down;
                if (event.key.code == sf::Keyboard::Space ||
                    event.key.code == sf::Keyboard::Enter)
                    arcadeEvent = Arcade::Action1;
                break;
            default:
                break;
        }
    }
}

void SfmlGraphic::displayMap(const std::vector<char>& map)
{
    window->draw(topBar);
    for (int i = 0; i != map.size(); i++)
    {
        if (map[i] != '0')
        {
            if (map[i] == '1')
                rect.setFillColor(sf::Color(100, 200, 50));
            else if (map[i] == '2')
                rect.setFillColor(sf::Color(200, 50, 50));
            else if (map[i] == '3')
                rect.setFillColor(sf::Color(100, 250, 50));
            rect.setPosition(
                sf::Vector2f(900 / mapSize.x * (i % mapSize.x) + 350,
                             windowSize.y / mapSize.y * (i / mapSize.y) + 30));
            window->draw(rect);
        }
    }
}

void SfmlGraphic::displayTexts(const std::vector<Arcade::TextData>& texts)
{
    for (int i = 0; i != texts.size(); i++)
    {
        textTmp.setFillColor(sf::Color(255, 255, 255));
        textTmp.setPosition(sf::Vector2f(texts[i].pos.x, texts[i].pos.y));
        textTmp.setString(texts[i].text);
        textTmp.setCharacterSize(texts[i].fontSize);
        window->draw(textTmp);
    }
}

void SfmlGraphic::display(const std::vector<char>& map,
                          const std::vector<Arcade::TextData>& texts)
{
    if (timer.getElapsedTime() >= 0.016)
    {
        window->clear();
        this->displayMap(map);
        this->displayTexts(texts);
        window->display();
        timer.restart();
    }
}

void SfmlGraphic::drawMenuLabel(Arcade::Switch toggle)
{
    textTmp.setFillColor(sf::Color(255, 255, 255));
    textTmp.setPosition(sf::Vector2f(50, 500));
    textTmp.setString("Username");
    window->draw(textTmp);
    window->draw(inputBoxSprite);
    window->draw(playerText);
    if (toggle == Arcade::GAMES)
        textTmp.setFillColor(sf::Color(83, 113, 255));
    else
        textTmp.setFillColor(sf::Color(255, 255, 255));
    textTmp.setPosition(sf::Vector2f(50, 700));
    textTmp.setString("Games");
    window->draw(textTmp);
    textTmp.setPosition(sf::Vector2f(50, 800));
    if (toggle == Arcade::GRAPHICS)
        textTmp.setFillColor(sf::Color(83, 113, 255));
    else
        textTmp.setFillColor(sf::Color(255, 255, 255));
    textTmp.setString("Graphics");
}

const std::string& SfmlGraphic::getUsername() const
{
    return this->username;
}
void SfmlGraphic::initText(sf::Text& text,
                           sf::Color color,
                           const sf::Vector2f& pos,
                           int fontSize)
{
    text.setFont(font);
    text.setCharacterSize(fontSize);
    text.setPosition(pos);
    text.setFillColor(color);
    text.setOutlineThickness(2);
}