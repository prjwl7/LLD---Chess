#pragma once
#include "../Piece.h"

namespace Chess{
    class Queen : public Piece{
        public:
        Queen(ColorType c);
        bool canMove( Cell& start,  Cell& end) override;
    };
}