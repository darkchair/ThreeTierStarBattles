#ifndef STRATEGYPIECE_H_INCLUDED
#define STRATEGYPIECE_H_INCLUDED

enum Piece {
    PIECE_PAWN,
    PIECE_KNIGHT,
    PIECE_BISHOP,
    PIECE_ROOK,
    PIECE_QUEEN,
    PIECE_KING,
    PIECE_EMPTY
};

class StrategyPiece {

public:

    Piece type;

public:

    StrategyPiece();
    StrategyPiece(Piece t);
    ~StrategyPiece();

};

#endif // STRATEGYPIECE_H_INCLUDED
