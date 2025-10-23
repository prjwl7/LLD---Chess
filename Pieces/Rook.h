#pragma once
#include "../Piece.h"

namespace Chess{
    class Cell;
    class Rook : public Piece{
        public:
        Rook(ColorType c);
        bool canMove( Cell& start,  Cell& end) override;
    };
}