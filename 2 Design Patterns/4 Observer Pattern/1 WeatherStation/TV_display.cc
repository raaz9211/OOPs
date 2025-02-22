#include <iostream>
#include "TV_display.h"

void TVDisplay::update(float temperature) {
    std::cout << "TV Display - Temperature updated: " << temperature << "C\n";
}
