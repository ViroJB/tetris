#pragma once

#include <vector>
#include "game/tetromino/tetromino_state.hpp"

namespace Tetris {

struct BoardState {
    std::vector<std::vector<std::unique_ptr<Block>>> board;
};

}  // namespace Tetris