//
// Created by omer on 24/11/17.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../GameLogic.h"
#include "../ConsoleScreen.h"


using testing::Eq;

void clearBoard(Board &b);
namespace {
    class TestGameLogic : public testing::Test {

    protected:

        GameLogic *gl;
        Board *b;

        virtual void SetUp(){
            gl = new GameLogic(8, new HumanPlayer('O', new ConsoleScreen()), new HumanPlayer('X', new ConsoleScreen()),
                               new ConsoleScreen());
            b=new Board(8,8, *(gl->getScreen()));
        }

        virtual void TearDown(){
            delete(gl);
            delete(b);
        }

    };
}

TEST_F(TestGameLogic, findPossibleCells) {

    vector<string> vector_of_cells=gl->findPossibleCells(*(gl->getBoard()),'O');
    ASSERT_EQ(vector_of_cells[0],"(3,5)");
    ASSERT_EQ(vector_of_cells[1],"(5,3)");
    ASSERT_EQ(vector_of_cells[2],"(2,4)");
    ASSERT_EQ(vector_of_cells[3],"(4,2)");
    b->setCellInBoard(3,5,'O');
    b->setCellInBoard(3,4,'O');
    vector_of_cells= gl->findPossibleCells(*b,'X');
    ASSERT_EQ(vector_of_cells[0],"(2,3)");
    ASSERT_EQ(vector_of_cells[1],"(2,5)");
    ASSERT_EQ(vector_of_cells[2],"(4,5)");
    clearBoard(*b);

}

TEST_F(TestGameLogic, checkPlayerMove) {
    bool condition=gl->checkPlayerMove("(3,5)",'O',*(gl->getBoard()));
    ASSERT_TRUE(condition);
}

TEST_F(TestGameLogic, checksIfGameOver) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            b->setCellInBoard(i,j,'O');
        }
    }
    bool condition= gl->checksIfGameOver(*b);
    ASSERT_TRUE(condition);
    clearBoard(*b);
}

TEST_F(TestGameLogic, changeplayer) {
    ASSERT_EQ(gl->getPlayer1('C')->getType(),'O');

    gl->changePlayer();
    ASSERT_EQ(gl->getCurrentPlayer(),'X');

    gl->changePlayer();
    ASSERT_EQ(gl->getCurrentPlayer(),'O');

}

TEST_F(TestGameLogic, updateScore_and_getXscore){
    b->setCellInBoard(5,5,'X');
    b->setCellInBoard(6,6,'X');
    b->setCellInBoard(2,2,'X');
    b->setCellInBoard(1,3,'X');
    b->setCellInBoard(1,1,'X');
    gl->updateScore(*b);
    ASSERT_EQ(gl->getXScore(*b),5);
}



void clearBoard(Board &b){
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
           b.setCellInBoard(i,j,'E');
        }
    }
    b.setCellInBoard(3,3,'O');
    b.setCellInBoard(3,4,'X');
    b.setCellInBoard(4,4,'O');
    b.setCellInBoard(4,3,'X');
}

