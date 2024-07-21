#include "player.hpp"

namespace Tetris { 

Player::Player() {
    fmt::print("Player Constructor\n");
    GameState* gameState = GameState::getInstance();
    gameState->playerState->position;

    assert(true, "Player state not equal");
}

Player::~Player() {
    fmt::print("Player Destructor\n");
}

PlayerState* Player::getState() {
    return &m_state;
}

}  // namespace Tetris