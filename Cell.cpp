#include "Cell.h" 

namespace Chess {

    Piece* Cell::getPiece() {
        return this->piece;
    }

    void Cell::setPiece(Piece* p) {
        this->piece = p;
    }

}