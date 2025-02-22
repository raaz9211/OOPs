#include "concrete_house_builder.h"

int main(){
    House luxuryHouse = ConcreteHouseBuilder().buildRoof().buildWalls().buildPool().getHouse();
    luxuryHouse.showDetails();

    House basicHouse = ConcreteHouseBuilder().buildRoof().buildWalls().getHouse();
    basicHouse.showDetails();

}