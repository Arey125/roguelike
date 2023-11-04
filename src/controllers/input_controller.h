#pragma once

#include "shared/controller.h"
#include <box2d/b2_body.h>

class InputController: public Controller {
public:
    InputController(b2Body *body);
    ~InputController() override;

    void update() override;

    int getCondMove() override;

private:
    b2Body *body;

    //int lastCondMove;

    float vF = 2000.0f;
};
