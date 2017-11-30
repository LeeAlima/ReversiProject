
#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../GameLogic.h"
#include "../ConsoleScreen.h"
#include "../GameFlow.h"
#include "../AIPlayer.h"


using testing::Eq;

void clearBoard(Board &b);
namespace {
    class TestFixture : public testing::Test {

    protected:

        GameLogic *gl;
        Board *b;
        GameFlow *gf;
        AIPlayer *ai;

        virtual void SetUp(){
            gl = new GameLogic(4, new HumanPlayer('X', new ConsoleScreen()),
                               new HumanPlayer('O', new ConsoleScreen()),
                               new ConsoleScreen());
            b=new Board(4,4, *(gl->getScreen()));
            gf=new GameFlow(4);
            ai= new AIPlayer('O',gl->getScreen());
        }

        virtual void TearDown(){
            delete(gl);
            delete(b);
        }

    };
}

/*
 * test to find possible cells.
 * create a vector for the possible cells
 * from game logic and compare it to known moves.
 */
TEST_F(TestFixture, findPolssibleCells) {
    vector<string> vector_of_cells=gl->
            findPossibleCells(*(gl->getBoard()),'O');
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

/*
 * test for to player move.
 * create a condition that get if player move is possible.
 */
TEST_F(TestFixture, checkPlayerMove) {
    bool condition=gl->checkPlayerMove("(1,3)",'O',*(gl->getBoard()));
    ASSERT_TRUE(condition);
}

/*
 * test if game over by create a board
 * with some positions.
 * we checked if the game is over when the board is full,
 * we also checked if game is over if there are no possible moves.
 */
TEST_F(TestFixture, checksIfGameOver) {
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

/*
 * test to change player.
 * switch between players and compare.
 */
TEST_F(TestFixture, changeplayer) {
    ASSERT_EQ(gl->getPlayer('C')->getType(),'X');

    gl->changePlayer();
    ASSERT_EQ(gl->getCurrentPlayer(),'O');

    gl->changePlayer();
    ASSERT_EQ(gl->getCurrentPlayer(),'X');

}

/*
 * test to check getScoresDifference.
 * I checked if the number of score matches.
 */
TEST_F(TestFixture, updateScore_and_getXscore){
    b->setCellInBoard(3,3,'X');
    b->setCellInBoard(0,0,'X');
    b->setCellInBoard(2,3,'X');
    b->setCellInBoard(1,3,'X');
    b->setCellInBoard(1,0,'X');
    gl->updateScore(*b);
    ASSERT_EQ(gl->getScoresDifference(*b),5);
}

/*
 * test to check the return type
 * I filled the board with values and check if
 * the player with the more points won.
 */
TEST_F(TestFixture,returnWhoWon){
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
    ASSERT_EQ(gl->getPlayer1Score(),1);
    ASSERT_EQ(gl->getPlayer2Score(),8);
    char temp = gl->returnsWhoWon();
    ASSERT_EQ(temp,'O');
}

/*
 * test to check the difference between the point number
 * between 'X' and 'O'
 */
TEST_F(TestFixture,getScoresDifference){
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
    clearBoard(*b);
    b->setCellInBoard(0,1,'X');
    b->setCellInBoard(1,2,'X');
    b->setCellInBoard(2,1,'X');
    b->setCellInBoard(2,2,'X');
    b->setCellInBoard(2,3,'X');
    b->setCellInBoard(3,2,'X');
    b->setCellInBoard(0,0,'O');
    b->setCellInBoard(1,0,'O');
    b->setCellInBoard(2,0,'O');
    b->setCellInBoard(1,1,'O');
    b->setCellInBoard(1,3,'O');
    gl->getBoard()->setCellInBoard(0,0,'X');
    ASSERT_EQ(gl->getScoresDifference(*b),1);
}

/*
 *test to check if fixPointToCom works.
 */
TEST_F(TestFixture,fixPointToCom){
    string s=gf->fixPointToCom("3,4");
    ASSERT_EQ(s,"(2,3)");
}

/*
 * test to check if the AIPlayer returns the right cell.
 */
TEST_F(TestFixture,chooseCellAi){
    gl->getBoard()->setCellInBoard(0,1,'X');
    gl->getBoard()->setCellInBoard(1,1,'X');
    string s= ai->chooseCell(*gl);
    ASSERT_EQ(s,"(0,0)");
    clearBoard(*b);
    gl->getBoard()->setCellInBoard(0,1,'X');
    gl->getBoard()->setCellInBoard(1,1,'X');
    gl->getBoard()->setCellInBoard(2,1,'X');
    gl->getBoard()->setCellInBoard(1,2,'X');
    gl->getBoard()->setCellInBoard(2,2,'X');
    gl->getBoard()->setCellInBoard(3,2,'X');
    gl->getBoard()->setCellInBoard(0,0,'O');
    gl->getBoard()->setCellInBoard(1,0,'O');
    gl->getBoard()->setCellInBoard(2,0,'O');
    s= ai->chooseCell(*gl);
    ASSERT_EQ(s,"(0,2)");
}

/*
 * test to check if the program changes a point from
 * computer pattern into user pattern
 */
TEST_F(TestFixture,fixPointToUser){
    vector<int> vector;
    vector.push_back(4);
    vector.push_back(3);
    string s = gf->fixPointToUser(vector);
    ASSERT_EQ(s,"(5,4)");
}

/*
 * test to check if 2 number changes by reference
 */
TEST_F(TestFixture,changeNumber){
    b->setCellInBoard(0,1,'O');
    b->setCellInBoard(0,2,'O');
    b->setCellInBoard(0,3,'O');
    b->setCellInBoard(1,1,'O');
    b->setCellInBoard(1,3,'X');
    b->setCellInBoard(2,2,'X');
    b->setCellInBoard(2,3,'X');
    b->setCellInBoard(3,1,'X');
    int Number1 = 0;
    int Number2 = 0;
    gl->calculateScores(Number1,Number2,*b);
    ASSERT_EQ(Number1,6);
    ASSERT_EQ(Number2,4);

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