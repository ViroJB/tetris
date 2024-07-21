#pragma once 

#include <fmt/core.h>   

#include "../game/game_state.hpp"

namespace Tetris {

class Renderer {
   public:
    Renderer();
    ~Renderer();

    void render(const GameState* state);

   private:
};

}  // namespace Tetris