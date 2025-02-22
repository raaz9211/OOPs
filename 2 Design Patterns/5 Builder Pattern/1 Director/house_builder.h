#ifndef HOUSE_BUILDER_H
#define HOUSE_BUILDER_H

#include "house.h"

class HouseBuilder {
public:
    virtual void buildWalls() = 0;
    virtual void buildRoof() = 0;
    virtual void buildPool() = 0;
    virtual House getHouse() = 0;
    virtual ~HouseBuilder() = default;
};

#endif // HOUSE_BUILDER_H
