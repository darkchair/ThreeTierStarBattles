#ifndef STRATEGYGAME_H_INCLUDED
#define STRATEGYGAME_H_INCLUDED

#include "StrategyPiece.h"

#define STRATEGY_BOARD_HEIGHT 8
#define STRATEGY_BOARD_WIDTH 8
#define STRATEGY_BOARD_PIXELS_SIZE 75

class StrategyGame {


public:

    StrategyPiece* pieceArray [STRATEGY_BOARD_WIDTH*STRATEGY_BOARD_HEIGHT];

    int pieceSelected;

public:

    StrategyGame();
    ~StrategyGame();

    StrategyPiece** getPieceArray();

};

#endif // STRATEGYGAME_H_INCLUDED
