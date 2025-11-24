#include "ge.hpp"

void initialisation()
{
    ge::newObject("dome", ge::v3(0, -200, 0), ge::v3(0, 1, 0), 0, ge::v3(1000, 1000, 1000), 1, ge::getIndiceTexture("sky"));

    ge::newObject("quad", ge::v3(0, 0, 0),
                    ge::v3(0, 1, 0), ge::deg2rad(0),
                    ge::v3(10, 10, 10), 0, ge::getIndiceTexture("grass"));

    for (int y = 0; y < 10; y += 1) {
        for (int x = 0; x < 10; x += 1) {
            if (y * 10 + x < int(ge::textures.size()))
                ge::newObject("quad", ge::v3(5, 2 + y, x - 5),
                    ge::v3(0, 0, -1), ge::deg2rad(90),
                    ge::v3(1, 1, 1), 0, y * 10 + x);
        }
    }

    ge::newObject("sphere", ge::v3(-5, 5, -5), ge::v3(0, 1, 0), 0, ge::v3(1, 1, 1), 1, ge::getIndiceTexture("gold"));
}
