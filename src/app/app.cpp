#include "app.hpp"

namespace Tetris {

App::App() {
    fmt::print("App Constructor\n");

    m_game = std::make_unique<Game>();
    m_game->mainLoop();
}

bool App::TestThis() {
    return true;
}

}  // namespace Tetris