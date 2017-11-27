/*
 *  Lee alima 313467441
 *  Omer havakok 203345087
 */

#include "Cell.h"
using namespace std;

Cell::Cell(char initializeType) :type(initializeType){
}

char Cell::getType() const {
    return  this->type;
}

void Cell::setType(char typeToChange)  {
    this->type = typeToChange;
}