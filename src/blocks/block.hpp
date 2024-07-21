#pragma once

#include "../app/global.hpp"
#include "block_state.hpp"

namespace Tetris {

class Block {
   public:
    Block();
    ~Block();

    BlockState* getState();

   private:
    BlockState m_blockState;
};

}  // namespace Tetris