#pragma once
#include "Cell.h" 
#include "Move.h" 
#include "Piece.h"
#include "Types.h"
#include <vector> 

namespace Chess {

    class Board {
    private:
        static const int ROWS = 8;
        static const int COLS = 8;
        std::vector<std::vector<Cell>> grid;
        std::vector<Piece*> whitePieces;
        std::vector<Piece*> blackPieces;

    public:
        Board();
        ~Board();
        void initializeBoard();
        Cell* getCell(int row, int col); 
        void setPiece(int row, int col, Piece* p);
        Piece* getPiece(int row, int col);
        void movePiece(const Move& m);
        char getPieceSymbol(Piece* p);
        void displayBoard();
        // bool isSquareAttacked(int row, int col, ColorType attackingColor);
        // bool isPathClear(const Move& m);
        // Cell* findKing(ColorType kingColor);

    };

}