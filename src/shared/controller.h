#pragma once

class Controller {
public:
    virtual ~Controller() {}

    virtual void update() = 0;

    static enum conditionMove{UpStand, DownStand, LeftStand, RightStand,
                              LeftUpStand, LeftDownStand, RightUpStand, RightDownStand,
                              UpMove, DownMove, LeftMove, RightMove,
                              LeftUpMove, LeftDownMove, RightUpMove, RightDownMove};
    virtual int getCondMove() = 0;

protected:
    conditionMove condMove = UpStand;

    bool isStand = true;
};


