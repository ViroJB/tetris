#include "game.hpp"

namespace Tetris {

Game::Game() : m_gameState(GameState::getInstance()) {
    fmt::print("Game Constructor\n");
    init();
}

void Game::init() {
    fmt::print("Game init\n");

    m_openGLManager = std::make_unique<OpenGLManager>();
    m_openGLManager->initialize();
    m_openGLManager->createWindow("Tetris", 800, 800);

    m_renderer = std::make_unique<Renderer>();
    m_renderer->setWindow(m_openGLManager->getWindow());

    m_input = std::make_unique<Input>(m_openGLManager->getWindow());
    m_player = std::make_unique<Player>();
    m_board = std::make_unique<Board>();
    m_activeBlock = std::make_unique<Block>();

    // init game state
    m_gameState.boardState = m_board->getState();
    m_gameState.playerState = m_player->getState();
    createNewTetromino();
}

Game::~Game() {
    fmt::print("Game Destructor\n");
}

void Game::createNewTetromino() {
    // get random tetromino type
    int random = createRandomNumber(0, 6);
    TetrominoType type = static_cast<TetrominoType>(random);

    m_activeTetromino = std::make_unique<Tetromino>(type, Position{5, 16});
    // set random color
    Color rndColor = {createRandomFloat(1.0f), createRandomFloat(1.0f), createRandomFloat(1.0f), 1.0f};
    m_activeTetromino->setColor(rndColor);
    m_gameState.tetrominoState = m_activeTetromino->getState();
}

int Game::createRandomNumber(int min, int max) {
    return min + (rand() % static_cast<int>(max - min + 1));
}

float Game::createRandomFloat(float max) {
    // create random number between 0.0 and max
    return static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / max));
}

bool Game::isDownMoveValid(std::shared_ptr<BoardState> boardState, std::shared_ptr<TetrominoState> tetrominoState) {
    // get the lowest block on each column
    std::vector<int> lowestBlocks(10, 22);  // Assuming there are 10 columns
    for (const auto& block : tetrominoState->blocks) {
        int column = block.position.x;
        int row = block.position.y;
        if (row < lowestBlocks[column]) {
            lowestBlocks[column] = row;
        }
    }

    // print all lowest blocks
    // for (int i = 0; i < 10; i++) {
    //     fmt::print("Lowest block in column {}: {}\n", i, lowestBlocks[i]);
    // }

    // check if each of those can move down, if one can't, return false
    for (int column = 0; column < 10; column++) {
        if (lowestBlocks[column] >= 22) {
            continue;
        }
        int row = lowestBlocks[column];
        if (row <= 0 || boardState->board[row - 1][column]->isActive == true) {
            return false;
        }
    }

    return true;
}

bool Game::isLeftMoveValid(std::shared_ptr<BoardState> boardState, std::shared_ptr<TetrominoState> tetrominoState) {
    // get most left block of the tetromino to check if it can move to the left
    Position mostLeftBlock = tetrominoState->blocks[0].position;
    for (const auto& block : tetrominoState->blocks) {
        if (block.position.x < mostLeftBlock.x) {
            mostLeftBlock = block.position;
        }
    }

    // check if the block can move to the left
    if (mostLeftBlock.x <= 0) {
        return false;
    }

    return true;
}
bool Game::isRightMoveValid(std::shared_ptr<BoardState> boardState, std::shared_ptr<TetrominoState> tetrominoState) {
    // get most right block of the tetromino to check if it can move to the right
    Position mostRightBlock = tetrominoState->blocks[0].position;
    for (const auto& block : tetrominoState->blocks) {
        if (block.position.x > mostRightBlock.x) {
            mostRightBlock = block.position;
        }
    }

    // check if the block can move to the right
    if (mostRightBlock.x >= 9) {
        return false;
    }

    return true;
}

void Game::moveTetrominoToBottom() {
    while (isDownMoveValid(m_gameState.boardState, m_gameState.tetrominoState)) {
        m_activeTetromino->moveDown();
    }
    m_board->attachTetromino(std::move(m_activeTetromino));
    createNewTetromino();
}

void Game::mainLoop() {
    fmt::print("Game running\n");

    float inputTime = 0.0f; // in ms
    float inputCooldown = 0.13f;  // in ms 
    // todo opengl stuff like input should be in the opengl-manager
    while (!glfwWindowShouldClose(m_openGLManager->getWindow())) {
        // show fps
        // fmt::print("FPS: {}\n", 1.0f / Timer::getDeltaTime());

        // todo refactor the input cooldown
        // get input
        if (inputTime <= 0.0f) {
            if (m_input->isKeyPressed(Input::Key::ESC)) {
                fmt::print("ESC pressed\n");
                glfwSetWindowShouldClose(m_openGLManager->getWindow(), true);

                inputTime = inputCooldown;
            }
            if (m_input->isKeyPressed(Input::Key::LEFT)) {
                if (isLeftMoveValid(m_gameState.boardState, m_gameState.tetrominoState)) {
                    fmt::print("Move left\n");
                    m_activeTetromino->moveLeft();
                    inputTime = inputCooldown;
                }
            }
            if (m_input->isKeyPressed(Input::Key::RIGHT)) {
                if (isRightMoveValid(m_gameState.boardState, m_gameState.tetrominoState)) {
                    fmt::print("Move right\n");
                    m_activeTetromino->moveRight();
                    inputTime = inputCooldown;
                }
            }
            if (m_input->isKeyPressed(Input::Key::UP)) {
                fmt::print("Rotate\n");
                m_activeTetromino->rotateClockwise();

                inputTime = inputCooldown;
            }
            if (m_input->isKeyPressed(Input::Key::DOWN)) {
                fmt::print("Move down\n");
                moveTetrominoToBottom();

                inputTime = inputCooldown;
            }
        } else {
            inputTime -= Timer::getDeltaTime();
        }

        // update game state
        // todo remove hardcoded gametime
        if (m_gameTime >= 0.7f) {
            m_gameTime = 0.0f;
            if (isDownMoveValid(m_gameState.boardState, m_gameState.tetrominoState)) {
                m_activeTetromino->moveDown();
            } else {
                // temp attach and create new tetromino
                m_board->attachTetromino(std::move(m_activeTetromino));
                createNewTetromino();
            }
        } else {
            m_gameTime += Timer::getDeltaTime();
        }

        // render
        m_renderer->render(m_gameState);

        Timer::updateDeltaTime();
    }
}

}  // namespace Tetris