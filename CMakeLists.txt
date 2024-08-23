cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(tetris)

set(CMAKE_BUILD_TYPE Debug) 

include_directories(${CMAKE_SOURCE_DIR}/src)

find_package(Microsoft.GSL CONFIG REQUIRED)
find_package(GTest CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)

add_executable(tetris 
    src/app/app.cpp
    src/app/main.cpp
    src/app/timer/timer.cpp
    src/config/config.cpp
    src/game/game.cpp
    src/game/player/player.cpp
    src/game/board/board.cpp
    src/opengl/opengl_manager.cpp
    src/opengl/renderer/renderer.cpp
    src/opengl/renderer/shaders/shader_manager.cpp
    src/opengl/input/input.cpp
    src/game/tetromino/tetromino.cpp
)
target_link_libraries(tetris PRIVATE fmt::fmt)
target_link_libraries(tetris PRIVATE Microsoft.GSL::GSL)
target_link_libraries(tetris PRIVATE OpenGL::GL GLEW::GLEW glfw glm::glm)

target_compile_options(tetris PRIVATE "/W4" "/wd4100" "/RTC1") # disable warning C4100 (unused parameter)


enable_testing()

# so we have to create a seperate executable for each test file to make em show at least a bit seperate in vscode testexplorer
add_executable(tests
    tests/main.cpp
    tests/app_test.cpp
    src/app/app.cpp
    src/config/config.cpp
    src/game/game.cpp
    src/game/player/player.cpp
    src/game/board/board.cpp
    src/opengl/renderer/renderer.cpp
)


target_link_libraries(tests PRIVATE GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)
target_link_libraries(tests
    PRIVATE fmt::fmt
    OpenGL::GL GLEW::GLEW glfw glm)
add_test(AllTests tests)