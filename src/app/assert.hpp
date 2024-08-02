#pragma once

#include <fmt/core.h>

#include "game/game_state.hpp"

namespace Tetris {

inline void Assert(bool condition, const char* message) {
    if (!condition) {
        fmt::print("Assertion failed: {}\n", message);

        auto& gs = GameState::getInstance();

        // player state
        fmt::print("Player State: {}\n", gs.playerState->position.x);

        // board state
        // fmt::print("Board State: {}\n", gs.boardState->board);

        // block state
        fmt::print("Block State: {}\n", gs.blockState->position.x);

        std::exit(1);
    }
}

}  // namespace Tetris
