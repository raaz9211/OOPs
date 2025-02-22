#ifndef HOUSE_BUILDER_H
#define HOUSE_BUILDER_H

#include "house.h"

class HouseBuilder {
public:
    virtual HouseBuilder &buildWalls() = 0;
    virtual HouseBuilder &buildRoof() = 0;
    virtual HouseBuilder &buildPool() = 0;
    virtual House getHouse() = 0;
    virtual ~HouseBuilder() = default;
};

#endif // HOUSE_BUILDER_H
