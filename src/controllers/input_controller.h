#pragma once

#include "shared/controller.h"
#include <box2d/b2_body.h>

class InputController: public Controller {
public:
    InputController(b2Body *body);
    ~InputController() override;

    void update() override;

private:
    b2Body *body;
};
