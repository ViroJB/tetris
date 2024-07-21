#include "game.hpp"

namespace Tetris {
    
// TODO figure out where to put this
GameState* GameState::m_instance = nullptr;

Game::Game() {
    // init game state
    m_gameState = GameState::getInstance();
    m_gameState->boardState = m_board.getState();
    m_gameState->playerState = m_player.getState();
    m_gameState->blockState = m_activeBlock.getState();

    assert(true, "Board state not equal");
    fmt::print("Game Constructor\n");
}   

Game::~Game() {
    fmt::print("Game Destructor\n");
}

void Game::run() {
    fmt::print("Game Running\n");
}

}  // namespace Tetris