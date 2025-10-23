#pragma once
#include "../Piece.h"

namespace Chess{
    class King : public Piece{
        public:
        King(ColorType c);
        bool canMove( Cell& start,  Cell& end) override;
    };
}