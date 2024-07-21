#pragma once

// #include <fmt/core.h>
#include "../app/global.hpp"
#include "game_state.hpp"
#include "../player/player.hpp"
#include "../board/board.hpp"
#include "../blocks/block.hpp"
#include "../app/assert.hpp"

namespace Tetris {

class Game {
   public:
   Game();
    ~Game();

    void run();

   private:
    GameState* m_gameState;
    Player m_player;
    Board m_board;
    Block m_activeBlock;
};

}  // namespace Tetris