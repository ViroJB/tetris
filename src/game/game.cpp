#include "game.hpp"

namespace Tetris {

Game::Game() : m_gameState(GameState::getInstance()) {
    m_openGLManager = std::make_unique<OpenGLManager>();
    m_openGLManager->initialize();
    m_openGLManager->createWindow("Tetris", 800, 600);

    m_renderer = std::make_unique<Renderer>();
    m_renderer->setWindow(m_openGLManager->getWindow());

    m_input = std::make_unique<Input>(m_openGLManager->getWindow());
    m_player = std::make_unique<Player>();
    m_board = std::make_unique<Board>();
    m_activeBlock = std::make_unique<Block>();

    // init game state
    m_gameState.boardState = m_board->getState();
    m_gameState.playerState = m_player->getState();
    m_gameState.blockState = m_activeBlock->getState();

    // assert(true, "Board state not equal");
    fmt::print("Game Constructor\n");
}

Game::~Game() {
    fmt::print("Game Destructor\n");
}

void Game::mainLoop() {
    fmt::print("Game Running\n");

    // todo opengl stuff like input should be in the opengl-manager
    while (!glfwWindowShouldClose(m_openGLManager->getWindow())) {
        // get input
        if (m_input->isKeyPressed(Input::Key::ESC)) {
            fmt::print("ESC pressed\n");
            glfwSetWindowShouldClose(m_openGLManager->getWindow(), true);
        }

        // update game state
        // render
        m_renderer->render(m_gameState);
    }
}

}  // namespace Tetris