#pragma once
#include "../Piece.h"

namespace Chess{
    class Pawn : public Piece{
        public:
        Pawn(ColorType c);
        bool canMove( Cell& start,  Cell& end) override;
    };
}