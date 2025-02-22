#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "house_builder.h"

class Director {
public:
    void constructLuxuryHouse(HouseBuilder &houseBuilder){
        houseBuilder.buildWalls();
        houseBuilder.buildRoof();
        houseBuilder.buildPool();
    }

    void constructBasicHouse(HouseBuilder &houseBuilder){
        houseBuilder.buildWalls();
        houseBuilder.buildRoof();
    }
};

#endif // DIRECTOR_H