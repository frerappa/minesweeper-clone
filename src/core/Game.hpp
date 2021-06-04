#include "Board.hpp"

class Game {
    private:
        int rows{0}, columns{0}, numberOfBombs{0};
        Board board;
    public:
        Game(): rows(0), columns(0), board(rows, columns){};
        void start();        
};