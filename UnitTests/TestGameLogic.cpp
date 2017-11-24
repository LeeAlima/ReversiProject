//
// Created by omer on 24/11/17.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../GameLogic.h"
#include "../ConsoleScreen.h"


using testing::Eq;

namespace {
    class TestGameLogic : public testing::Test {

    public:

        GameLogic *gl;

        TestGameLogic() {
            gl = new GameLogic(8, new HumanPlayer('O', new ConsoleScreen()), new HumanPlayer('X', new ConsoleScreen()),
                               new ConsoleScreen());
        }
    };
}


TEST_F(TestGameLogic, changeplayer) {
    ASSERT_EQ(gl->getPlayer1('C')->getType(),'O');

    gl->changePlayer();
    ASSERT_EQ(gl->getCurrentPlayer(),'O');

    gl->changePlayer();
    ASSERT_EQ(gl->getCurrentPlayer(),'O');

}