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
            gl = new GameLogic(4, new HumanPlayer('O', new ConsoleScreen()), new HumanPlayer('X', new ConsoleScreen()),
                               new ConsoleScreen());
            b=new Board(4,4, *(gl->getScreen()));
        }

        virtual void TearDown(){
            delete(gl);
            delete(b);
        }

    };
}

TEST_F(TestGameLogic, findPolssibleCells) {

    vector<string> vector_of_cells=gl->findPossibleCells(*(gl->getBoard()),'O');
    ASSERT_EQ(vector_of_cells[0],"(1,3)");
    ASSERT_EQ(vector_of_cells[1],"(3,1)");
    ASSERT_EQ(vector_of_cells[2],"(0,2)");
    ASSERT_EQ(vector_of_cells[3],"(2,0)");
    b->setCellInBoard(1,3,'O');
    b->setCellInBoard(0,2,'O');
    vector_of_cells= gl->findPossibleCells(*b,'X');
    ASSERT_EQ(vector_of_cells[0],"(1,0)");
    ASSERT_EQ(vector_of_cells[1],"(3,2)");
    ASSERT_EQ(vector_of_cells[2],"(0,1)");
    clearBoard(*b);

}

TEST_F(TestGameLogic, checkPlayerMove) {
    bool condition=gl->checkPlayerMove("(1,3)",'O',*(gl->getBoard()));
    ASSERT_TRUE(condition);
}

TEST_F(TestGameLogic, checksIfGameOver) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            b->setCellInBoard(i,j,'O');
        }
    }
    bool condition= gl->checksIfGameOver(*b);
    ASSERT_TRUE(condition);
    clearBoard(*b);
    b->setCellInBoard(0,1,'O');
    b->setCellInBoard(0,2,'O');
    b->setCellInBoard(0,3,'O');
    b->setCellInBoard(1,1,'O');
    b->setCellInBoard(1,2,'O');
    b->setCellInBoard(1,3,'O');
    b->setCellInBoard(2,2,'O');
    b->setCellInBoard(2,3,'O');
    b->setCellInBoard(3,1,'X');
    b->setCellInBoard(2,1,'E');
    condition= gl->checksIfGameOver(*b);
    ASSERT_TRUE(condition);
    clearBoard(*b);

}

TEST_F(TestGameLogic, changeplayer) {
    ASSERT_EQ(gl->getPlayer('C')->getType(),'O');

    gl->changePlayer();
    ASSERT_EQ(gl->getCurrentPlayer(),'X');

    gl->changePlayer();
    ASSERT_EQ(gl->getCurrentPlayer(),'O');

}

TEST_F(TestGameLogic, updateScore_and_getXscore){
    b->setCellInBoard(3,3,'X');
    b->setCellInBoard(0,0,'X');
    b->setCellInBoard(2,3,'X');
    b->setCellInBoard(1,3,'X');
    b->setCellInBoard(1,0,'X');
    gl->updateScore(*b);
    ASSERT_EQ(gl->getScoresDifference(*b),5);
}

TEST_F(TestGameLogic,returnWhoWon){
    b->setCellInBoard(0,1,'O');
    b->setCellInBoard(0,2,'O');
    b->setCellInBoard(0,3,'O');
    b->setCellInBoard(1,1,'O');
    b->setCellInBoard(1,2,'O');
    b->setCellInBoard(1,3,'O');
    b->setCellInBoard(2,2,'O');
    b->setCellInBoard(2,3,'O');
    b->setCellInBoard(3,1,'X');
    b->setCellInBoard(2,1,'E');
    gl->updateScore(*b);
    char temp = gl->returnsWhoWon();
    ASSERT_EQ(temp,'O');
}

TEST_F(TestGameLogic,getScoresDifference){

    b->setCellInBoard(0,1,'O');
    b->setCellInBoard(0,2,'O');
    b->setCellInBoard(0,3,'O');
    b->setCellInBoard(1,1,'O');
    b->setCellInBoard(1,2,'X');
    b->setCellInBoard(1,3,'X');
    b->setCellInBoard(2,2,'X');
    b->setCellInBoard(2,3,'X');
    b->setCellInBoard(3,1,'X');
    b->setCellInBoard(2,1,'E');
    gl->updateScore(*b);
    int temp = gl->getScoresDifference(*b);
    ASSERT_EQ(temp,1);

}

void clearBoard(Board &b){
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
           b.setCellInBoard(i,j,'E');
        }
    }
    b.setCellInBoard(1,1,'O');
    b.setCellInBoard(1,2,'X');
    b.setCellInBoard(2,2,'O');
    b.setCellInBoard(2,1,'X');
}

