#include <iostream>
#include "phone_display.h"

void PhoneDisplay::update(float temperature) {
    std::cout << "Phone Display - Temperature updated: " << temperature << "C\n";
}
