#ifndef STRATEGYPIECE_H_INCLUDED
#define STRATEGYPIECE_H_INCLUDED

enum Piece {

    pawn,
    knight,
    bishop,
    rook,
    queen,
    king

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
