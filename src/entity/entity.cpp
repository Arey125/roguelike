#include <box2d/box2d.h>

#include "controllers/input_controller.h"
#include "entity.h"


Entity::Entity(b2World &world, std::function<Controller *(b2Body *)> createController) {
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(400.0f, 300.0f);
    bodyDef.fixedRotation = true;

    body = world.CreateBody(&bodyDef);
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(10.0f, 10.0f);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 0.01f;
    fixtureDef.restitution = 0;

    controller = createController(body);

    shape.setPointCount(dynamicBox.m_count);
    for (int i = 0; i < dynamicBox.m_count;i++) {
        auto [x, y] = dynamicBox.m_vertices[i];
        shape.setPoint(i, {x, y});
    }

    body->CreateFixture(&fixtureDef);

    auto [centroid_x, centroid_y] = dynamicBox.m_centroid;
    shape.setOrigin(centroid_x, centroid_y);
}

Entity::~Entity() {
    delete controller;
}

void Entity::update() {
    controller->update();

    auto k = 0.1;
    auto velocity = body->GetLinearVelocity();
    b2Vec2 force = b2Vec2(-velocity.Length() * velocity.x * k, -velocity.Length() * velocity.y * k);
    body->ApplyForceToCenter(force, true);

    b2Vec2 position = body->GetPosition();
    float angle = body->GetAngle();
    shape.setRotation(angle * 180 / 3.14159f);
    shape.setPosition({position.x, position.y});
    shape.setFillColor(contact ? sf::Color::Red : sf::Color::White);
    contact = false;
}

void Entity::render(sf::RenderTarget &target) {
    target.draw(shape);
}

void Entity::testContact(b2Contact *contact) {
    const bool isFixtureA = contact->GetFixtureA() == body->GetFixtureList();
    const bool isFixtureB = contact->GetFixtureB() == body->GetFixtureList();

    if (isFixtureA || isFixtureB) {
        if (!contact->IsTouching())
            return;
        this->contact = true;
    }
}
