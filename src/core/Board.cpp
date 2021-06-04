#include "Board.hpp"
#include <iostream>   /* printf, scanf, puts, NULL */
#include <stdlib.h> 
#include <ctime>
#include <queue>

Board::Board(int rows, int columns, int numberOfMines): rows{rows}, columns{columns}, numberOfMines{numberOfMines}, cellsWithoutMinesShown{0}, minesLeftShown{numberOfMines}, board{std::vector<std::vector<Cell>>(rows, std::vector<Cell>(columns))}{
    initializeMines();
    initializeBoard();
}


Board::Board(int rows, int columns): Board(rows, columns, (int) (0.2 * rows * columns)){}

void Board::initializeMines(){
    std::vector<int> mines(numberOfMines);
    Tree t = Tree();
    srand((unsigned) time(0));
    int n = rows * columns;
    for(int i = 0; i < numberOfMines; i++){
        int r;
        do{
            r = (int) n * ((float) rand() / RAND_MAX);
        } while(t.search_insert(r));
        mines[i] = r;   
        board[rowFromIndex(r)][columnFromIndex(r)].setIsMine(true);
    }
}

void Board::setNumbersAroundBomb(Cell bomb){
    int bombRow = bomb.getRow(), bombColumn = bomb.getColumn();
    int vicinity[8][2] = {{1, -1}, {1, 0}, {1, 1}, {0, -1}, {0, 1}, {-1, -1}, {-1, 0}, {-1, 1}};
    for (auto position : vicinity){
        int cellRow = bombRow + position[0], cellColumn = bombColumn + position[1];
        if (withinBoard(cellRow, cellColumn)){
            board[cellRow][cellColumn].addToNumber();
        }
    }
}

void Board::initializeBoard(){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            board[i][j].setRowAndColunm(i, j);
            if (board[i][j].getIsMine()){
                setNumbersAroundBomb(board[i][j]);
            }
        }
    }
}

void Board::expandBlankCell(Cell cell){
    int vicinity[8][2] = {{1, -1}, {1, 0}, {1, 1}, {0, -1}, {0, 1}, {-1, -1}, {-1, 0}, {-1, 1}};
    std::queue<Cell> queue;
    cell.showCell();
    cellsWithoutMinesShown++;
    queue.push(cell);
    while (!queue.empty()){
        Cell u = queue.front();
        queue.pop();
        // TODO aparentemente as chamadas copiam a células, e nao as alteram
        for (auto position : vicinity){
            int cellRow = u.getRow() + position[0], cellColumn = u.getColumn() + position[1];
            if (withinBoard(cellRow, cellColumn) && !board[cellRow][cellColumn].getIsShown()){
                Cell neighbourCell = board[cellRow][cellColumn]; 
                if (neighbourCell.getNumberOfMines() > 0){
                    neighbourCell.showCell();
                    cellsWithoutMinesShown++;
                }
                else{
                    neighbourCell.showCell();
                    cellsWithoutMinesShown++;
                    queue.push(neighbourCell);
                }     
            }
        }
    }

}

bool Board::clickCell(int row, int column){
    Cell cell = board[row][column];
    if (cell.getIsMine()){
        return false;
    }
    if (cell.getIsFlagged()){
        return true;
    }
    if (cell.getNumberOfMines() > 0){
        cell.showCell();
        cellsWithoutMinesShown++;
        return true;
    }
    else{
        expandBlankCell(cell);
        return true;
    }
}

void Board::changeCellFlag(int row, int column){
    Cell cell = board[row][column];
    cell.setIsFlagged(!cell.getIsFlagged());
    minesLeftShown = minesLeftShown + (cell.getIsFlagged() ? 1 : -1);
}

void Board::showBoard(){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            if (board[i][j].getIsShown()){
                if (board[i][j].getIsMine()){
                    std::cout << 'B';
                }
                else {
                    std::cout << board[i][j].getNumberOfMines();
                }
            }   
            else if (board[i][j].getIsFlagged()){
                std::cout << 'F';
            }  
            else{
                std::cout << ' ';
            }
        }
        std::cout << '\n';
    }    
}




