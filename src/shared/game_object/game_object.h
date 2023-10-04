#ifndef TEST_FOR_BOX_2D_GAME_OBJECT_H
#define TEST_FOR_BOX_2D_GAME_OBJECT_H

#include "SFML/Graphics.hpp"

class GameObject {
public:
    virtual void update() = 0;
    virtual void render(sf::RenderTarget &target) = 0;
    virtual ~GameObject() = default;
};


#endif //TEST_FOR_BOX_2D_GAME_OBJECT_H
