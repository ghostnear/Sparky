#include "states/GLTriangle.hpp"

#include <gl\glew.h>
#include <cmath>
#include <numbers>

struct TriangleData
{
    float angle;
};

GLTriangle::GLTriangle()
{
    // Generate random triangles.
    auto test_entity = entities.create_entity();
    entities.add_component(test_entity, TriangleData{
        .angle = 0
    });
}

void GLTriangle::update()
{
    // 'Update' systems first.

    // 'Draw' systems rest.
    entities.visit([](TriangleData& data) {
        data.angle += std::numbers::pi / 144.0;
        glBegin(GL_TRIANGLES);
            glColor3f(1.0f, 0.0f, 0.0f); glVertex2f(0 + sin(data.angle) / 2, -0.25 + cos(data.angle) / 2);
            glColor3f(0.0f, 1.0f, 0.0f); glVertex2f(0.25 + sin(data.angle) / 2, 0.25 + cos(data.angle) / 2);
            glColor3f(0.0f, 0.0f, 1.0f); glVertex2f(-0.25 + sin(data.angle) / 2, 0.25 + cos(data.angle) / 2);
        glEnd();
    });
}
