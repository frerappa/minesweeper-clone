#include "Cell.hpp"
#include "Tree.hpp"
#include <vector>

class Board {
    private:
        int rows = 0, columns = 0, numberOfMines = 0, cellsWithoutMinesShown = 0, minesLeftShown = 0;
        std::vector<std::vector<Cell>> board;
        void initializeBoard();
        void initializeMines();
        void setNumbersAroundBomb(Cell bomb);
        void expandBlankCell(Cell cell);
        int rowFromIndex(int index) {
            return (int) (index / columns);
        }
        int columnFromIndex(int index) {
            return index % columns;
        }
        bool withinBoard(int cellRow, int cellColumn){
            return cellRow >= 0 && cellRow < rows && cellColumn >= 0 && cellColumn < columns;
        }
    public:
        Board(int rows, int columns, int numberOfMines);
        Board(int rows, int columns);
        void showBoard();
        bool clickCell(int row, int column);
        void changeCellFlag(int row, int column);
};
