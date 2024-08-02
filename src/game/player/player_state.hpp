#pragma once

#include "app/global.hpp"

namespace Tetris {

struct Score {
    int value = 0;

    void plusOne() {
        value++;
    }
};

struct PlayerState {
    Position position;
    Score score;
};
}  // namespace Tetris