#pragma once

#include "app/global.hpp"
#include "player_state.hpp"

#include "game/game_state.hpp"
#include "app/assert.hpp"

namespace Tetris {

class Player {
   public:
    Player();
    ~Player();

    std::shared_ptr<PlayerState> getState();

   private:
    std::shared_ptr<PlayerState> m_state;
};

}  // namespace Tetris