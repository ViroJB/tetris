#include "block.hpp"

namespace Tetris {

Block::Block() {
    fmt::print("Block Constructor\n");
    m_state = std::make_shared<BlockState>();
}

Block::~Block() {
    fmt::print("Block Destructor\n");
}

std::shared_ptr<BlockState> Block::getState() {
    return m_state;
}

}  // namespace Tetris