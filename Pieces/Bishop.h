#pragma once
#include "../Piece.h"

namespace Chess{
        class Bishop : public Piece{
            public:
        Bishop(ColorType c);
        bool canMove( Cell& start,  Cell& end) override;
    };
}