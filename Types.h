#pragma once

namespace Chess{
    enum class ColorType{
        Black,
        White,
        None,
    };

    enum class PieceType{
        Rook,
        Knight,
        Bishop,
        Queen,
        King,
        Pawn,
        None,
    };

    enum class GameStatus {
        ACTIVE,
        WHITE_IN_CHECK,
        BLACK_IN_CHECK,
        WHITE_WINS,
        BLACK_WINS,
        STALEMATE,
        DRAW 
    };
};