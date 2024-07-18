#include <gtest/gtest.h>
#include "../src/app/app.h"

TEST(AppTest, TestThis) {
    Tetris::App* app = new Tetris::App;
    EXPECT_TRUE(app->TestThis());
}