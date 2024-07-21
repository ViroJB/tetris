#include "board.hpp"

namespace Tetris {

Board::Board() {
    fmt::print("Board Constructor\n");
}

Board::~Board() {
    fmt::print("Board Destructor\n");
}

BoardState* Board::getState() {
    return &m_state;
}

}  // namespace Tetris