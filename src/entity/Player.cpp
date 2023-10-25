#include "Player.h"

#include "entity/entity_factory.h"

Player::Player(sf::RenderWindow* window): 
    entity(EntityFactory::Instance()->createPlayer(window))
{

}

void Player::update()
{
    entity->update();

    auto pos = entity->getPosition();
    //view->setCenter(sf::Vector2f(pos.x, pos.y));

}

void Player::render()
{
    entity->render();
}

void Player::testContact(b2Contact *contact)
{
    entity->testContact(contact);
}

Player::~Player()
{

}