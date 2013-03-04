#include "StrategyGame.h"

StrategyGame::StrategyGame() {

    for(int i=8; i<STRATEGY_BOARD_WIDTH; i++) {

        pieceArray[i] = new StrategyPiece(pawn);
        pieceArray[5*i] = new StrategyPiece(pawn);

    }

}

StrategyGame::~StrategyGame() {



}
