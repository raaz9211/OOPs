#ifndef CONCRETE_HOUSE_BUILDER_H
#define CONCRETE_HOUSE_BUILDER_H

#include "house_builder.h"

class ConcreteHouseBuilder : public HouseBuilder {
private:
    House house;

public:
    void buildWalls(){
        house.setWalls(true);
    }

    void buildRoof(){
        house.setRoof(true);
    }
    void buildPool(){
        house.setPool(true);
    }
    House getHouse(){
        return house;
    }
};

#endif // CONCRETE_HOUSE_BUILDER_H
