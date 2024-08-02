#include "board.hpp"

namespace Tetris {

Board::Board() {
    fmt::print("Board Constructor\n");
    m_state = std::make_shared<BoardState>();
}

Board::~Board() {
    fmt::print("Board Destructor\n");
}

std::shared_ptr<BoardState> Board::getState() {
    return m_state;
}

}  // namespace Tetris