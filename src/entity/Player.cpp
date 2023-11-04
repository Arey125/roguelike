#include "Player.h"

#include "entity/entity_factory.h"

#include <string>

#include <iostream>

Player::Player(sf::RenderWindow* window): 
    entity(EntityFactory::Instance()->createPlayer(window)), window(window)
{
    /*
    texture = new sf::Texture;
    texture->loadFromFile("player1.png");
    textures[Controller::] = texture;*/

    std::vector<std::string> spriteNames = 
    {"upStand", "downStand", "leftStand", "rightStand",
    "leftUpStand", "leftDownStand", "rightUpStand", "rightDownStand",
    "upMove", "downMove", "leftMove", "rightMove",
    "leftUpMove", "leftDownMove", "rightUpMove", "rightDownMove"};

    for (int cond = Controller::UpStand; cond != Controller::RightDownMove; cond++ )
    {
        texture = new sf::Texture;
        texture->loadFromFile(spriteNames[cond] + ".png");
        textures[cond] = texture;
    }

    //sprite.setTexture(*texture);
}

void Player::update()
{
    entity->update();

    auto pos = entity->getPosition();

    sprite.setPosition(pos.x - 10, pos.y - 16);
    
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

    //std::cout <<  << std::endl;
    int idTexture = entity->getCondMove();

    sprite.setTexture(*textures[idTexture]);

    window->draw(sprite);
}

void Player::testContact(b2Contact *contact)
{
    entity->testContact(contact);
}

Player::~Player()
{

}