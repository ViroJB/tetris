#include "app.hpp"

namespace Tetris {

App::App() {
    fmt::print("App Constructor\n");
    init();
}

void App::init() {
    fmt::print("App init\n");

    try {
        m_game = std::make_unique<Game>();
    } catch (const std::exception& e) {
        fmt::print("Exception creating game object: {}\n", e.what());
    }
}

void App::run() {
    fmt::print("App running\n");

    if (m_game) {
        m_game->mainLoop();
    }
}

bool App::testThis() {
    return true;
}

}  // namespace Tetris