#pragma once

#include "app/global.hpp"
#include "block_state.hpp"

namespace Tetris {

class Block {
   public:
    Block();
    ~Block();

    std::shared_ptr<BlockState> getState();

   private:
    std::shared_ptr<BlockState> m_state;
};

}  // namespace Tetris