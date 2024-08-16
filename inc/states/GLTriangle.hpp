#pragma once

#include <ethereal/core/State.hpp>

using namespace Ethereal::Core;

class GLTriangle : public State
{
public:
    GLTriangle();
    void update() override;
};
