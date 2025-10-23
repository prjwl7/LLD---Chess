#pragma once
#include "Board.h"
#include "Player.h"
#include "Types.h"
#include "Move.h"

namespace Chess {
    class System {
        private:
            Board board;
            Player* whitePlayer;
            Player* blackPlayer;
            Player* currentPlayer;
            GameStatus gameStatus;
            std::vector<Move*> moveHistory;
        public:
            System(std::string whitePlayerName, std::string blackPlayerName);
            void initialiseChess();
            void resetGame();
            GameStatus getGameStatus();
            Player* getCurrentPlayer();
            void switchPlayer();
            std::vector<Move*> getMoveHistory();
            ~System();
    };
}