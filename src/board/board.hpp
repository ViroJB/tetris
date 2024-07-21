#pragma once

#include "../app/global.hpp"
#include "../board/board_state.hpp"

namespace Tetris {

class Board {
   public:
    Board();
    ~Board();

    BoardState* getState();

   private:
    BoardState m_state;
};

}  // namespace Tetris