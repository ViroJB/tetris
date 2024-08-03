#include <gtest/gtest.h>
#include "../src/app/app.hpp"

TEST(AppTest, testThis) {
    Tetris::App* app = new Tetris::App;
    EXPECT_TRUE(app->testThis());
}