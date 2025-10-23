#pragma once
#include "Types.h"

namespace Chess {
    class Cell;
    class Piece {
    public: 
        Piece(ColorType c, PieceType p) {
            this->color = c;
            this->piece = p;
            this->hasMoved = false;
        }
        virtual bool canMove( Cell& start,  Cell& end) = 0;
        ColorType getColor() { 
            return this->color; 
        }
        
        PieceType getPieceType() { 
            return this->piece; 
        }
        
        bool getHasMoved() { 
            return this->hasMoved; 
        }

        void setHasMoved(bool moved) {
            this->hasMoved = moved;
        }
    protected: 
        ColorType color;
        PieceType piece;
        bool hasMoved;
    };

};