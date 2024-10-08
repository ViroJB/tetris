#pragma once

#include "app/global.hpp"
#include "game/game.hpp"
#include "game/game_state.hpp"

namespace Tetris {

extern GameState gameState;

class App {
   public:
    App();
    ~App();
    
    void init();
    void run();

    bool testThis();

   private:
    std::unique_ptr<Game> m_game;
};

}  // namespace Tetris