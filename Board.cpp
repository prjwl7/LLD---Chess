#include "Board.h"
#include "Pieces/Rook.h"
#include "Pieces/Pawn.h"
#include "Pieces/Knight.h"
#include "Pieces/Bishop.h"
#include "Pieces/Queen.h"
#include "Pieces/King.h"
#include <iostream>

namespace Chess {
    Board::Board() {
        // This resizes the vector to 8x8
        grid.resize(ROWS, std::vector<Cell>(COLS));
        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                grid[r][c] = Cell(r, c);
            }
        }
    };

    // --- Destructor Definition ---
    Board::~Board() {
        for (Piece* p : whitePieces) {
            delete p;
        }
        for (Piece* p : blackPieces) {
            delete p;
        }
        whitePieces.clear();
        blackPieces.clear();
    };


    // --- initializeBoard Definition ---
    void Board::initializeBoard() {
        // Place Rooks
        setPiece(0, 0, new Rook(ColorType::Black));
        setPiece(0, 7, new Rook(ColorType::Black));
        setPiece(7, 0, new Rook(ColorType::White));
        setPiece(7, 7, new Rook(ColorType::White));

        // Place Knights
        setPiece(0, 1, new Knight(ColorType::Black));
        setPiece(0, 6, new Knight(ColorType::Black));
        setPiece(7, 1, new Knight(ColorType::White));
        setPiece(7, 6, new Knight(ColorType::White));

        // Place Bishops
        setPiece(0, 2, new Bishop(ColorType::Black));
        setPiece(0, 5, new Bishop(ColorType::Black));
        setPiece(7, 2, new Bishop(ColorType::White));
        setPiece(7, 5, new Bishop(ColorType::White));

        // Place Queens
        setPiece(0, 3, new Queen(ColorType::Black));
        setPiece(7, 3, new Queen(ColorType::White));

        // Place Kings
        setPiece(0, 4, new King(ColorType::Black));
        setPiece(7, 4, new King(ColorType::White));

        // Place Pawns
        for (int c = 0; c < COLS; ++c) {
            setPiece(1, c, new Pawn(ColorType::Black));
            setPiece(6, c, new Pawn(ColorType::White));
        }
    }

    void Board::setPiece(int row, int col, Piece* p) {
        grid[row][col].setPiece(p);
    }
    
    Piece* Board::getPiece(int row, int col) {
        return grid[row][col].getPiece();
    }
    
    Cell* Board::getCell(int row, int col) {
        return &grid[row][col];
    }

    void Board::movePiece(const Move& m) {
        Cell start = m.getStart();
        Cell end = m.getEnd();
        Piece* movingPiece = getPiece(start.getRow(), start.getCol());
        setPiece(end.getRow(), end.getCol(), movingPiece);
        setPiece(start.getRow(), start.getCol(), nullptr);
        if (movingPiece) {
            movingPiece->setHasMoved(true);
        }
    }
    char Board::getPieceSymbol(Piece* p) {
    if (!p) return ' ';

    char symbol;
    
    switch (p->getPieceType()) {
        case PieceType::Rook:   symbol = 'R'; break;
        case PieceType::Knight: symbol = 'N'; break;
        case PieceType::Bishop: symbol = 'B'; break;
        case PieceType::Queen:  symbol = 'Q'; break;
        case PieceType::King:   symbol = 'K'; break;
        case PieceType::Pawn:   symbol = 'P'; break;
        default: return '?'; 
    }
    if (p->getColor() == ColorType::Black) {
        symbol = tolower(symbol); 
    }

    return symbol;
    }

    void Board::displayBoard() {
    // Print column letters
    std::cout << "  A B C D E F G H" << std::endl; 

    for (int r = 0; r < ROWS; ++r) {
        // Print row number
        std::cout << 8 - r << " "; 
        
        for (int c = 0; c < COLS; ++c) {
            Piece* piece = getPiece(r, c);
            if (piece) {
                char symbol = getPieceSymbol(piece); 
                std::cout << symbol << " ";
            } else {
                std::cout << ". ";
            }
        }
        std::cout << 8 - r << std::endl;
    }
    std::cout << "  A B C D E F G H" << std::endl;

    }
}