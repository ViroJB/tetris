#pragma once

#include "board_state.hpp"
#include "app/global.hpp"

namespace Tetris {

class Board {
   public:
    Board();
    ~Board();

    std::shared_ptr<BoardState> getState();

   private:
    std::shared_ptr<BoardState> m_state;
};

}  // namespace Tetris