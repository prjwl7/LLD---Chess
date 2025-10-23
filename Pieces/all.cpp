#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include "Pawn.h"
#include "../Cell.h"
#include <cmath>

namespace Chess{
    Rook::Rook(ColorType c) : Piece(c, PieceType::Rook) {
        // The constructor body is empty
    }
    Knight::Knight(ColorType c) : Piece(c, PieceType::Knight) {
        // The constructor body is empty
    }
    Bishop::Bishop(ColorType c) : Piece(c, PieceType::Bishop) {
        // The constructor body is empty
    }
    Queen::Queen(ColorType c) : Piece(c, PieceType::Queen) {
        // The constructor body is empty
    }
    King::King(ColorType c) : Piece(c, PieceType::King) {
        // The constructor body is empty
    }
    Pawn::Pawn(ColorType c) : Piece(c, PieceType::Pawn) {
        // The constructor body is empty
    }

    bool Rook::canMove( Cell& start, Cell& end){
        bool sameRow = (start.getRow() == end.getRow());
        bool sameCol = (start.getCol() == end.getCol());

        return (sameRow || sameCol) && !(sameRow && sameCol);
    }

    bool Knight::canMove(Cell& start, Cell& end) {
        int deltaRow = std::abs(start.getRow() - end.getRow());
        int deltaCol = std::abs(start.getCol() - end.getCol());
        bool isLMove = (deltaRow == 2 && deltaCol == 1) || (deltaRow == 1 && deltaCol == 2);
        return isLMove;
    }

    bool Bishop::canMove(Cell& start, Cell& end) {
        int deltaRow = std::abs(start.getRow() - end.getRow());
        int deltaCol = std::abs(start.getCol() - end.getCol());
        return (deltaRow == deltaCol) && (deltaRow != 0);
    }

    bool Queen::canMove(Cell& start, Cell& end) {
        int deltaRow = std::abs(start.getRow() - end.getRow());
        int deltaCol = std::abs(start.getCol() - end.getCol());
        bool isStraight = (start.getRow() == end.getRow()) || (start.getCol() == end.getCol());
        bool isDiagonal = (deltaRow == deltaCol);
        bool hasMoved = (deltaRow != 0) || (deltaCol != 0);
        return (isStraight || isDiagonal) && hasMoved;
    }

    bool King::canMove(Cell& start, Cell& end) {
        int deltaRow = std::abs(start.getRow() - end.getRow());
        int deltaCol = std::abs(start.getCol() - end.getCol());
        bool isOneSquare = (std::max(deltaRow, deltaCol) == 1);
        return isOneSquare;
    }
    
    bool Pawn::canMove(Cell& start, Cell& end) {
        int startRow = start.getRow();
        int endRow = end.getRow();
        int startCol = start.getCol();
        int endCol = end.getCol();

        int deltaRow = endRow - startRow;
        int deltaCol = endCol - startCol;

        // Determine forward direction based on color
        // (Assuming WHITE is on low rows, BLACK on high rows)
        int forwardDir = (this->color == ColorType::White) ? 1 : -1;

        // 1. Standard 1-Square Forward Move
        if (deltaCol == 0 && deltaRow == forwardDir) {
            // This is a valid move *shape*.
            // The System must check if the 'end' cell is empty.
            return true;
        }

        // 2. First Move 2-Square Advance
        if (deltaCol == 0 && !this->getHasMoved() && deltaRow == (2 * forwardDir)) {
            // This is a valid move *shape*.
            // The System must check if 'end' cell AND the path are empty.
            return true;
        }

        // 3. Diagonal Capture
        if (std::abs(deltaCol) == 1 && deltaRow == forwardDir) {
            // This is a valid move *shape*.
            // The System must check if the 'end' cell is an ENEMY piece.
            // (It will also handle En Passant as a special case).
            return true;
        }
        return false;
    }
}