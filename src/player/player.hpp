#pragma once

#include "../app/global.hpp"
#include "../player/player_state.hpp"

#include "../game/game_state.hpp"
#include "../app/assert.hpp"

namespace Tetris {

class Player {
   public:
    Player();
    ~Player();

    PlayerState* getState();
   private:


    PlayerState m_state;
};

}  // namespace Tetris