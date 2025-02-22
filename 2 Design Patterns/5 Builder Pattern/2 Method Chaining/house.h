#ifndef HOUSE_H
#define HOUSE_H

#include <iostream>

class House {
private:
    bool hasWalls = false;
    bool hasRoof = false;
    bool hasPool = false;

public:
    void setWalls(bool hasWalls) { this->hasWalls = hasWalls;}
    void setRoof(bool hasRoof) { this->hasRoof = hasRoof;}
    void setPool(bool hasPool) { this->hasPool = hasPool;}

    void showDetails() const {
        std::cout << "House Details:\n"
            << "Walls: " << (hasWalls ? "Yes" : "No") << "\n"
            << "Roof: " << (hasRoof ? "Yes" : "No") << "\n"
            << "Pool: " << (hasPool ? "Yes" : "No") << "\n";
    }

};

#endif // HOUSE_H