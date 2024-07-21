#include "app.hpp"

namespace Tetris {

App::App() {
    fmt::print("App Constructor\n");

    game.run();
}

bool App::TestThis() {
    return true;
}

}  // namespace Tetris