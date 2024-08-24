#pragma once

// #include <fmt/core.h>
#include "app/assert.hpp"
#include "app/global.hpp"
#include "app/timer/timer.h"
#include "board/board.hpp"
#include "opengl/opengl_manager.hpp"
#include "opengl/input/input.hpp"
#include "opengl/renderer/renderer.hpp"
#include "game_state.hpp"
#include "player/player.hpp"


// test stuff
#include "game/tetromino/tetromino.hpp"

namespace Tetris {

class Game {
   public:
    Game();
    ~Game();

    void init();
    void mainLoop();

    void createNewTetromino();
    int createRandomNumber(int min, int max);
    float createRandomFloat(float max);

    void removeFullRows();

    void moveTetrominoToBottom();
    bool isLeftMoveValid(std::shared_ptr<BoardState> boardState, std::shared_ptr<TetrominoState> tetrominoState);
    bool isRightMoveValid(std::shared_ptr<BoardState> boardState, std::shared_ptr<TetrominoState> tetrominoState);
    bool isDownMoveValid(std::shared_ptr<BoardState> boardState, std::shared_ptr<TetrominoState> tetrominoState);

   private:
    GameState& m_gameState;

    std::unique_ptr<Renderer> m_renderer;
    std::unique_ptr<Player> m_player;
    std::unique_ptr<Board> m_board;
    std::unique_ptr<Block> m_activeBlock;
    std::unique_ptr<Tetromino> m_activeTetromino;
    std::unique_ptr<Input> m_input;
    std::unique_ptr<OpenGLManager> m_openGLManager;

    float m_gameTime = 0.0f;
};

}  // namespace Tetris