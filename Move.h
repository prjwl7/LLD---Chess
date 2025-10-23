#pragma once
#include "Cell.h"
namespace Chess
{
    class Move{
        private:
            Cell start;
            Cell end;

        public:
            Move(Cell start, Cell end){
                this->start = start;
                this->end = end;
            };
            Cell getStart() const;
            Cell getEnd() const;

    };
};
