#pragma once

#include "shared/game_object.h"

enum class MenuState {
    Main,
    Settings,
};

class Menu: public GameObject {
public:
    Menu(sf::Window &window);

    void update() override;
    void processEvent(sf::Event &event);
    void render(sf::RenderTarget &target) override;

    int getFPS();

private:
    void showMenu();
    
    void showMainMenu();
    void showSettings();

    sf::Window &window;
    bool menuIsOpen;

    MenuState state;
    bool v_sync;
    int fps;
};
