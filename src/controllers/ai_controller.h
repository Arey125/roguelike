#pragma once

#include "shared/controller.h"
#include <box2d/b2_body.h>

class AIController: public Controller {
public:
    AIController(b2Body *body);
    ~AIController() override;

    void update() override;
    int getCondMove() override;

private:
    b2Body *body;
};
