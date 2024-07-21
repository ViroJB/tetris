#pragma once

#include <fmt/core.h>
#include "../config/config.hpp"
// #include "../app/assert.hpp" // i think this breaks because the gamestate hasnt been initialized yet

namespace Tetris {

struct Position {
    int x;
    int y;
};

struct Size {
    int width;
    int height;
};

struct Color {
    int r;
    int g;
    int b;
    int a;
};

struct Rect {
    Position position;
    Size size;
    Color color;
};

}  // namespace Tetris