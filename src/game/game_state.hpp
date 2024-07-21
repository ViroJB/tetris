#pragma once

#include "../blocks/block_state.hpp"
#include "../board/board_state.hpp"
#include "../player/player_state.hpp"

namespace Tetris {

class GameState {
   public:
    PlayerState* playerState;
    BoardState* boardState;  // do we save the "attached" blocks in the game field?
    BlockState* blockState;

    static GameState* getInstance() {
        if (!m_instance) {
            fmt::print("GameState creation\n");
            m_instance = new GameState();
        }
        return m_instance;
    }

   private:
    GameState() {
    }
    static GameState* m_instance;
};

}  // namespace Tetris