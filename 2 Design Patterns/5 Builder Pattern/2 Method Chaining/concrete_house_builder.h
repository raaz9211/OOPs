#ifndef CONCRETE_HOUSE_BUILDER_H
#define CONCRETE_HOUSE_BUILDER_H

#include "house_builder.h"

class ConcreteHouseBuilder : public HouseBuilder {
private:
    House house;

public:
    HouseBuilder &buildWalls(){
        house.setWalls(true);
        return *this;
    }

    HouseBuilder &buildRoof(){
        house.setRoof(true);
        return *this;

    }
    HouseBuilder &buildPool(){
        house.setPool(true);
        return *this;
    }
    House getHouse(){
        return house;
    }
};

#endif // CONCRETE_HOUSE_BUILDER_H
