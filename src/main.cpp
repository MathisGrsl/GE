#include <iostream>
#include "global.hpp"
#include "ge.hpp"

std::vector<float> newDonut(float radiusHole = 0.5, float radiusDonut = 1.0)
{
    int precision = 16;
    std::vector<float> vertices;

    for (int i = 0; i < precision; ++i) {
        float theta0 = 2.0f * ge::pi() * i / precision;
        float theta1 = 2.0f * ge::pi() * (i + 1) / precision;

        for (int j = 0; j < precision; ++j) {
            float phi0 = 2.0f * ge::pi() * j / precision;
            float phi1 = 2.0f * ge::pi() * (j + 1) / precision;

            // Points sur le tore
            auto torusPoint = [&](float theta, float phi) -> ge::v3 {
                float x = (radiusHole + radiusDonut * cos(phi)) * cos(theta);
                float y = (radiusHole + radiusDonut * cos(phi)) * sin(theta);
                float z = radiusDonut * sin(phi);
                return ge::v3(x, y, z);
            };

            ge::v3 p00 = torusPoint(theta0, phi0);
            ge::v3 p01 = torusPoint(theta0, phi1);
            ge::v3 p10 = torusPoint(theta1, phi0);
            ge::v3 p11 = torusPoint(theta1, phi1);

            // Normales
            auto torusNormal = [&](float theta, float phi) -> ge::v3 {
                float x = cos(theta) * cos(phi);
                float y = sin(theta) * cos(phi);
                float z = sin(phi);
                return ge::v3(x, y, z).normalized();
            };

            ge::v3 n00 = torusNormal(theta0, phi0);
            ge::v3 n01 = torusNormal(theta0, phi1);
            ge::v3 n10 = torusNormal(theta1, phi0);
            ge::v3 n11 = torusNormal(theta1, phi1);

            // Coordonnées UV
            ge::v2 uv00(i / (float)precision, j / (float)precision);
            ge::v2 uv01(i / (float)precision, (j + 1) / (float)precision);
            ge::v2 uv10((i + 1) / (float)precision, j / (float)precision);
            ge::v2 uv11((i + 1) / (float)precision, (j + 1) / (float)precision);

            auto push = [&](ge::v3 p, ge::v3 n, ge::v2 uv) {
                vertices.insert(vertices.end(), {
                    p.x, p.y, p.z,
                    n.x, n.y, n.z,
                    uv.x, uv.y
                });
            };

            push(p00, n00, uv00);
            push(p10, n10, uv10);
            push(p11, n11, uv11);
            push(p00, n00, uv00);
            push(p11, n11, uv11);
            push(p01, n01, uv01);
        }
    }
    return vertices;
}


int main() {

    if (ge::initWindow(30, 12000) == -1)
        return 1;

    glfwSetCursorPosCallback(ge::window, mouse_callback);
    glfwSetFramebufferSizeCallback(ge::window, framebuffer_size_callback);
    glfwSetKeyCallback(ge::window, key_callback);
    glfwSetMouseButtonCallback(ge::window, button_callback);

    glfwSetCursorPos(ge::window, ge::screenWidth / 2, ge::screenHeight / 2);

    glfwMaximizeWindow(ge::window);

    initialisation();
    //ge::loadMaps();

    double lastTime = glfwGetTime();
    while (!glfwWindowShouldClose(ge::window)) {
        double currentTime = glfwGetTime();
        float deltaTime = currentTime - lastTime;
        lastTime = currentTime;

        if (ge::clockEvent.on(deltaTime))
            frameEvent(ge::max(deltaTime, ge::clockEvent.deltaLimit));
        if (ge::clockRendering.on(deltaTime))
            frameRendering(ge::max(deltaTime, ge::clockRendering.deltaLimit));
        if (ge::clockSecond.on(deltaTime))
            frameSecond(ge::max(deltaTime, ge::clockSecond.deltaLimit));
    }
    ge::saveMaps();
    glfwDestroyWindow(ge::window);
    glfwTerminate();
    return 0;
}
