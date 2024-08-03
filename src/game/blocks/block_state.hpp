#pragma once

#include "app/global.hpp"

namespace Tetris {

enum class BlockType { I, O, T, S, Z, J, L };

struct BlockState {
    BlockType type;
    Size size;
    int rotation;
    Position position;
};
}  // namespace Tetris
