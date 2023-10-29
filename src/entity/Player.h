#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"

class Player
{
public:
    Player(sf::RenderWindow* window);

    void update();
    void render();

    const b2Vec2& getPosition();

    // for test purposes
    void testContact(b2Contact *contact);

    ~Player();

private:
    Entity* entity;

    sf::RenderWindow* window;
};


#endif //PLAYER_H
