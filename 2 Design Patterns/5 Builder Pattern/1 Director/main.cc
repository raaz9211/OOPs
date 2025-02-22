#include "concrete_house_builder.h"
#include "director.h"
int main(){
    ConcreteHouseBuilder builder;
    Director director;

    director.constructLuxuryHouse(builder);
    House luxuryHouse = builder.getHouse();
    luxuryHouse.showDetails();

    builder = ConcreteHouseBuilder();

    director.constructBasicHouse(builder);
    House basicHouse  = builder.getHouse();
    basicHouse.showDetails();

}