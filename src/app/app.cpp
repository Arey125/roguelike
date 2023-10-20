#include <box2d/box2d.h>

#include <imgui.h>
#include <imgui-SFML.h>

#include "app.h"
#include "entity/entity_factory.h"
#include "shared/rigid_body/rigid_body.h"
#include "entity/entity.h"
#include "ui/menu.h"

#include "shared/map.h"

#include <iostream>

App::App() :window(sf::VideoMode(800, 800), "SFML works!") {
    window.setFramerateLimit(60);
    ImGui::SFML::Init(window);

}

void App::run() {
    b2World world({0, 0});

    EntityFactory entity_factory(world);

    auto player = entity_factory.createPlayer();

    int32 velocityIterations = 6;
    int32 positionIterations = 2;

    sf::Clock deltaClock;
    Menu menu(window);

    Map* map = Map::Instance();
    map->generated(world);

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
        world.Step(1./fps, velocityIterations, positionIterations);
        //std::cout<< world.GetContactCount() << world.GetBodyCount() << std::endl;
        for (auto contact = world.GetContactList(); contact; contact = contact->GetNext()) {
            player.testContact(contact);
        }
        player.update();
        

        window.clear();

        map->render(window);
        player.render(window);

        ImGui::SFML::Render(window);
        window.display();
    }
    ImGui::SFML::Shutdown();
}
