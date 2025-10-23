#pragma once
#include "Types.h"
#include "Move.h"
#include <iostream>


namespace Chess{
    class Player{
        private:
            ColorType color;
            std::string name;
            Move* currentMove;
        public:
            Player(ColorType color, std::string name);
            Move* getMove();
            void setMove(Move* move);

    };
}