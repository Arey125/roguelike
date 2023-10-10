#pragma once

class Controller {
public:
    virtual ~Controller() {}

    virtual void update() = 0;
};
