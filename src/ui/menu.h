#pragma once

#include "shared/game_object.h"


class Menu: public GameObject {
public:
    Menu(sf::Window &window);

    void update() override;
    void processEvent(sf::Event &event);
    void render(sf::RenderTarget &target) override;

private:
    void showMenu();

    sf::Window &window;
    bool menuIsOpen;
};
