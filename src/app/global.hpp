#pragma once

#include <fmt/core.h>

#include "config/config.hpp"

// #include "../app/assert.hpp" // i think this breaks because the gamestate hasnt been initialized yet

namespace Tetris {

struct Position {
    int x;
    int y;

    Position operator+(const Position& other) const {
        return {x + other.x, y + other.y};
    }

    Position operator-(const Position& other) const {
        return {x - other.x, y - other.y};
    }

    bool operator==(const Position& other) const {
        return x == other.x && y == other.y;
    }

    bool operator!=(const Position& other) const {
        return x != other.x || y != other.y;
    }

    bool operator<(const Position& other) const {
        return x < other.x || (x == other.x && y < other.y);
    }

    bool operator>(const Position& other) const {
        return x > other.x || (x == other.x && y > other.y);
    }

    std::pair<int, int> toPair() const {
        return std::make_pair(x, y);
    }
};

struct Size {
    int width;
    int height;
};

struct Color {
    float r = 0.0f;
    float g = 0.0f;
    float b = 0.0f;
    float a = 1.0f;
};

}  // namespace Tetris