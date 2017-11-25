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

    protected:

        GameLogic *gl;

        virtual void SetUp(){
            gl = new GameLogic(8, new HumanPlayer('O', new ConsoleScreen()), new HumanPlayer('X', new ConsoleScreen()),
                               new ConsoleScreen());
        }

        virtual void TearDown(){
            delete(gl);
        }
    };
}

TEST_F(TestGameLogic, findPossibleCells) {

    vector<string> vector_of_cells=gl->findPossibleCells(*(gl->getBoard()),'O');
    ASSERT_EQ(vector_of_cells[0],"(3,5)");
    ASSERT_EQ(vector_of_cells[1],"(5,3)");

}

TEST_F(TestGameLogic, checkPlayerMove) {
    bool condition=gl->checkPlayerMove("(3,5)",'O',*(gl->getBoard()));
    ASSERT_TRUE(condition);

}



TEST_F(TestGameLogic, changeplayer) {
    ASSERT_EQ(gl->getPlayer1('C')->getType(),'O');

    gl->changePlayer();
    ASSERT_EQ(gl->getCurrentPlayer(),'X');

    gl->changePlayer();
    ASSERT_EQ(gl->getCurrentPlayer(),'O');

}