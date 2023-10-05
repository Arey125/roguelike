#include <box2d/b2_world.h>
#include <box2d/b2_body.h>
#include <box2d/b2_polygon_shape.h>
#include <box2d/b2_fixture.h>
#include <imgui.h>
#include <imgui-SFML.h>

#include "app.h"
#include "shared/index.h"

RigidBody createBox(b2World &world) {
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(300.0f, 100.0f);
    bodyDef.angle = 0.4;
    bodyDef.fixedRotation = false;

    b2Body* body = world.CreateBody(&bodyDef);
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(20.0f, 20.0f);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 10.0f;
    fixtureDef.friction = 0.5;
    fixtureDef.restitution = 0.5;

    sf::ConvexShape shape(dynamicBox.m_count);
    for (int i = 0; i < dynamicBox.m_count;i++) {
        auto [x, y] = dynamicBox.m_vertices[i];
        shape.setPoint(i, {x, y});
    }

    body->CreateFixture(&fixtureDef);

    auto [centroid_x, centroid_y] = dynamicBox.m_centroid;
    shape.setOrigin(centroid_x, centroid_y);

    return {shape, body};
}

RigidBody createGround(b2World &world) {
    b2BodyDef bodyDef;
    bodyDef.type = b2_staticBody;
    bodyDef.position.Set(400.0f, 700.0f);

    b2Body* body = world.CreateBody(&bodyDef);;
    b2PolygonShape staticBox;
    staticBox.SetAsBox(500, 100);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &staticBox;


    sf::ConvexShape shape(staticBox.m_count);
    for (int i = 0; i < staticBox.m_count;i++) {
        auto [x, y] = staticBox.m_vertices[i];
        shape.setPoint(i, {x, y});
    }

    body->CreateFixture(&fixtureDef);

    auto [centroid_x, centroid_y] = staticBox.m_centroid;
    shape.setOrigin(centroid_x, centroid_y);

    return {shape, body};
}

App::App() :window(sf::VideoMode(800, 800), "SFML works!") {
    window.setFramerateLimit(60);
    ImGui::SFML::Init(window);
}

void App::run() {
    b2World world({0, 100});

    auto box = createBox(world);
    auto ground = createGround(world);

    int32 velocityIterations = 6;
    int32 positionIterations = 2;

    sf::Clock deltaClock;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            ImGui::SFML::ProcessEvent(event);
            if (event.type == sf::Event::Closed)
                window.close();
        }
        ImGui::SFML::Update(window, deltaClock.restart());

        world.Step(1./60, velocityIterations, positionIterations);
        box.update();
        ground.update();

        ImGui::Begin("Hello, world!");
        ImGui::Button("Look at this pretty button");
        ImGui::End();


        window.clear();
        box.render(window);
        ground.render(window);
        ImGui::SFML::Render(window);
        window.display();
    }
    ImGui::SFML::Shutdown();
}
