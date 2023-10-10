#include "input_controller.h"
#include <SFML/Window.hpp>

#include <vector>
#include <algorithm>


InputController::InputController(b2Body *body)
  : body(body) {}

InputController::~InputController() {}


void InputController::update() {
    std::vector<std::pair<sf::Keyboard::Key, b2Vec2>> forces = {
        {sf::Keyboard::W, b2Vec2(0.0f, -1000.0f)},
        {sf::Keyboard::A, b2Vec2(-1000.0f, 0.0f)},
        {sf::Keyboard::S, b2Vec2(0.0f, 1000.0f)},
        {sf::Keyboard::D, b2Vec2(1000.0f, 0.0f)},
    };

    for (auto [key, force] : forces)
      if (sf::Keyboard::isKeyPressed(key)) {
        body->ApplyForceToCenter(force, true);
      }
}
