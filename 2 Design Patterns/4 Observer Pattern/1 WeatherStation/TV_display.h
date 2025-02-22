#ifndef TV_DISPLAY_H
#define TV_DISPLAY_H

#include "observer.h"

class TVDisplay : public Observer {
public:
    void update(float temperature);
};

#endif //TV_DISPLAY_H