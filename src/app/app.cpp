#include <box2d/box2d.h>

#include <imgui.h>
#include <imgui-SFML.h>

#include "app.h"
#include "entity/entity_factory.h"
#include "shared/rigid_body/rigid_body.h"
#include "entity/entity.h"
#include "ui/menu.h"

#include "map/map.h"

#include "entity/Player.h"

#include <iostream>

App::App() :window(sf::VideoMode(800, 800), "SFML works!") {
    window.setFramerateLimit(60);
    ImGui::SFML::Init(window);

}

void App::run() {
    // инициализация вида
    sf::View* view = new sf::View(sf::FloatRect(0.f, 0.f, 800.f, 800.f));
    //

    //Entity entityPlayer = EntityFactory::Instance()->createPlayer(&window);
    Player player(&window);

    int32 velocityIterations = 6;
    int32 positionIterations = 2;

    sf::Clock deltaClock;
    Menu menu(window);

    //
    Map* map = new Map();
    b2World* world = EntityFactory::Instance()->getWorld();

    map->generated(*world, player.getPosition());

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            ImGui::SFML::ProcessEvent(event);

            auto type = event.type;
            if (type == sf::Event::Closed)
                window.close();

            menu.processEvent(event);
        }

        ImGui::SFML::Update(window, deltaClock.restart());
        menu.update();

        auto fps = menu.getFPS();
        
        world->Step(1./fps, velocityIterations, positionIterations);
        //std::cout<< world.GetContactCount() << world.GetBodyCount() << std::endl;
        for (auto contact = world->GetContactList(); contact; contact = contact->GetNext()) {
            player.testContact(contact);
        }

        player.update();
        
        window.clear();

        map->generated(*world, player.getPosition());

        map->render(window, player.getPosition());
        player.render();

        ImGui::SFML::Render(window);
        window.display();
    }
    ImGui::SFML::Shutdown();
}
