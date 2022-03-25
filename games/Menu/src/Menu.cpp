
#include "Menu.hpp"

Menu::Menu() : Arcade::AGame(1, 1), dr("./lib/")
{
    toggle = Arcade::GAMES;
}

Menu::~Menu() {}

void Menu::initLibs()
{
    std::string path = "./lib/lib_sfml.so";
    std::vector<std::string> f = dr.getFiles();
    std::size_t pos = path.find("lib_");
    std::cout << "nb files : " << pos << std::endl;
    std::string tmp = path.substr(pos);

    for (int i = 0; i != f.size(); i++)
    {
        std::cout << " :o " << std::endl;
        if (!f[i].compare(4, 8, "sfml", 4))
        {
            std::cout << "here ! " << std::endl;
            libs.push_back((LibraryData){f[i], LIB_GRAPHIC, false});
        }
        else if (!f[i].compare(4, 8, "menu", 4))
        {
            std::cout << "here ! " << std::endl;
            libs.push_back((LibraryData){f[i], LIB_GAME, false});
            if (tmp == f[i])
            {
                libs[libs.size() - 1].selected = true;
            }
        }
    }
    for (int i = 0; i != libs.size(); i++)
    {
        if (libs[i].type == LIB_GAME)
        {
            libs[i].selected = true;
            break;
        }
    }
}

void Menu::init()
{
    texts.push_back(Arcade::TextData{"Arcade", Vec2(640, 100), 54});
    texts.push_back(Arcade::TextData{"Name ", Vec2(250, 280), 24});
    texts.push_back(Arcade::TextData{"Games", Vec2(230, 400), 32});
    texts.push_back(Arcade::TextData{"Graphics", Vec2(200, 600), 32});

    this->initLibs();
    for (int i = 0; i != libs.size(); i++)
    {
        std::cout << "here ! " << std::endl;
        if (libs[i].type == LIB_GRAPHIC)
            texts.push_back(
                Arcade::TextData{libs[i].name, Vec2(200 + i * 100, 600), 32});
    }
}

void Menu::update(Arcade::Event event) {}

std::size_t Menu::getScore() const
{
    return 0;
}

const std::string Menu::getName() const
{
    return "Menu";
}

int Menu::getSelectedGame() const
{
    for (int i = 0; i != libs.size(); i++)
    {
        if (libs[i].selected == true && libs[i].type == LIB_GAME) return (i);
    }
    return -1;
}

int Menu::getSelectedGraphic() const
{
    for (int i = 0; i != libs.size(); i++)
    {
        if (libs[i].selected == true && libs[i].type == LIB_GRAPHIC) return (i);
    }
    return -1;
}

Arcade::Switch Menu::getToggle() const
{
    return toggle;
}

void Menu::nextGame()
{
    int j = -1;

    for (int i = 0; i != libs.size(); i++)
    {
        if (libs[i].type == LIB_GAME && libs[i].selected == true)
        {
            libs[i].selected = false;
            j = i;
        }
    }
    for (int i = 0; i != libs.size() && j != -1; i++)
    {
        if (libs[i].type == LIB_GAME && i > j)
        {
            libs[i].selected = true;
            j = -2;
            break;
        }
    }
    if (j != -2) libs[j].selected = true;
}

void Menu::nextGraphic()
{
    int j = -1;

    for (int i = 0; i != libs.size(); i++)
    {
        if (libs[i].type == LIB_GRAPHIC && libs[i].selected == true)
        {
            libs[i].selected = false;
            j = i;
        }
    }
    for (int i = 0; i != libs.size() && j != -1; i++)
    {
        if (libs[i].type == LIB_GRAPHIC && i > j)
        {
            libs[i].selected = true;
            j = -2;
            break;
        }
    }
    if (j != -2) libs[j].selected = true;
}

void Menu::prevGame()
{
    int j = -1;

    for (int i = 0; i != libs.size(); i++)
    {
        if (libs[i].type == LIB_GAME && libs[i].selected == true)
        {
            libs[i].selected = false;
            j = i;
        }
    }
    for (int i = j; i >= 0 && j != -1; i--)
    {
        if (libs[i].type == LIB_GAME && i < j)
        {
            libs[i].selected = true;
            j = -2;
            break;
        }
    }
    if (j != -2) libs[j].selected = true;
}

void Menu::prevGraphic()
{
    int j = -1;

    for (int i = 0; i != libs.size(); i++)
    {
        if (libs[i].type == LIB_GRAPHIC && libs[i].selected == true)
        {
            libs[i].selected = false;
            j = i;
        }
    }
    for (int i = j; i >= 0 && j != -1; i--)
    {
        if (libs[i].type == LIB_GRAPHIC && i < j)
        {
            libs[i].selected = true;
            j = -2;
            break;
        }
    }
    if (j != -2) libs[j].selected = true;
}

void Menu::toggleDown()
{
    if (toggle == Arcade::GAMES)
        toggle = Arcade::GRAPHICS;
    else if (toggle == Arcade::GRAPHICS)
        toggle = Arcade::GAMES;
}

void Menu::toggleUp()
{
    if (toggle == Arcade::GAMES)
        toggle = Arcade::GRAPHICS;
    else if (toggle == Arcade::GRAPHICS)
        toggle = Arcade::GAMES;
}
