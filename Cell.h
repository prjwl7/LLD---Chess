#pragma once
#include "Piece.h"

namespace Chess
{
    class Cell{
        private:
            int row;
            int col;
            Piece* piece;
            

        public:
            Cell (int row, int col){
                this->row = row;
                this->col = col;
                this->piece = nullptr;
            }
            Cell() {
                this->row = -1; 
                this->col = -1; 
                this->piece = nullptr;
            }
            Piece* getPiece();
            void setPiece(Piece* piece);
            int getRow(){return this->row;}
            int getCol(){return this->col;}

    };
};
