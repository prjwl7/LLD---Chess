#pragma once
#include "../Piece.h"

namespace Chess{
    class Knight : public Piece{
        public:
        Knight(ColorType c);
        bool canMove( Cell& start,  Cell& end) override;
    };
}