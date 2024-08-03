#include "player.hpp"

namespace Tetris { 

Player::Player() {
    fmt::print("Player Constructor\n");

    m_state = std::make_shared<PlayerState>();

    // GameState* gameState = GameState::getInstance();
    // gameState->playerState->position;

    // Assert(true, "assert test");
}

Player::~Player() {
    fmt::print("Player Destructor\n");
}

std::shared_ptr<PlayerState> Player::getState() {
    return m_state;
}

}  // namespace Tetris