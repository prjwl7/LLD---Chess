#include "Move.h"

namespace Chess{
    Cell Move::getStart() const{
        return this->start;
    };
    Cell Move::getEnd() const{
        return this->end;
    };
};