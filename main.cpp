#include "System.h"

using namespace Chess;

int main(){
    System chessSystem("Prajwal", "Deepika");
    std::cout << "Chess game started: Prajwal (White) vs Deepika (Black).\n";
    chessSystem.initialiseChess();
    // while(chessSystem.getGameStatus() == GameStatus::ACTIVE){
    //     Player* currentPlayer = chessSystem.getCurrentPlayer();
    //     std::cout << "It's " << (currentPlayer->getMove()->getStart().getRow()) << "'s turn.\n";
        
    //     chessSystem.switchPlayer();
    // }
    return 0;
}