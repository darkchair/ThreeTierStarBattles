#include "StrategyGame.h"

StrategyGame::StrategyGame() {

    for(int i=0; i<STRATEGY_BOARD_WIDTH; i++) {
        pieceArray[8*1+i] = new StrategyPiece(PIECE_PAWN);
        pieceArray[8*2+i] = new StrategyPiece(PIECE_EMPTY);
        pieceArray[8*3+i] = new StrategyPiece(PIECE_EMPTY);
        pieceArray[8*4+i] = new StrategyPiece(PIECE_EMPTY);
        pieceArray[8*5+i] = new StrategyPiece(PIECE_EMPTY);
        pieceArray[8*6+i] = new StrategyPiece(PIECE_PAWN);
    }

    pieceArray[0] = new StrategyPiece(PIECE_ROOK);
    pieceArray[1] = new StrategyPiece(PIECE_KNIGHT);
    pieceArray[2] = new StrategyPiece(PIECE_BISHOP);
    pieceArray[3] = new StrategyPiece(PIECE_QUEEN);
    pieceArray[4] = new StrategyPiece(PIECE_KING);
    pieceArray[5] = new StrategyPiece(PIECE_BISHOP);
    pieceArray[6] = new StrategyPiece(PIECE_KNIGHT);
    pieceArray[7] = new StrategyPiece(PIECE_ROOK);

    pieceArray[56] = new StrategyPiece(PIECE_ROOK);
    pieceArray[57] = new StrategyPiece(PIECE_KNIGHT);
    pieceArray[58] = new StrategyPiece(PIECE_BISHOP);
    pieceArray[59] = new StrategyPiece(PIECE_QUEEN);
    pieceArray[60] = new StrategyPiece(PIECE_KING);
    pieceArray[61] = new StrategyPiece(PIECE_BISHOP);
    pieceArray[62] = new StrategyPiece(PIECE_KNIGHT);
    pieceArray[63] = new StrategyPiece(PIECE_ROOK);

}

StrategyGame::~StrategyGame() {



}

StrategyPiece** StrategyGame::getPieceArray() {

    return pieceArray;

}
