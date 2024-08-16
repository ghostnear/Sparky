#include <ethereal/lib.hpp>

#include "states/GLTriangle.hpp"

using namespace Ethereal::Core;

int main(int argc, char* argv[])
{
    auto window_config = WindowConfig {
        Color(0.1, 0.1, 0.1),
        Vector2<intmax_t>(960, 540),
        "OpenGL Triangle Sample"
    };
    auto window = new Window(window_config);
    window->set_state(new GLTriangle());
    auto app = App()
        .add_window(window);
    return app.run();
}