class Cell {
    private:
        int row{0}, column{0}, bombsInVicinity{0};
        bool isFlagged{false}, isMine{false}, isShown{false};
    public:
        Cell(int row, int column): row(row), column(column){};
        Cell(): row(0), column(0){};
        bool getIsFlagged(){
          return isFlagged;
        }
        bool getIsMine(){
            return isMine;
        }
        bool getIsShown(){
            return isShown;
        }
        int getNumberOfMines(){
            return bombsInVicinity;
        }
        int getRow(){
            return row;
        }
        int getColumn(){
            return column;
        }
        void setRowAndColunm(int row, int column);
        void setIsFlagged(bool value);
        void setIsMine(bool value);
        void showCell(){
            isShown = true;
        }
        void addToNumber(){
            bombsInVicinity++;
        }

        
};