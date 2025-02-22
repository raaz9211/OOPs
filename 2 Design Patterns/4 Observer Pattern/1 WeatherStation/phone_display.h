#ifndef PHONE_DISPLAY_H
#define PHONE_DISPLAY_H

#include "observer.h"

class PhoneDisplay : public Observer {
public:
    void update(float temperature);
};

#endif //PHONE_DISPLAY_H