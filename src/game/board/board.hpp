#pragma once

#include "board_state.hpp"
#include "app/global.hpp"
#include "game/tetromino/tetromino.hpp"

namespace Tetris {

class Board {
   public:
    Board();
    ~Board();

    void attachTetromino(std::unique_ptr<Tetromino> tetromino);
    void addEmptyRow();
    void removeRow(int row);
    std::vector<int> getFullRows();

    std::shared_ptr<BoardState> getState();

   private:
    std::shared_ptr<BoardState> m_state;
};

}  // namespace Tetris