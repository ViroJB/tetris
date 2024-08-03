#pragma once

// #include <fmt/core.h>
#include "app/assert.hpp"
#include "app/global.hpp"
#include "blocks/block.hpp"
#include "board/board.hpp"
#include "game_state.hpp"
#include "opengl/opengl_manager.hpp"
#include "opengl/input/input.hpp"
#include "opengl/renderer/renderer.hpp"
#include "player/player.hpp"

namespace Tetris {

class Game {
   public:
    Game();
    ~Game();

    void init();
    void mainLoop();

   private:
    GameState& m_gameState;

    std::unique_ptr<Renderer> m_renderer;
    std::unique_ptr<Player> m_player;
    std::unique_ptr<Board> m_board;
    std::unique_ptr<Block> m_activeBlock;
    std::unique_ptr<Input> m_input;
    std::unique_ptr<OpenGLManager> m_openGLManager;
};

}  // namespace Tetris