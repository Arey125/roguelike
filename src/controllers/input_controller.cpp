#include "input_controller.h"
#include <SFML/Window.hpp>

#include <vector>
#include <algorithm>


InputController::InputController(b2Body *body): body(body)
{
  condMove = UpStand;
}

InputController::~InputController() {}

int InputController::getCondMove()
{
  return condMove;
}

void InputController::update() {
    std::vector<std::pair<sf::Keyboard::Key, b2Vec2>> forces = {
        {sf::Keyboard::W, b2Vec2(0.0f, -vF)},
        {sf::Keyboard::A, b2Vec2(-vF, 0.0f)},
        {sf::Keyboard::S, b2Vec2(0.0f, vF)},
        {sf::Keyboard::D, b2Vec2(vF, 0.0f)},
    };

    float Sx = 0.0;
    float Sy = 0.0;
    for (auto [key, force] : forces)
      if (sf::Keyboard::isKeyPressed(key)) {
        body->ApplyForceToCenter(force, true);
        Sx += force.x;
        Sy += force.y; 
      }
    
    if (abs(Sx) == 0 & abs(Sy) == 0)
    {
      if (isStand) return;
      else{
        isStand = true;

        switch (condMove)
        {
        case UpMove:
          condMove = UpStand;
          break;
        case DownMove:
          condMove = DownStand;
          break;
        case LeftMove:
          condMove = LeftStand;
          break;
        case RightMove:
          condMove = RightStand;
          break;
        case LeftUpMove:
          condMove = LeftUpStand;
          break;
        case LeftDownMove:
          condMove = LeftDownStand;
          break;
        case RightUpMove:
          condMove = RightUpStand;
          break;
        case RightDownMove:
          condMove = RightDownStand;
          break;
      
        default:
          condMove = UpStand;
          break;
        }
      }
    }
    else
    {
      isStand = false;

      if (Sx > 0 & Sy > 0) {condMove = RightDownMove; return;}
      if (Sx < 0 & Sy < 0) {condMove = LeftUpMove; return;}
      if (Sx > 0 & Sy < 0) {condMove = RightUpMove; return;}
      if (Sx < 0 & Sy > 0) {condMove = LeftDownMove; return;}

      if (Sx > 0) {condMove = RightMove; return;}
      if (Sx < 0) {condMove = LeftMove; return;}
      if (Sy > 0) {condMove = DownMove; return;}
      if (Sy < 0) {condMove = UpMove; return;}
    } 
}
