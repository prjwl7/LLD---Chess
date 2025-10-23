#include "System.h"
#include <iostream>

namespace Chess{
    System::System(std::string whitePlayerName, std::string blackPlayerName) {
        this->whitePlayer = new Player(ColorType::White, whitePlayerName);
        this->blackPlayer = new Player(ColorType::Black, blackPlayerName);
        this->currentPlayer = this->whitePlayer;
        this->gameStatus = GameStatus::ACTIVE;
    }

    System::~System()
    {
        delete whitePlayer;
        delete blackPlayer;
    }

    void System::initialiseChess(){
        std::cout<<"Starting Chess System ..."<<std::endl;
        this->board.initializeBoard();
        this->board.displayBoard();
    }

    void System::resetGame(){
        this->board.~Board();
        new (&this->board) Board();
        this->moveHistory.clear();
        this->currentPlayer = this->whitePlayer;
        this->gameStatus = GameStatus::ACTIVE;
    }

    GameStatus System::getGameStatus(){
        return this->gameStatus;
    }

    Player* System::getCurrentPlayer(){
        return this->currentPlayer;
    }

    void System::switchPlayer(){
        this->currentPlayer = (this->currentPlayer == this->whitePlayer) ? this->blackPlayer : this->whitePlayer;
    }

    std::vector<Move*> System::getMoveHistory(){
        return this->moveHistory;
    }

}