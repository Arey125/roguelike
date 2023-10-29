#include "Player.h"

#include "entity/entity_factory.h"

Player::Player(sf::RenderWindow* window): 
    entity(EntityFactory::Instance()->createPlayer(window)), window(window)
{

}

void Player::update()
{
    entity->update();

    auto pos = entity->getPosition();
    
    sf::View view(sf::FloatRect(0.f, 0.f, 800.f, 800.f)); // инициализация вида
 
    // перемещение начала координат в левую верхнюю часть экрана
    view.setCenter(sf::Vector2f(pos.x, pos.y));
 
    window->setView(view);
}

const b2Vec2& Player::getPosition()
{
    return entity->getPosition();
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