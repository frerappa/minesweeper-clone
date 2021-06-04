#include "Cell.hpp"

void Cell::setRowAndColunm(int row, int column){
    this->row = row;
    this->column = column;
}

void Cell::setIsFlagged(bool value){
    isFlagged = value;
}

void Cell::setIsMine(bool value){
    isMine = value;
}

