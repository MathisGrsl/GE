#include <iostream>
#include "ge.hpp"

int frameEvent(double deltaTime)
{
    ge::v3 impact;
    ge::object::instanceData *result = ge::getObject(ge::screenWidth / 2, ge::screenHeight / 2, &impact);

    if (result != nullptr) {
        snprintf(ge::test, sizeof(ge::test), "%f %f %f", impact.x, impact.y, impact.z);
    } else {
        snprintf(ge::test, sizeof(ge::test), "no pick");
    }

    return 0;
}
