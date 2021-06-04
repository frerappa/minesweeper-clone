#include <iostream>
#include <vector>
#include "core/Board.hpp"
int main() {
    std::vector<int> a;

    // a.resize(25);
    // for (int i =0 ; i < a.size(); i++){
    //   a[i] = i;
    // }

    // for (int i =0 ; i < a.size(); i++){
    //   std::cout << a[i] << "\n";
    // }

    Board b = Board(4, 4, 1);
    b.showBoard();
    b.clickCell(0,0);
    b.showBoard();
}