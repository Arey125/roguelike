#ifndef TEST_FOR_BOX_2D_RIGID_BODY_H
#define TEST_FOR_BOX_2D_RIGID_BODY_H

#include "shared/game_object.h"
#include <box2d/b2_body.h>

class RigidBody: public GameObject {
public:
    RigidBody(sf::ConvexShape shape, b2Body* body, sf::RenderTarget* renderTarget);

    ~RigidBody() override = default;

    // GameObject
    void update() override;
    void render(/*sf::RenderTarget &target*/) override;

private:
    sf::ConvexShape shape;
    b2Body *body;

    sf::RenderTarget* renderTarget;
};


#endif //TEST_FOR_BOX_2D_RIGID_BODY_H
