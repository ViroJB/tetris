cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(tetris)

set(CMAKE_BUILD_TYPE Debug) 

find_package(GTest CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)

add_executable(tetris 
    src/app/app.cpp
    src/app/main.cpp
    src/config/config.cpp
    src/blocks/block.cpp
    src/board/board.cpp
    src/game/game.cpp
    src/player/player.cpp
    src/renderer/renderer.cpp
)
target_link_libraries(tetris PRIVATE fmt::fmt)

enable_testing()

# so we have to create a seperate executable for each test file to make em show at least a bit seperate in vscode testexplorer
add_executable(tests
    tests/main.cpp
    tests/app_test.cpp
    src/app/app.cpp
    src/config/config.cpp
    src/blocks/block.cpp
    src/board/board.cpp
    src/game/game.cpp
    src/player/player.cpp
    src/renderer/renderer.cpp
)

target_link_libraries(tests PRIVATE GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main fmt::fmt)
add_test(AllTests tests)