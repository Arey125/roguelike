#include "shared/controller.h"
#include <box2d/b2_body.h>

template<typename ControllerType>
Controller *createController(b2Body *body) {
    return new ControllerType(body);
}
