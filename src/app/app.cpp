#include <box2d/box2d.h>

#include <imgui.h>
#include <imgui-SFML.h>

#include "app.h"
#include "entity/entity_factory.h"
#include "shared/rigid_body/rigid_body.h"
#include "entity/entity.h"
#include "ui/menu.h"

#include "shared/map.h"

#include "entity/Player.h"

#include <iostream>

App::App() :window(sf::VideoMode(800, 800), "SFML works!") {
    window.setFramerateLimit(60);
    ImGui::SFML::Init(window);

}

void App::run() {
    //b2World world({0, 0});

    //EntityFactory entity_factory(world);

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
    Map* map = Map::Instance();
    b2World* world = EntityFactory::Instance()->getWorld();

    //std::cout << "1111" << std::endl;

    map->generated(*world);

    //std::cout << "2222" << std::endl;

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

        //std::cout << "3333" << std::endl;

        auto fps = menu.getFPS();
        
        world->Step(1./fps, velocityIterations, positionIterations);
        //std::cout<< world.GetContactCount() << world.GetBodyCount() << std::endl;
        for (auto contact = world->GetContactList(); contact; contact = contact->GetNext()) {
            player.testContact(contact);
        }

        //td::cout << "4444" << std::endl;

        player.update();
        
        window.clear();

        map->render(window);
        player.render();

        ImGui::SFML::Render(window);
        window.display();
    }
    ImGui::SFML::Shutdown();
}
