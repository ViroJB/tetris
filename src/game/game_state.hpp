#pragma once

#include "blocks/block_state.hpp"
#include "board/board_state.hpp"
#include "player/player_state.hpp"

namespace Tetris {

enum class GameStateType { GAME, MENU, PAUSE, GAME_OVER, EXIT };

class GameState {
   public:
    std::shared_ptr<PlayerState> playerState;
    std::shared_ptr<BoardState> boardState;  // do we save the "attached" blocks in the game field?
    std::shared_ptr<BlockState> blockState;

    GameStateType current = GameStateType::GAME;

    static GameState& getInstance() {
        static GameState instance;
        return instance;
    }

    GameState(const GameState&) = delete;
    GameState& operator=(const GameState&) = delete;

   private:
    GameState() {
        fmt::print("GameState Constructor\n");
    }
};

}  // namespace Tetris
