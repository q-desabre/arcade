
#include "Snake.hpp"

Snake::Snake(const Vec2& initialPos) : body(4) {
    direction = LEFT;
    body[0] = initialPos;
    body[1] = Vec2(initialPos.x + 1, initialPos.y);
    body[2] = Vec2(initialPos.x + 2, initialPos.y);
    body[3] = Vec2(initialPos.x + 3, initialPos.y);
}

Snake::~Snake() {}

void Snake::move(Arcade::Event event) {
    switch (event) {
        case Arcade::Left:
            if (direction == LEFT)
                direction = BOTTOM;
            else if (direction == BOTTOM)
                direction = RIGHT;
            else if (direction == RIGHT)
                direction = TOP;
            else if (direction == TOP)
                direction = LEFT;
            break;
        case Arcade::Right:
            if (direction == LEFT)
                direction = TOP;
            else if (direction == BOTTOM)
                direction = LEFT;
            else if (direction == RIGHT)
                direction = BOTTOM;
            else if (direction == TOP)
                direction = RIGHT;
            break;
    }
}

void Snake::update(const std::vector<char>& map, Vec2 mapSize) {
    Vec2 tmp;
    std::size_t size;

    size = body.size() - 1;
    tmp = body[size];
    for (int i = size; i != 0; i--) {
        body[i] = body[i - 1];
    }
    if (direction == LEFT)
        body[0].x -= 1;
    if (direction == RIGHT)
        body[0].x += 1;
    if (direction == TOP)
        body[0].y -= 1;
    if (direction == BOTTOM)
        body[0].y += 1;

    if (map[body[0].x + body[0].y * mapSize.y] == '2') {
        body.push_back(tmp);
    }
}

void Snake::eat() {
    grow = true;
}

const std::vector<Vec2>& Snake::getBody() const {
    return body;
}
