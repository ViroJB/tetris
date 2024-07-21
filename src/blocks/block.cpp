#include "block.hpp"

namespace Tetris {

Block::Block() {
    fmt::print("Block Constructor\n");
}

Block::~Block() {
    fmt::print("Block Destructor\n");
}

BlockState* Block::getState() {
    return &m_blockState;
}

}  // namespace Tetris