#include <iostream>
#include "ge.hpp"

void drawCursor()
{
    float size = 7.0f;
    float gap = 2.0f;
    float thickness = 2.0f;
    float x = float(ge::screenWidth / 2.0);
    float y = float(ge::screenHeight / 2.0);

    glColor3f(255 / 255.0f, 192 / 255.0f, 203 / 255.0f);
    glLineWidth(thickness);
    glBegin(GL_LINES);
    // Ligne horizontale gauche
    glVertex2f(x - gap - size, y);
    glVertex2f(x - gap, y);

    // Ligne horizontale droite
    glVertex2f(x + gap, y);
    glVertex2f(x + gap + size, y);

    // Ligne verticale haut
    glVertex2f(x, y - gap - size);
    glVertex2f(x, y - gap);

    // Ligne verticale bas
    glVertex2f(x, y + gap);
    glVertex2f(x, y + gap + size);
    glEnd();
}

int frameRendering(double deltaTime)
{
    ge::fps += 1;
    
    ge::deplacementCamera(deltaTime);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    ge::objects[ge::getIndiceObject("dome")].instances[0].position.x = ge::camPos.x;
    ge::objects[ge::getIndiceObject("dome")].instances[0].position.z = ge::camPos.z;

    ge::drawObjects();

    ge::interfaceMode();
    ge::renderText(ge::test, 10, 50, 2, ge::v3(255 / 255.0f, 192 / 255.0f, 203 / 255.0f));
    ge::renderText(ge::fpsText, 10, 10, 2, ge::v3(255 / 255.0f, 192 / 255.0f, 203 / 255.0f));

    drawCursor();

    glfwSwapBuffers(ge::window);
    ge::updateInput();
    glfwPollEvents();

    return 0;
}
